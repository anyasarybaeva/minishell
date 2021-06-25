#include "ft_minishell.h"

int	replacement_utils_4(char *command, int *i, int j)
{
	int	c;
	int	k;
	int	a;
	int	len_command;
	int	len_env;

	c = *i;
	k = j;
	a = c - j;
	len_command = ft_strlen(command);
	while (k + a < len_command)
	{
		command[k] = command[k + a];
		k++;
	}
	command[k] = '\0';
	return (0);
}

int	replacement_utils_5(char *command,
			char *new_command, int j, char *env_varianles)
{
	int	k;
	int	a;
	int	c;
	int	len_command;
	int	len_env;

	k = 0;
	a = 0;
	c = j;
	len_command = ft_strlen(command);
	len_env = ft_strlen(env_varianles);
	while (k < len_command + len_env + 1)
	{
		if (k < (j - 1))
			new_command[k] = command[k];
		if (k > (j - 1) && k < j + len_env)
			new_command[k - 1] = env_varianles[a++];
		if (k > j + len_env && command[c] != '\0')
			new_command[k - 2] = command[c++];
		k++;
	}
	new_command[k - 2] = '\0';
	return (j + len_env - 2);
}

char	*replacement_2(char *command, int *i, int j, t_minishell *all_command)
{
	int		len_env;
	int		len_command;
	char	*new_command;

	len_command = ft_strlen(command);
	len_env = ft_strlen(all_command->env_varianles);
	replacement_utils_4(command, i, j);
	len_env = ft_strlen(all_command->env_varianles);
	len_command = ft_strlen(command);
	new_command = (char *)malloc(sizeof(char) * (len_command + len_env + 1));
	if (new_command == NULL)
		return (NULL);
	*i = replacement_utils_5(command, new_command,
			j, all_command->env_varianles);
	if (all_command->name_varianled[0] == '?' && \
			ft_strlen(all_command->name_varianled) == 1)
		free(all_command->env_varianles);
	return (new_command);
}

char	*create_cislo_in_string(int lvl)
{
	char	*chislo;
	int		lvl_2;
	int		i;

	i = 0;
	lvl_2 = lvl;
	while (lvl_2 > 0)
	{
		i++;
		lvl_2 = lvl_2 / 10;
	}
	lvl_2 = lvl;
	chislo = (char *)malloc(sizeof(char) * i + 1);
	if (chislo == NULL)
		return (NULL);
	chislo[i] = '\0';
	while (lvl_2)
	{
		chislo[i] = (lvl_2 % 10) + '0';
		lvl_2 = lvl_2 / 10;
		i--;
	}
	return (chislo);
}

int	create_env_lvl(t_env *env, int lvl)
{
	int		i;
	int		i1;
	char	*new_lvl;
	char	*tmp;

	i = 0;
	i1 = 0;
	new_lvl = ft_itoa(lvl);
	while (env->env[i])
	{
		if (ft_strnstr(env->env[i], "SHLVL", ft_strlen("SHLVL")))
		{
			while (env->env[i][i1] != '=')
				i1++;
			i1++;
			env->env[i][i1] = '\0';
			tmp = env->env[i];
			env->env[i] = ft_strjoin(env->env[i], new_lvl);
			free(tmp);
		}
		break ;
		i++;
	}
	free(new_lvl);
	return (0);
}
