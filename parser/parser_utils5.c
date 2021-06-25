#include "ft_minishell.h"

int	parser_flags_utils(int *i, int *j, int *k, int *z)
{
	*i = -1;
	*k = 1;
	*j = 0;
	*z = 0;
	return (0);
}

int	parser_flags_utils2(t_command_and_flag *one_command, \
		t_minishell *all_command)
{
	split_flags(one_command, all_command);
	create_null_array_flags(one_command);
	all_command->onecovkey = 0;
	all_command->doublecovkey = 0;
	return (0);
}

int	parser_flags_utils3(t_command_and_flag *one_command, int *j, int *i)
{
	while (one_command->flags[*j] == ' ')
	{
		(*j)++;
		(*i) = (*j);
	}
	return (0);
}

int	parser_flags_utils4(t_command_and_flag *one_command, \
		t_minishell *all_command, int *i)
{
	if (one_command->flags[*i] == '\'' && all_command->doublecovkey == 0)
	{
		if (all_command->onecovkey == 0)
			all_command->onecovkey = 1;
		else
			all_command->onecovkey = 0;
	}
	if (one_command->flags[*i] == '\"' && all_command->onecovkey == 0)
	{
		if (all_command->doublecovkey == 0)
			all_command->doublecovkey = 1;
		else
			all_command->doublecovkey = 0;
	}
	return (0);
}

int	parser_flags(t_minishell *all_command, t_command_and_flag *one_command)
{
	int	i;
	int	j;
	int	k;
	int	z;

	while (one_command)
	{
		parser_flags_utils(&i, &j, &k, &z);
		parser_flags_utils2(one_command, all_command);
		while (one_command->flags[++i])
		{
			parser_flags_utils3(one_command, &j, &i);
			if (one_command->flags[j] == '\0')
				break ;
			parser_flags_utils4(one_command, all_command, &i);
			if ((one_command->flags[i] == ' ' && all_command->onecovkey != 1 \
				&& all_command->doublecovkey != 1 && j != i) || \
				(one_command->flags[i + 1] == '\0'))
				parser_flags_utils5(one_command, &i, &j, &k);
		}
		parser_flags_utils6(one_command, all_command, k);
		one_command = one_command->next;
	}
	return (0);
}
