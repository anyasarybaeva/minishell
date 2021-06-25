#include "ft_minishell.h"

t_env	*env_keys_values(t_env	*env1, int	lvl, int i)
{
	int		i1;
	char	*tmp;

	while (env1->env[++i])
	{
		i1 = 0;
		while (env1->env[i][i1] != '=')
			i1++;
		env1->env[i][i1] = '\0';
		env1->keys[i] = ft_strdup(env1->env[i]);
		env1->env[i][i1] = '=';
		if (!ft_strncmp(env1->keys[i], "SHLVL", 6))
		{
			env1->env[i][i1 + 1] = '\0';
			env1->values[i] = ft_itoa(lvl + 1);
			tmp = env1->env[i];
			env1->env[i] = ft_strjoin(tmp, env1->values[i]);
			free(tmp);
		}
		else
			env1->values[i] = ft_strdup(&env1->env[i][++i1]);
	}
	env1->values[i] = NULL;
	env1->keys[i] = NULL;
	return (env1);
}

t_env	*allocate_env(char	**env, int	lvl)
{
	t_env	*env1;
	int		i;
	char	*tmp;

	i = 0;
	env1 = malloc(sizeof(t_env));
	if (env1 == NULL)
		return (NULL);
	env1->env = ft_strdup_array_of_strings(env);
	env1->env_lvl = 0;
	while (env[i])
		i++;
	env1->keys = (char **)malloc(sizeof(char *) * (i + 1));
	if (env1->keys == NULL)
		return (NULL);
	env1->values = (char **)malloc(sizeof(char *) * (i + 1));
	if (env1->values == NULL)
		return (NULL);
	i = -1;
	env1 = env_keys_values(env1, lvl, i);
	env1->exit_num = 0;
	return (env1);
}
