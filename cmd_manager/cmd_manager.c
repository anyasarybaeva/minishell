#include "ft_minishell.h"

int	save_sistem_term(t_minishell *all_command)
{
	int				stat_1;
	struct termios	termios_p_in;

	stat_1 = tcgetattr(fileno(stdin), &termios_p_in);
	if (stat_1 == 0)
		all_command->term->termios_p_in = termios_p_in;
	else
		return (-1);
	return (0);
}

int	create_new_sistem_term(t_minishell *all_command)
{
	int				stat_1;
	struct termios	termios_p_in;

	stat_1 = tcgetattr(0, &termios_p_in);
	if (stat_1 == 0)
		all_command->term->termios_p_in = termios_p_in;
	else
		return (-1);
	return (0);
}

int	return_settings_term(t_minishell *all_command)
{
	tcsetattr(fileno(stdin), TCSANOW, &all_command->term->termios_und);
	return (0);
}

char	*cmd_manager(t_minishell *all_command)
{
	char	*command;

	save_sistem_term(all_command);
	command = reeder_from_term(all_command);
	return (command);
}
