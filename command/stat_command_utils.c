#include "ft_minishell.h"

int	check_stat_file_with_path_utils(t_command_and_flag *command,
		struct stat stat_command)
{
	int	i_stat;

	i_stat = 0;
	if (command->pape == LESS)
	{
		if ((stat_command.st_mode & S_IRUSR) == S_IRUSR)
			return (i_stat);
		else
			i_stat = -3;
	}
	else
	{
		if ((stat_command.st_mode & S_IWUSR) == S_IWUSR)
			return (i_stat);
		else
			i_stat = -3;
	}
	return (i_stat);
}

int	check_stat_file_with_path(t_command_and_flag *command)
{
	int			i_stat;
	int			i;
	struct stat	stat_command;

	i = 0;
	i_stat = -1;
	i_stat = stat(command->command, &stat_command);
	if (i_stat == 0)
	{
		if (S_ISREG(stat_command.st_mode))
		{
			i_stat = check_stat_file_with_path_utils(command, stat_command);
		}
		else
		{
			i_stat = -2;
		}
	}
	return (i_stat);
}

int	check_stat_command_utils_2(struct stat stat_command)
{
	int	i_stat;

	i_stat = 0;
	if (S_ISREG(stat_command.st_mode))
	{
		if ((stat_command.st_mode & S_IXUSR) == S_IXUSR)
			i_stat = 0;
		else
			i_stat = -1;
	}
	else
		i_stat = -1;
	return (i_stat);
}

int	check_stat_command_utils(t_minishell *all_command,
		t_command_and_flag *command, char **path_and_command)
{
	struct stat		stat_command;
	int				i;
	int				i_stat;

	i = 0;
	i_stat = -1;
	while (all_command->path[i])
	{
		*path_and_command = ft_strjoin(all_command->path[i],
				command->command);
		i_stat = stat(*path_and_command, &stat_command);
		if (i_stat == 0)
		{
			i_stat = check_stat_command_utils_2(stat_command);
			break ;
		}
		i++;
		free(*path_and_command);
		*path_and_command = NULL;
	}
	return (i_stat);
}

int	check_stat_command(t_minishell *all_command, t_command_and_flag *command)
{
	int				i_stat;
	int				i;
	struct stat		stat_command;
	char			*path_and_command;

	i = 0;
	path_and_command = NULL;
	i_stat = -1;
	if (find_slash_dot(command->command) == 1)
		i_stat = check_stat_command_with_path(command);
	else
	{
		if (all_command->path == NULL)
			return (i_stat);
		i_stat = check_stat_command_utils(all_command,
				command, &path_and_command);
	}
	if (path_and_command != NULL)
	{
		free (command->command);
		command->command = path_and_command;
	}
	return (i_stat);
}
