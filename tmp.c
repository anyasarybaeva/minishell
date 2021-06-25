#include "ft_minishell.h"

void	print_command(t_minishell	*command_list)
{
	t_command_and_flag	*command;
	int					i;

	command = command_list->head;
	while (command)
	{
		printf("\n");
		printf("command name:|%s|\n", command->command);
		printf("pape:%d\n", command->pape);
		printf("error:%d\n", command->f_error);
		i = 0;
		while (command->array_flags[i])
		{
			printf("ar[%d]:|%s|\n", i, command->array_flags[i]);
			i++;
		}
		printf("ar[%d]:%s\n", i, command->array_flags[i]);
		command = command->next;
	}
}
