#include "ft_minishell.h"

int	ft_clear_command_from_kov_utils(t_minishell *all_command,
		t_command_and_flag *command, int i)
{
	int	len;
	int	k;
	int	j;

	len = 0;
	if (command->command[i] == '\'' && all_command->doublecovkey != 1)
	{
		if (all_command->onecovkey == 0)
			all_command->onecovkey = 1;
		else
			all_command->onecovkey = 0;
		j = i;
		k = 0;
		len = ft_strlen(&command->command[i]);
		while (k < len)
		{
			command->command[j] = command->command[j + 1];
			j++;
			k++;
		}
	}
	return (0);
}

int	ft_clear_command_from_kov_utils2(t_minishell *all_command,
		t_command_and_flag *command, int i)
{
	int	len;
	int	k;
	int	j;

	if (command->command[i] == '\"' && all_command->onecovkey != 1)
	{
		if (all_command->doublecovkey == 0)
			all_command->doublecovkey = 1;
		else
			all_command->doublecovkey = 0;
		j = i;
		k = 0;
		len = ft_strlen(&command->command[i]);
		while (k < len)
		{
			command->command[j] = command->command[j + 1];
			j++;
			k++;
		}
	}
	return (0);
}

int	ft_clear_command_from_kov(t_minishell *all_command,
		t_command_and_flag *command)
{
	int	i;
	int	j;
	int	len;
	int	k;

	j = 0;
	i = 0;
	all_command->onecovkey = 0;
	all_command->doublecovkey = 0;
	while (command->command[i])
	{
		ft_clear_command_from_kov_utils(all_command, command, i);
		ft_clear_command_from_kov_utils2(all_command, command, i);
		if (command->command[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
