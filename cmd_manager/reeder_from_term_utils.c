#include "ft_minishell.h"

int	press_up(t_minishell *all_command, char**command, int *i, char **tmp)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	if (all_command->term->history_slider != 0)
	{
		all_command->term->history_line = \
		reader_history_line(all_command, all_command->term->history_slider);
		write(1, all_command->term->history_line, \
		ft_strlen(all_command->term->history_line));
		all_command->term->history_slider--;
		free(*command);
		*command = (char *)malloc(sizeof(char) * 1);
		if (*command == NULL)
			return (-1);
		*command[0] = '\0';
		*tmp = *command;
		*command = ft_strjoin(*command, all_command->term->history_line);
		free(*tmp);
		free(all_command->term->history_line);
		*i = ft_strlen(*command);
	}
	return (0);
}

int	press_down(t_minishell *all_command, char **command, int *i, char **tmp)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	if (all_command->term->history_slider != MAX_LINE)
	{
		all_command->term->history_line = reader_history_line(all_command, \
		all_command->term->history_slider);
		write(1, all_command->term->history_line, \
		ft_strlen(all_command->term->history_line));
		all_command->term->history_slider++;
		free(*command);
		*command = (char *)malloc(sizeof(char) * 1);
		if (*command == NULL)
			return (0);
		*command[0] = '\0';
		*tmp = *command;
		*command = ft_strjoin(*command, all_command->term->history_line);
		free(*tmp);
		free(all_command->term->history_line);
		*i = ft_strlen(*command);
	}
	return (0);
}

int	create_term_win(t_minishell *all_command)
{
	struct winsize	win;

	ioctl(1, TIOCGWINSZ, &win);
	all_command->win = &win;
	return (0);
}

int	press_control_c(char **command)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tgetstr("ed", 0), 1, ft_putchar);
	write(1, "\n", 1);
	free(*command);
	*command = malloc(sizeof(char) * 1);
	if (*command == NULL)
		return (0);
	*command[0] = '\0';
	return (0);
}

int	press_backspase(int *i, char **command)
{
	int	len;

	len = ft_strlen(*command);
	if (*i != 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		(*command)[ft_strlen(*command) - 1] = '\0';
		*i = *i - 1;
	}
	return (0);
}
