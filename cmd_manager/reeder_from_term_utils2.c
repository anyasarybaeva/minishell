#include "ft_minishell.h"

int	ft_strlen_history(t_minishell *all_command)
{
	int		history_slider;
	int		fd;
	char	*line;

	history_slider = 0;
	fd = open(all_command->file_history, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		free(line);
		history_slider++;
	}
	free(line);
	close(fd);
	return (history_slider);
}

char	*reader_history_line(t_minishell *all_command, int history_slider)
{
	char	*history_line;
	int		fd;
	int		i;

	i = 0;
	fd = open(all_command->file_history, O_RDONLY);
	while (i != history_slider)
	{
		get_next_line(fd, &history_line);
		free(history_line);
		i++;
	}
	get_next_line(fd, &history_line);
	close(fd);
	return (history_line);
}

int	save_old_term(t_minishell *all_command)
{
	tcgetattr(fileno(stdin), &all_command->term->termios_und);
	return (0);
}

int	create_new_term(t_minishell *all_command)
{
	int	stat_1;

	stat_1 = -1;
	if (!isatty(fileno(stdin)))
		return (-1);
	all_command->term->term_name = getenv("TERM");
	if (all_command->term->term_name == NULL)
		all_command->term->term_name = "xterm-256color";
	stat_1 = tcgetattr(0, &all_command->term->termios_p_in);
	all_command->term->termios_p_in.c_lflag &= ~(ICANON);
	all_command->term->termios_p_in.c_lflag &= ~(ECHO);
	all_command->term->termios_p_in.c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, &all_command->term->termios_p_in);
	tgetent(0, all_command->term->term_name);
	return (0);
}

int	definition_history_line(t_minishell *all_command, int *i)
{
	all_command->term->history_slider = ft_strlen_history(all_command);
	all_command->term->str = (char *)malloc(sizeof(char) * 101);
	if (all_command->term->str == NULL)
		return (0);
	*i = 0;
	write(1, "minishell$ ", 11);
	tputs(save_cursor, 1, ft_putchar);
	return (0);
}
