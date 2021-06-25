#include "ft_minishell.h"

int	handler_the_shooter(t_minishell *all_command,
			char **command, int *i, char **tmp)
{
	if (!ft_strcmp(all_command->term->str, "\e[A"))
	{
		press_up(all_command, command, i, tmp);
		all_command->term->key = 1;
	}
	else if (!ft_strcmp(all_command->term->str, "\e[B"))
	{
		press_down(all_command, command, i, tmp);
		all_command->term->key = 1;
	}
	else if (!ft_strcmp(all_command->term->str, "\e[C"))
	{
		all_command->term->key = 1;
	}
	else if (!ft_strcmp(all_command->term->str, "\e[D"))
	{
		all_command->term->key = 1;
	}
	return (0);
}

int	handler_the_signals(t_minishell *all_command,
		char **command, int *i)
{
	if (!ft_strcmp(all_command->term->str, "\177"))
	{
		press_backspase(i, command);
		all_command->term->key = 1;
	}
	else if (!ft_strcmp(all_command->term->str, "\n"))
	{
		write(1, "\n", 1);
		all_command->term->key = 2;
	}
	else if (!ft_strcmp(all_command->term->str, "\4"))
	{
		if (ft_strlen(*command) == 0)
		{
			free(*command);
			*command = NULL;
			all_command->term->key = 2;
		}
	}
	else if (!ft_strcmp(all_command->term->str, "\3"))
	{
		press_control_c(command);
		all_command->term->key = 2;
	}
	return (0);
}

int	handler_press(t_minishell *all_command, char **command, int *i, char **tmp)
{
	if (all_command->term->key == 0)
	{
		*tmp = *command;
		*command = ft_strjoin(*command, all_command->term->str);
		free(*tmp);
		write(1, all_command->term->str, all_command->term->len);
		*i = *i + all_command->term->len;
	}
	else
		all_command->term->key = 0;
	return (0);
}

int	create_char_command(char **command)
{
	*command = (char *)malloc(sizeof(char) * 1);
	if (*command == NULL)
		return (0);
	*command[0] = '\0';
	return (0);
}

char	*reeder_from_term(t_minishell *all_command)
{
	int				i;
	char			*command;
	char			*tmp;

	all_command->term->key = 0;
	save_old_term(all_command);
	create_char_command(&command);
	create_new_term(all_command);
	definition_history_line(all_command, &i);
	while (1 != 0)
	{
		all_command->term->len = read(0, all_command->term->str, 100);
		all_command->term->str[all_command->term->len] = '\0';
		handler_the_shooter(all_command, &command, &i, &tmp);
		handler_the_signals(all_command, &command, &i);
		if (all_command->term->key == 2)
			break ;
		handler_press(all_command, &command, &i, &tmp);
	}
	tcsetattr(fileno(stdin), TCSANOW, &(all_command->term->termios_und));
	free(all_command->term->str);
	return (command);
}
