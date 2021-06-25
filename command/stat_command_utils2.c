#include "ft_minishell.h"

int	check_stat_file_utils(t_command_and_flag *command,
		int *i_stat, struct stat stat_command)
{
	if (*(i_stat) == 0)
	{
		if (S_ISREG(stat_command.st_mode))
		{
			if (command->pape == LESS)
			{
				if ((stat_command.st_mode & S_IRUSR) != S_IRUSR)
					return (-3);
			}
			else
			{
				if ((stat_command.st_mode & S_IWUSR) != S_IWUSR)
					return (-3);
			}
		}
		else
			*(i_stat) = -2;
	}
	else
		*(i_stat) = create_file(command->command);
	return (0);
}

int	check_stat_file(t_command_and_flag *command)
{
	int			i_stat;
	struct stat	stat_command;
	int			len;
	char		buf[32000];
	char		*tmp;

	i_stat = -1;
	if (find_slash_dot(command->command) == 1)
		i_stat = check_stat_file_with_path(command);
	else
	{
		getcwd(buf, 32000);
		len = ft_strlen(buf);
		buf[len] = '/';
		len++;
		buf[len] = '\0';
		tmp = command->command;
		command->command = ft_strjoin(buf, command->command);
		free(tmp);
		i_stat = stat(command->command, &stat_command);
		check_stat_file_utils(command, &i_stat, stat_command);
	}
	return (i_stat);
}
