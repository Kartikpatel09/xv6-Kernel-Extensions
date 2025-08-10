#include "types.h"

#include "stat.h"

#include "user.h"

int main(int argc, char *argv[])

{

    if (argc < 2)

    {

        printf(1, "Usage: %s <program> [arguments...]\n", argv[0]);

        exit();
    }

    int id = fork();
    if (id == 0)
    {

        exec(argv[1], &argv[1]);    //called exec to complete the commonad provided
        //printf("Error has occured");
        exit(); // written so that child can exit even if it was unable to execute properly.
    }
    wait(); //waiting for parent is waitng for child;

    exit();
}
