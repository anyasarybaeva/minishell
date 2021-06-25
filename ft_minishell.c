#include "ft_minishell.h"

void	create_signal_controller(void)
{
	signal(SIGINT, &signal_manager);
	signal(SIGQUIT, &signal_manager);
	g_global_pid = 0;
}

int	crete_or_cheak_file_history(t_minishell *all_command, int lvl)
{
	char	*path;
	int		len;
	int		fd;
	char	*tmp;
	char	*itoa;

	path = getenv("PWD");
	len = ft_strlen(path);
	path = ft_strjoin(path, "/tmp/lvl");
	tmp = path;
	itoa = ft_itoa(lvl);
	path = ft_strjoin(path, itoa);
	free(tmp);
	free(itoa);
	fd = open(path, O_WRONLY | O_CREAT, 0777 | O_TRUNC | O_APPEND);
	if (fd == -1)
		return (-1);
	all_command->file_history = path;
	close(fd);
	return (0);
}

int	changes_path_history(t_minishell *all_command, int lvl)
{
	int	len;
	int	i;
	int	fd;

	i = 0;
	len = ft_strlen(all_command->file_history);
	if (lvl < 10)
	{
		all_command->file_history[len -1] = lvl + '0';
		fd = open(all_command->file_history, O_WRONLY | \
			O_CREAT, 0777 | O_TRUNC | O_APPEND);
		if (fd == -1)
			return (-1);
		close(fd);
	}
	return (0);
}

void	allocate(t_minishell *all_command)
{
	all_command->onecovkey = 0;
	all_command->doublecovkey = 0;
	all_command->head = NULL;
}

int	main(int argc, char **argv, char **env)
{
	if (!argv[1])
		return (main_dup(argc, argv, env));
	else
		ft_putstr_fd("Error:too many arguments\n", 0);
	return (0);
}
