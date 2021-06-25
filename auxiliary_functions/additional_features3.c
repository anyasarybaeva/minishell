#include "ft_minishell.h"

int	find_slash_dot(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 47)
			return (1);
		else if (line[i] == '.')
			return (1);
	}
	return (0);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

char	*my_getenv(char *name_env, t_minishell *all_command)
{
	int	i;

	i = 0;
	if (name_env[0] == '?')
		return (NULL);
	while (all_command->env->keys[i])
	{
		if (!ft_strncmp(all_command->env->keys[i], name_env, ft_strlen(name_env)) && \
		ft_strlen(all_command->env->keys[i]) == ft_strlen(name_env))
			break ;
		i++;
	}
	return (all_command->env->values[i]);
}
