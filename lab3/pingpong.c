#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "string.h"
#define BUFSIZE 512

void ping_pong(int fd) 
{  char buff[BUFSIZE];
   int byteRead;
   while((byteRead=read(fd,buff,BUFSIZE))>0){
    char* s="ping";
    char temp[15];
    int t=0;
    for(int i=0;i<byteRead;i++){
        if(buff[i]==' '){
            temp[t]='\0';
            if(strcmp(temp,s)==0){
                write(1,"pong\n",sizeof("pong\n"));
            }t=0;
        }
        else{
            temp[t]=buff[i];
            t++;
        }

    }
   }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf(1, "Usage: %s <input_file>\n", argv[0]);
        exit();
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf(1, "Error opening file %s\n", argv[1]);
        exit();
    }

    ping_pong(fd);
    close(fd);

    exit();
}
