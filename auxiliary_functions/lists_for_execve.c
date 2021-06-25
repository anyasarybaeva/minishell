#include "ft_minishell.h"
t_command_and_flag	*ft_create_elem(t_command_and_flag *data)
{
	t_command_and_flag	*elem;
	int					i;

	i = 0;
	elem = (t_command_and_flag *)malloc(sizeof(t_command_and_flag));
	if (elem == NULL)
		return (NULL);
	elem->pape = data->pape;
	elem->command = ft_strdup(data->command);
	while (data->array_flags[i])
		i++;
	elem->array_flags = malloc(sizeof(char *) * (i + 1));
	if (!elem->array_flags)
		return (0);
	i = -1;
	while (data->array_flags[++i])
		elem->array_flags[i] = ft_strdup(data->array_flags[i]);
	elem->array_flags[i] = NULL;
	elem->next = 0;
	return (elem);
}

void	ft_list_push_front(t_command_and_flag	**begin_list, \
	t_command_and_flag	*data)
{
	t_command_and_flag	*elem;

	if (begin_list != 0)
	{
		elem = ft_create_elem(data);
		elem->next = *begin_list;
		*begin_list = elem;
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_list_push_second(t_command_and_flag	**begin_list, \
	t_command_and_flag	*data)
{
	t_command_and_flag	*elem1;
	t_command_and_flag	*tmp;

	elem1 = *begin_list;
	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
	{
		tmp = elem1->next;
		elem1->next = ft_create_elem(data);
		elem1->next->next = tmp;
	}
}

void	ft_list_clear(t_command_and_flag *command)
{
	int					i;
	t_command_and_flag	*tmp;

	while (command)
	{
		free(command->command);
		i = 0;
		while (command->array_flags[i])
		{
			free(command->array_flags[i]);
			i++;
		}
		free(command->array_flags);
		tmp = command->next;
		free(command);
		command = tmp;
	}
}
