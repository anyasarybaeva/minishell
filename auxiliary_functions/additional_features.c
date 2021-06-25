#include "ft_minishell.h"

int	replacement_utils(t_minishell *all_command, char **env_varianles)
{
	int	len_env;
	int	a;

	if (all_command->env->exit_num == 0)
	{
		len_env = 1;
		*env_varianles = (char *)malloc(sizeof(char) * len_env + 1);
		if (*env_varianles == NULL)
			return (0);
		(*env_varianles)[0] = '0';
		(*env_varianles)[1] = '\0';
	}
	return (0);
}

int	replacement_utils_2(t_minishell *all_command, char **env_varianles)
{
	int	len_env;
	int	a;

	len_env = 0;
	a = all_command->env->exit_num;
	while (a > 0)
	{
		a = a / 10;
		len_env++;
	}
	*env_varianles = (char *)malloc(sizeof(char) * len_env + 1);
	if (env_varianles == NULL)
		return (0);
	(*env_varianles)[len_env] = '\0';
	len_env--;
	while (len_env > -1)
	{
		(*env_varianles)[len_env] = \
				(all_command->env->exit_num % 10) + '0';
		all_command->env->exit_num = \
				all_command->env->exit_num / 10;
		len_env--;
	}
	return (0);
}

int	replacement_utils_3(char **env_varianles)
{
	*env_varianles = (char *)malloc(sizeof(char) * 1);
	if (*env_varianles == NULL)
		return (0);
	(*env_varianles)[0] = '\0';
	return (0);
}

char	*replacement(char *command, int *i, int j, t_minishell *all_command)
{
	char	*new_command;

	if (all_command->env_varianles == NULL)
	{
		if (all_command->name_varianled[0] == '?' && \
				ft_strlen(all_command->name_varianled) == 1)
		{
			if (all_command->env->exit_num == 0)
				replacement_utils(all_command, &all_command->env_varianles);
			else
				replacement_utils_2(all_command, &all_command->env_varianles);
		}
		else
			replacement_utils_3(&all_command->env_varianles);
	}
	new_command = replacement_2(command, i, j, all_command);
	return (new_command);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	a;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	a = *(const unsigned char *)s1 - *(const unsigned char *)s2;
	return (a);
}
