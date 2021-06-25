#include "ft_minishell.h"

void	ft_pwd(char **env, int fd)
{
	int		i;
	int		i1;
	char	buf[32000];

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
		{
			i1 = 3;
			while (env[i][++i1])
				ft_putchar_fd(env[i][i1], fd);
			ft_putchar_fd('\n', fd);
			exit(0);
		}
	}
	getcwd(buf, 32000);
	ft_putstr_fd(buf, fd);
	exit(0);
}

void	ft_env(t_command_and_flag	*all, char	**env, int	fd)
{
	int	i;

	i = -1;
	if (all->array_flags[1])
		exit(1);
	while (env[++i])
	{	
		ft_putstr_fd(env[i], fd);
		ft_putchar_fd('\n', fd);
	}
	exit(0);
}

void	ft_echo(t_command_and_flag	*all, int	fd)
{
	int	i;

	i = 1;
	if (!all->array_flags[1])
	{	
		ft_putchar_fd('\n', fd);
		exit(0);
	}
	while (!ft_strncmp(all->array_flags[i], "-n", 3))
		i++;
	while (all->array_flags[i])
	{
		ft_putstr_fd(all->array_flags[i++], fd);
		if (all->array_flags[i])
			ft_putchar_fd(32, fd);
	}
	if (ft_strncmp(all->array_flags[1], "-n", 3))
		ft_putchar_fd('\n', fd);
	exit(0);
}

void	ft_cd_change_pwd(char **env, char *buf)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
		{
			tmp = env[i];
			env[i] = ft_strjoin("PWD=", buf);
			free(tmp);
			break ;
		}
	}
}

int	ft_cd(t_command_and_flag *all, char **env)
{
	int		i;
	char	buf[32000];
	char	*tmp;

	getcwd(buf, 32000);
	i = -1;
	if (chdir(all->array_flags[1]) == -1)
		return (10);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "OLDPWD=", 7))
		{
			tmp = env[i];
			env[i] = ft_strjoin("OLDPWD=", buf);
			free(tmp);
			break ;
		}
	}
	getcwd(buf, 32000);
	ft_cd_change_pwd(env, buf);
	return (0);
}
