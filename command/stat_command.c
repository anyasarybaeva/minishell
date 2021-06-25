#include "ft_minishell.h"

int	check_stat_command_with_path(t_command_and_flag *command)
{
	int				i_stat;
	struct stat		stat_command;

	i_stat = 0;
	i_stat = stat(command->command, &stat_command);
	{
		if (i_stat == 0)
		{
			if (S_ISREG(stat_command.st_mode))
			{
				if ((stat_command.st_mode & S_IXUSR) == S_IXUSR)
					return (i_stat);
				else
					i_stat = -1;
			}
			else
				i_stat = -1;
		}
	}
	return (i_stat);
}

int	create_file(char *path_and_command)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path_and_command, O_WRONLY | O_CREAT, 0777 | O_TRUNC | O_APPEND);
	if (!fd)
		return (-1);
	else
		close (fd);
	return (0);
}

int	check_stat_build_in(t_command_and_flag *command)
{
	int	stat;

	stat = -1;
	if (!ft_strncmp(command->command, "echo", 4) || \
	!ft_strncmp(command->command, "cd", 2) || \
	!ft_strncmp(command->command, "pwd", 3) || \
	!ft_strncmp(command->command, "minishell", 9) || \
	!ft_strncmp(command->command, "export", 6) || \
	!ft_strncmp(command->command, "unser", 5) || \
	!ft_strncmp(command->command, "env", 3) || \
	!ft_strncmp(command->command, "exit", 4))
	{
		stat = 1;
	}
	return (stat);
}

int	stat_command_utils(t_command_and_flag *command, int *i_stat, \
		t_minishell *all_command)
{
	if (command->pape == DOUBLE_MORE || \
		command->pape == MORE || command->pape == LESS)
		*i_stat = check_stat_file(command);
	else
		*i_stat = check_stat_command(all_command, command);
	command->f_error = *i_stat;
	return (0);
}

int	*stat_command(t_minishell *all_command)
{
	int					i_stat;
	t_command_and_flag	*command;

	command = all_command->head;
	while (command)
	{
		i_stat = -1;
		if (check_stat_build_in(command) == 1)
		{
			command->f_error = 0;
			command = command->next;
			continue ;
		}
		if (command->pape == DOUBLE_LESS)
		{
			i_stat = 0;
			command = command->next;
			continue ;
		}
		stat_command_utils(command, &i_stat, all_command);
		command = command->next;
	}
	return (0);
}
