#include "ft_minishell.h"

int	find_path_from_new_env_utils(t_minishell *all_command)
{
	int		i;
	char	*tmp;

	i = 0;
	while (all_command->path[i])
	{
		tmp = all_command->path[i];
		all_command->path[i] = ft_strjoin(all_command->path[i], "/");
		free(tmp);
		i++;
	}
	return (0);
}

int	find_path_from_new_env(t_minishell *all_command)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	path = NULL;
	while (all_command->env->keys[i])
	{
		if (ft_strnstr(all_command->env->keys[i], "PATH", \
				ft_strlen(all_command->env->keys[i])))
		{
			path = ft_strdup(all_command->env->values[i]);
			all_command->path = ft_split(path, ':');
			find_path_from_new_env_utils(all_command);
			break ;
		}
		i++;
	}
	if (path == NULL)
		all_command->path = NULL;
	else
		free(path);
	return (0);
}
