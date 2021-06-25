#include "ft_minishell.h"

void	redirect(t_command_and_flag	*all, int	*fd1, int	*fd2)
{
	if (all->pape == MORE)
		*fd1 =open(all->command, O_WRONLY |O_TRUNC);
	else if (all->pape == DOUBLE_MORE)
		*fd1 = open(all->command, O_WRONLY |O_APPEND);
	else if (all->pape == LESS)
		*fd2 = open(all->command, O_RDONLY);
}

t_command_and_flag	*redirect2(t_command_and_flag	*all)
{
	int	fd;

	fd = 0;
	while (all && (all->pape == MORE || \
	all->pape == DOUBLE_MORE || all->pape == LESS))
	{
		if (all->pape == MORE)
		{
			fd = open(all->command, O_WRONLY |O_TRUNC);
			close(fd);
		}
		else if (all->pape == DOUBLE_MORE)
		{
			fd = open(all->command, O_WRONLY |O_APPEND);
			close(fd);
		}
		else if (all->pape == LESS)
		{
			fd = open(all->command, O_RDONLY);
			close(fd);
		}
		all = all->next;
	}
	return (all);
}

t_command_and_flag	*ft_double_less(char	*split, t_minishell *all_com)
{
	char				*str;
	int					len;
	t_command_and_flag	*all;

	all = malloc(sizeof(t_command_and_flag));
	if (!all)
		return (0);
	all->command = ft_strdup(split);
	all->array_flags = 0;
	all->array_flags = new_array_add(all->array_flags, split);
	len = ft_strlen(split);
	while (1)
	{
		str = term_from_double_less(all_com);
		if (str == NULL)
			break ;
		if (!ft_strncmp(str, split, len + 1))
			break ;
		all->array_flags = new_array_add(all->array_flags, str);
		free(str);
	}
	all->pape = DOUBLE_LESS;
	free(str);
	return (all);
}

void	ft_double_less_print(t_command_and_flag *all, int fd)
{
	int	i;

	i = 1;
	while (all->array_flags[i])
	{
		ft_putstr_fd(all->array_flags[i++], fd);
		ft_putchar_fd('\n', fd);
	}
	exit(0);
}

void	redirect_fd(int fd, int where)
{
	if (fd)
	{
		dup2(fd, where);
		close(fd);
	}
}
