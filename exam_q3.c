#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1,pid2;
    int pip[2];
    FILE * fd;
    char x1[40];
    char x2[40];

    pipe(pip);

    pid1 = fork();
    pid2 = fork();

    fd = fopen("/home/binita/Desktop/EOS_EXAM_210950130003/dictionary.txt", "rd");

    if(pid1 == 0)
    {
        printf("Child1 Process\n");
        close(pip[1]);

        while (read(pip[0], &x2, sizeof(char*)) == sizeof(char*))
          printf("%s\n", x2);
            printf("found in child1\n");

        close(pip[0]);
    }
    else if(pid2 == 0)
    {
        printf("Child2 Process\n");
        close(pip[1]);

        while (read(pip[0], &x2, sizeof(char*)) == sizeof(char*))
          printf("%s\n", x2);
            printf("found in child2\n");

        close(pip[0]);
    }
    else
    {
        printf("Parent P1\n");
        close(pip[0]);
        printf("enter any word\n");
        scanf("%s",x1);
        write(pip[1], &x1, sizeof(&x1));
        close(pip[1]);
        
        waitpid(pid1, NULL, 0);
        
    }


    return 0;
}