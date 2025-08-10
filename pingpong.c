
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define BUFSIZE 512

int string_compare(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0; // Strings are not equal
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void ping_pong(int fd)
{
    char buff[BUFSIZE];
    int byteRead;
    while ((byteRead = read(fd, buff, BUFSIZE)) > 0)
    {
        char *s = "ping";
        char temp[15];
        int t = 0;
        for (int i = 0; i < byteRead; i++)
        {
            if (buff[i] == ' ' || buff[i] == '.')
            {
                temp[t] = '\0';
                if (string_compare(temp, s))//strcmp() was not working so created similar function to compare strings
                {
                    write(1, "pong\n", 5);  // writing in stdout if ping is encountered.
                }
                t = 0;
            }
            else
            {
                temp[t] = buff[i];
                t++;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(1, "Usage: %s <input_file>\n", argv[0]);
        exit();
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf(1, "Error opening file %s\n", argv[1]);
        exit();
    }

    ping_pong(fd);
    close(fd);

    exit();
}
