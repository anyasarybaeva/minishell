
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include"function.h"
/*int main(int argc, char *argv[],char *envp[])
{
    int pipe_1[2];int pipe_2[2];
    char *yes[2];char *head[2];
    char *wc[2];yes[0] = "/usr/bin/yes";
    yes[1] = 0;head[0] = "/usr/bin/head";
    head[1] = 0;wc[0] = "/usr/bin/wc";wc[1] = 0;
    (void)argc;
    (void)argv;
    pipe(pipe_1);
    if (!fork())
    {
        dup2(pipe_1[0],0);
        close(pipe_1[1]);
        close(pipe_1[0]);
        execve(wc[0], wc, envp);
    }
    close(pipe_1[0]);
    pipe(pipe_2);
    if (!fork())
    {
        dup2(pipe_2[0],0);
        close(pipe_2[1]);
        close(pipe_2[0]);
        dup2(pipe_1[1],1);
        close(pipe_1[1]);
        close(pipe_1[0]);
        execve(head[0],head, envp);
}
close(pipe_1[1]);
close(pipe_2[0]);
if (!fork())
{dup2(pipe_2[1],1);
close(pipe_2[1]);
close(pipe_2[0]);
execve(yes[0],yes, envp);
}
close(pipe_2[1]);
wait(0);
wait(0);
wait(0);
}*/
int main(int argc,char **argv,char **env)
{
    int fd;
    int pipe_1[2];
	fd=open("j",O_WRONLY);
    //pipe(pipe_1);
    if(!fork())
    {
    dup2(fd,1);
	//close(pipe_1[1]);
	//close(pipe_1[0]);
    //while(1)
    //{
        write(1,&"k|",2);
    //}
        execve("ls",argv,env);
    }
    //close(pipe_1[1]);
	//	close(pipe_1[0]);
       wait(0);
        close(fd);
}
