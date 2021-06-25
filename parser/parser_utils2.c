#include "ft_minishell.h"

int	ft_clear_flags_from_kov_utils(t_minishell *all_command, \
		t_command_and_flag *command, int i, int j)
{
	int	l;
	int	k;
	int	len;

	if (command->array_flags[i][j] == '\'' && all_command->doublecovkey != 1)
	{
		if (all_command->onecovkey == 0)
			all_command->onecovkey = 1;
		else
			all_command->onecovkey = 0;
		l = j;
		k = 0;
		len = ft_strlen(&command->array_flags[i][j]);
		while (k < len + 1)
		{
			command->array_flags[i][l] = command->array_flags[i][l + 1];
			l++;
			k++;
		}
	}
	return (0);
}

int	ft_clear_flags_from_kov_utils2(t_minishell *all_command, \
		t_command_and_flag *command, int i, int j)
{
	int	l;
	int	k;
	int	len;

	if (command->array_flags[i][j] == '\"' && all_command->onecovkey != 1)
	{
		if (all_command->doublecovkey == 0)
			all_command->doublecovkey = 1;
		else
			all_command->doublecovkey = 0;
		l = j;
		k = 0;
		len = ft_strlen(&command->array_flags[i][j]);
		while (k < len + 1)
		{
			command->array_flags[i][l] = command->array_flags[i][l + 1];
			l++;
			k++;
		}
	}
	return (0);
}

int	ft_clear_flags_from_kov_utils3(t_minishell *all_command, \
		t_command_and_flag *command, int i)
{
	int	j;

	j = 0;
	while (command->array_flags[i][j])
	{
		ft_clear_flags_from_kov_utils(all_command, command, i, j);
		ft_clear_flags_from_kov_utils2(all_command, command, i, j);
		j++;
	}
	return (0);
}

int	ft_clear_flags_from_kov(t_minishell *all_command)
{
	int					i;
	int					j;
	t_command_and_flag	*command;

	command = all_command->head;
	all_command->doublecovkey = 0;
	all_command->onecovkey = 0;
	while (command)
	{
		i = 1;
		if (command->array_flags != NULL)
		{
			while (command->array_flags[i])
			{
				ft_clear_flags_from_kov_utils3(all_command, command, i);
				i++;
			}
		}
		command = command->next;
	}
	return (0);
}
