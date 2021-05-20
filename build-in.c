#include"function.h"
int ft_pwd(t_pars *all)
{
	int i;
	int i1;

	i = -1;
	if(all->array[1])
		return(1);
	while(all->env[i])
	{
		if(!strncmp(all->env[i],"PWD=",4))
		{
			i1=3;
			while(all->env[i][++i1])
				printf("%c",all->env[i][i1]);
			printf("\n");
			return(0);
		}
	}
	char buf[32000];
	getcwd(buf,32000);
	if(!buf)
		return(1);
	fprintf("%s",buf);
	return(0);
}

int ft_env(t_pars *all)
{
	int i;

	i = -1;
	if(all->array[1])
		return(1);
	while (all->env[++i])
		printf("%s\n",all->env[i]);
	return(0);
}
int ft_cd(t_pars *all)
{
	int i;
	char buf[32000];
	
	getcwd(buf,32000);
	if(!buf)
		return(1);
	i = -1;
	if(!all->array[1] || all->array[2])
		return(1);
	if(chdir(all->array[1])==-1)
		return(1);
	while(all->env[++i])
	{
		if(!strncmp(all->env[i],"OLDPWD=",7))
		{
			free(all->env[i]);
			all->env[i]=buf;
			break;
		}
	}
	getcwd(buf,32000);
	while(all->env[++i])
	{
		if(!strncmp(all->env[i],"PWD=",4))
		{
			free(all->env[i]);
			all->env[i]=buf;
			break;
		}
	}
	return(0);
}