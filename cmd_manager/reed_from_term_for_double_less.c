#include "ft_minishell.h"

int	definition_history_line2(t_minishell *all_command, int *i)
{
	all_command->term->str = (char *)malloc(sizeof(char) * 101);
	if (all_command->term->str == NULL)
		return (0);
	*i = 0;
	write(1, "> ", 2);
	tputs(save_cursor, 1, ft_putchar);
	return (0);
}

int	handler_the_shooter2(t_minishell *all_command)
{
	if (!ft_strcmp(all_command->term->str, "\e[A"))
	{
	}
	else if (!ft_strcmp(all_command->term->str, "\e[B"))
	{
	}
	else if (!ft_strcmp(all_command->term->str, "\e[C"))
	{
	}
	else if (!ft_strcmp(all_command->term->str, "\e[D"))
	{
	}
	return (0);
}

char	*term_from_double_less(t_minishell *all_command)
{
	int				i;
	char			*command;
	char			*tmp;

	all_command->term->key = 0;
	save_old_term(all_command);
	create_char_command(&command);
	create_new_term(all_command);
	definition_history_line2(all_command, &i);
	while (1 != 0)
	{
		all_command->term->len = read(0, all_command->term->str, 100);
		all_command->term->str[all_command->term->len] = '\0';
		handler_the_shooter2(all_command);
		handler_the_signals(all_command, &command, &i);
		if (all_command->term->key == 2)
			break ;
		handler_press(all_command, &command, &i, &tmp);
	}
	tcsetattr(fileno(stdin), TCSANOW, &(all_command->term->termios_und));
	free(all_command->term->str);
	return (command);
}
