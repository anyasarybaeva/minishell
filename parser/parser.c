#include "ft_minishell.h"

int	shift_comand(char *command, t_minishell *all_command)
{
	int		i;
	int		fd;
	char	a[5];

	fd = open(all_command->file_history, O_RDWR);
	if (fd == -1)
		return (-1);
	i = 1;
	while (i != 0)
		i = read(fd, a, 1);
	if (all_command->flag == 1)
	{
		write(fd, "\n", 1);
		write(fd, command, ft_strlen(command));
		all_command->flag = 0;
	}
	else
	{
		write(fd, "\n", 1);
		write(fd, command, ft_strlen(command));
	}
	close(fd);
	return (0);
}

int	create_null_array_flags(t_command_and_flag *command)
{
	command->array_flags[0] = command->command;
	return (0);
}

int	create_list_command(char *command, t_minishell *all_command, int pipe)
{
	t_command_and_flag	*new_command;

	new_command = ft_lstnew(command, pipe);
	ft_lstadd_back(&all_command->head, new_command);
	return (0);
}

int	parser_commands_utils(char *command, int *i)
{
	if (command[*i] == '\\')
	{
		(*i)++;
		if (command[*i] == '\'' || command[*i] == '\"' || \
			command[*i] == '\\' || command[*i] == '$')
			(*i)++;
	}
	return (0);
}

int	parser_commands(char *command, t_minishell *all_command)
{
	int		i;
	char	*new_command;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	all_command->pipe = NEW_COMMAND;
	shift_comand(command, all_command);
	command = create_command_with_env_variables(command, all_command);
	all_command->onecovkey = 0;
	all_command->doublecovkey = 0;
	while (command[i])
	{
		parser_commands_utils(command, &i);
		parser_commands_direct_line(command, &i, &j, all_command);
		parser_commands_more(command, &i, &j, all_command);
		parser_commands_less(command, &i, &j, all_command);
		i++;
	}
	new_command = create_command(command, i, j, 1);
	create_list_command(new_command, all_command, all_command->pipe);
	parser_command(all_command);
	return (0);
}
