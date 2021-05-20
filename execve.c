#include"function.h"
int find_slash_dot(char *line)
{
	int i;

	i = -1;
	while(line[++i])
	{
		if(line[i]==47)//47-ascii "\"
			return(1);
		else if(line[i]=='.')
			return(1);
	}
	return(0);
}
void free_array_of_strings(char **array)
{
	int i;

	i = -1;
	while(array[++i])
		free(array[i]);
	free(array);
}
char  *find_path(char *name)
{
	char **PATH;
	int i;
	char *tmp;
	struct stat buff;
	i = -1;
	tmp = getenv("PATH");
	PATH = ft_split(tmp,':');
	while(PATH[++i])
	{
		
		tmp = ft_strjoin(PATH[i],name);
		if(!stat(tmp,&buff))
		{
			free_array_of_strings(PATH);
			return(tmp);
		}
		printf("%s\n",tmp);
		free(tmp);
	}
	free_array_of_strings(PATH);
	return(0);
}
void test(t_pars *all,int *pipe_1,int *pipe_2,int fd)
{
	
	struct stat buff;
	//if(pipe_2!=0)
//		pipe(pipe_2);
	if(pipe_1!=0)
		pipe(pipe_1);
	if(!stat(all->filename,&buff))
	{
		if(!fork())
		{
			if(pipe_1!=0)
			{
				dup2(pipe_1[1],1);
				close(pipe_1[1]);
				close(pipe_1[0]);
			}
			if(pipe_2!=0)
			{
				dup2(pipe_2[0],0);
				close(pipe_2[1]);
				close(pipe_2[0]);
			}
			if(fd)
				dup2(fd,1);
			execve(all->filename,all->array,all->env);
		}
		if(pipe_1!=0)
		{
			close(pipe_1[1]);
			close(pipe_1[0]);
		}
	}
}
void redirect(int fd,int *pipe_1)
{
	if(pipe_1!=0)
	{
		dup2(pipe_1[1],fd);
		close(pipe_1[1]);
		close(pipe_1[0]);
	}
	close(pipe_1[1]);
	close(pipe_1[0]);

}
void check_function(t_pars *all,int *pipe_1,int *pipe_2)
{
	/*if(!strncmp(all->filename,"pwd\0",4))
	{	
		if(ft_pwd(all))
			printf("error\n");
	}
	else if(!strncmp(all->filename,"env\0",4))	
	{
		if(ft_env(all))
			printf("error\n");
	}
	else if(!strncmp(all->filename,"cd\0",3))
	{
		if(ft_cd(all))
			printf("error\n");
	}*/
	//if(find_slash_dot(all->filename))
	//{	
		//if(execve(all->filename,all->array,all->env)==-1)
		//	ft_putchar("error");
	//	test(all,pipe_1,pipe_2);
//	}
	//else
	//{	
		//all->filename=find_path(all->filename);
		//printf("%s",all->filename);
		//test(all,pipe_1,pipe_2);
		//if(find_path(all)==-1)
		//	ft_putchar("error");
	//}
}
int main(int argc,char **argv,char **env)
{
	t_pars all[3];
	char *a[3];
	char *b[3];
	char *c[2];
	int **pipe;
	//array
	a[0]=argv[0];
	a[1]="hello";
	a[2]=NULL;
	b[0]=argv[0];
	b[1]="third";
	b[2]=NULL;
	c[0]=argv[0];
	c[1]=NULL;
	//pipe
	pipe=malloc(sizeof(int*)*5);
	pipe[0]=NULL;
	pipe[1]=malloc(sizeof(int)*2);
	pipe[2]=malloc(sizeof(int)*2);
	pipe[3]=malloc(sizeof(int)*2);
	pipe[4]=NULL;
	//filename
	all[0].filename=ft_strdup("/bin/ls");
	all[1].filename=ft_strdup("/usr/bin/head");
	all[2].filename=ft_strdup("/usr/bin/yes");
	//array
	all[0].array=c;
	all[1].array=c;
	all[2].array=c;
	//env
	all[0].env=env;
	all[1].env=env;
	all[2].env=env;
	int i;
	i = -1;
	//while(++i<3)
	int fd;
	fd=open("j",O_WRONLY);
	//if(!fd)
//		printf("%d",fd);
	//pipe(pipe[1]);
	test(&all[0],0,pipe[1],0);
	//execve(all[0].filename,all[0].array,all->env);
	test(&all[1],pipe[1],pipe[2],0);
	test(&all[2],pipe[2],0,fd);

//	close(pipe[3][0]);
//	close(pipe[3][1]);
	i=2;
	//while (++i<3)
//	{
//		check_function(&all[i],pipe[i],pipe[i+1]);
//	}
	//printf("%s",find_path("/yes"));
	//while(--i>0)
		wait(0);
	/*pipe(pipe_1);
	if(!fork())
	{
		dup2(pipe_1[0],0);
        close(pipe_1[1]);
        close(pipe_1[0]);
        execve("/usr/bin/wc",wc, all[0]->env);
	}
	pipe(pipe_2);

	if(!fork())
	{
		dup2(pipe_2[0],0);
        close(pipe_2[1]);
        close(pipe_2[0]);
		dup2(pipe_1[1],1);
		close(pipe_1[1]);
		close(pipe_1[0]);
        execve("/usr/bin/grep",all[1]->array, all[0]->env);
	}
	
	if (!fork())
	{
		dup2(pipe_2[1],1);
		close(pipe_2[1]);
		close(pipe_2[0]);
		execve("/bin/cat",all[0]->array, all[1]->env);
	}
	close(pipe_1[1]);
    close(pipe_1[0]);
	close(pipe_2[1]);
    close(pipe_2[0]);
	wait(0);
	wait(0);
		wait(0);*/
}