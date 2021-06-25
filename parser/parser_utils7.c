#include "ft_minishell.h"

int	parser_commands_less(char *command, int *i, int *j, \
		t_minishell *all_command)
{
	char	*new_command;

	if (command[*i] == '<')
	{
		if (command[*i + 1] == '<')
		{
			new_command = create_command(command, *i, *j, 1);
			create_list_command(new_command, all_command, all_command->pipe);
			all_command->pipe = DOUBLE_LESS;
			*i = *i + 2;
			*j = *i;
		}
		else
		{
			new_command = create_command(command, *i, *j, 1);
			create_list_command(new_command, all_command, all_command->pipe);
			all_command->pipe = LESS;
			(*i)++;
			*j = *i;
		}
	}
	return (0);
}

int	parser_commands_more(char *command, int *i, int *j, \
		t_minishell *all_command)
{
	char	*new_command;

	if (command[*i] == '>')
	{
		if (command[*i + 1] == '>')
		{
			new_command = create_command(command, *i, *j, 1);
			create_list_command(new_command, all_command, all_command->pipe);
			all_command->pipe = DOUBLE_MORE;
			*i = *i + 2;
			*j = *i;
		}
		else
		{
			new_command = create_command(command, *i, *j, 1);
			create_list_command(new_command, all_command, all_command->pipe);
			all_command->pipe = MORE;
			(*i)++;
			*j = *i;
		}
	}
	return (0);
}

int	parser_commands_direct_line(char *command, int *i, int *j, \
		t_minishell *all_command)
{
	char	*new_command;

	if (command[*i] == '|')
	{
		new_command = create_command(command, *i, *j, 1);
		create_list_command(new_command, all_command, all_command->pipe);
		all_command->pipe = DIRECT_LINE;
		(*i)++;
		*j = *i;
	}
	return (0);
}
