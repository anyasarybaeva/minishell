#include "ft_minishell.h"

int	create_command_with_env_variables_utils(char *command, \
		t_minishell *all_command, int *i)
{
	if (command[*i] == '\\')
	{
		(*i)++;
		if (command[*i] == '\'' || command[*i] == '\"' \
				|| command[*i] == '\\' || command[*i] == '$')
			(*i)++;
	}
	if (command[*i] == '\'' && all_command->doublecovkey == 0)
	{
		if (all_command->onecovkey == 0)
			all_command->onecovkey = 1;
		else
			all_command->onecovkey = 0;
		(*i)++;
	}
	if (command[*i] == '\"' && all_command->onecovkey == 0)
	{
		if (all_command->doublecovkey == 0)
			all_command->doublecovkey = 1;
		else
			all_command->doublecovkey = 0;
		(*i)++;
	}
	return (0);
}

int	create_command_with_env_variables_utils_2(char *command, \
		int *i, int *j)
{
	(*i)++;
	*j = *i;
	while (command[*i] != ' ' && command[*i] != '\0')
		(*i)++;
	return (0);
}

int	create_command_with_env_variables_utils_3(char **command, \
		t_minishell *all_command, int *i, int *j)
{
	all_command->name_varianled = create_command(*command, *i, *j, 0);
	all_command->env_varianles = my_getenv(all_command->name_varianled, \
			all_command);
	if ((*command)[(*j) - 2] == '"')
		all_command->tmp = replacement(*command, i, --(*j), all_command);
	else
		all_command->tmp = replacement(*command, i, *j, all_command);
	*command = all_command->tmp;
	all_command->doublecovkey = 0;
	free(all_command->name_varianled);
	return (0);
}

char	*create_command_with_env_variables(char *command, \
		t_minishell *all_command)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	all_command->tmp = NULL;
	while (command[i])
	{
		create_command_with_env_variables_utils(command, all_command, &i);
		if (command[i] == '$' && all_command->onecovkey != 1)
		{
			create_command_with_env_variables_utils_2(command, \
					&i, &j);
			if (!ft_strnstr(command, "unset", ft_strlen(command)))
				create_command_with_env_variables_utils_3(&command, all_command, \
					&i, &j);
		}
		if (command[i] == '\0')
			break ;
		i++;
	}
	if (all_command->tmp != NULL)
		free(all_command->tmp);
	return (command);
}
