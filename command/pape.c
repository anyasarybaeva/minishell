#include "ft_minishell.h"

void	number_of_pipes(int	*size, t_command_and_flag	**head1, \
t_command_and_flag	**new_head, t_minishell *all)
{
	t_command_and_flag	*head;
	t_command_and_flag	*tmp;

	tmp = 0;
	head = *head1;
	*size = 0;
	if (head->pape == MORE || head->pape == DOUBLE_MORE)
		*size = -1;
	ft_list_push_front(new_head, head);
	head = head->next;
	while (head)
	{
		if (head->pape != MORE && head->pape != \
		DOUBLE_MORE && head->pape != LESS)
			*size += 1;
		if (head->pape == DOUBLE_LESS)
		{
			tmp = ft_double_less(head->command, all);
			ft_list_push_second(new_head, tmp);
			free_tmp(tmp);
		}
		else
			ft_list_push_front(new_head, head);
		head = head->next;
	}
}

int	**make_pipe(int	size)
{
	int	**pipe;
	int	i;

	i = 0;
	if (size < 0)
		return (0);
	pipe = malloc(sizeof(int *) * (size + 2));
	if (!pipe)
		return (0);
	pipe[i++] = NULL;
	while (i <= size)
	{
		pipe[i] = malloc(sizeof(int) * 2);
		if (!pipe[i++])
			return (0);
	}
	pipe[size + 1] = NULL;
	return (pipe);
}
