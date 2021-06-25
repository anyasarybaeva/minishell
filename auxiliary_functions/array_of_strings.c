#include "ft_minishell.h"

void	free_array_of_strings(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		array[i++] = 0;
	while (i >= 0)
		free(array[i--]);
	free(array);
}

char	**new_array_add(char **array, char *str)
{
	int		i;
	char	**new_array;

	i = 0;
	if (!array)
	{
		new_array = (char **)malloc(sizeof(char *) * 2);
		new_array[1] = NULL;
		new_array[0] = ft_strdup(str);
		return (new_array);
	}
	while (array && array[i])
		i++;
	i += 1;
	new_array = (char **)malloc(sizeof(char *) *(i + 1));
	if (!new_array)
		return (0);
	new_array[i--] = NULL;
	new_array[i] = ft_strdup(str);
	while (--i >= 0)
		new_array[i] = array[i];
	free_array_of_strings(array);
	return (new_array);
}

char	**new_array_rm(char	**array, int	index)
{
	int		i;
	int		i_new;
	int		i_old;
	char	**new_array;

	i_new = 0;
	i_old = 0;
	i = 0;
	while (array[i])
		i++;
	new_array = (char **)malloc(sizeof(char *) * (i--));
	if (!new_array)
		return (0);
	i_old = i;
	free(array[index]);
	new_array[i] = 0;
	while (--i >= 0)
	{
		if (i_old == index)
			i_old--;
		new_array[i] = array[i_old--];
	}
	free_array_of_strings(array);
	return (new_array);
}

char	**ft_strdup_array_of_strings(char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (0);
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = env[i];
	return (new_env);
}
