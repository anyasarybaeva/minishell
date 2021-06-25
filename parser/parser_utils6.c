#include "ft_minishell.h"

int	parser_command_utils(t_command_and_flag *one_command, \
		int *i, int *j, int *len)
{
	*i = 0;
	*j = 0;
	*len = ft_strlen(one_command->command_and_flags);
	while (one_command->command_and_flags[*i] == ' ')
		(*i)++;
	*j = *i;
	return (0);
}

int	parser_command_utils2(t_minishell *all_command, \
		t_command_and_flag *one_command, int *i)
{
	if (one_command->command_and_flags[*i] == '\'' && \
		all_command->doublecovkey == 0)
	{
		if (all_command->onecovkey == 0)
			all_command->onecovkey = 1;
		else
			all_command->onecovkey = 0;
	}
	if (one_command->command_and_flags[*i] == '\"' && \
		all_command->onecovkey == 0)
	{
		if (all_command->doublecovkey == 0)
			all_command->doublecovkey = 1;
		else
			all_command->doublecovkey = 0;
	}
	return (0);
}

int	parser_command_utils3(t_command_and_flag *one_command, \
		int *i, int *j, t_minishell *all_command)
{
	int	k;

	one_command->command = (char *)malloc(sizeof(char) * (*i - *j) + 1);
	if (one_command->command == NULL)
		return (-1);
	k = 0;
	while (*j < *i)
	{
		one_command->command[k] = one_command->command_and_flags[*j];
		(*j)++;
		k++;
	}
	one_command->command[*j] = '\0';
	ft_clear_command_from_kov(all_command, one_command);
	return (0);
}

int	parser_command_utils4(t_command_and_flag *one_command, int len, int *i)
{
	int	j;

	j = 0;
	one_command->flags = (char *)malloc(sizeof(char) * (len - *i + 1));
	if (one_command->flags == NULL)
		return (-1);
	while ((*i) < len)
	{
		one_command->flags[j] = one_command->command_and_flags[*i];
		j++;
		(*i)++;
	}
	one_command->flags[j] = '\0';
	return (0);
}

int	parser_command(t_minishell *all_command)
{
	int					i;
	int					j;
	int					len;
	int					k;
	t_command_and_flag	*one_command;

	one_command = all_command->head;
	while (one_command)
	{
		parser_command_utils(one_command, &i, &j, &len);
		while (one_command->command_and_flags[i])
		{
			parser_command_utils2(all_command, one_command, &i);
			if (one_command->command_and_flags[i] == ' ' && \
			all_command->onecovkey != 1 && all_command->doublecovkey != 1)
				break ;
			i++;
		}
		parser_command_utils3(one_command, &i, &j, all_command);
		parser_command_utils4(one_command, len, &i);
		one_command = one_command->next;
	}
	stat_command(all_command);
	parser_flags(all_command, all_command->head);
	return (0);
}
