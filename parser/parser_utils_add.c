#include "ft_minishell.h"

int	split_flags_utils5(t_command_and_flag *one_command, int j)
{
	one_command->array_flags = (char **)malloc(sizeof(char *) * (j + 2));
	if (one_command->array_flags == NULL)
		return (-1);
	return (0);
}

int	parser_flags_utils5(t_command_and_flag *one_command, \
		int *i, int *j, int *k)
{
	int	z;
	int	key;

	key = 0;
	z = 0;
	if (one_command->flags[*i + 1] == '\0' && one_command->flags[*i] != ' ')
	{
		(*i)++;
		key = 1;
	}
	one_command->array_flags[*k] = (char *)malloc(sizeof(char) * \
			((*i) - (*j) + 1));
	if (one_command->array_flags[*k] == NULL)
		return (-1);
	while (*j < *i)
	{
		one_command->array_flags[*k][z++] = one_command->flags[*j];
		(*j)++;
	}
	one_command->array_flags[*k][z] = '\0';
	(*k)++;
	(*j) = (*i);
	if (key == 1)
		(*i)--;
	return (0);
}

int	parser_flags_utils6(t_command_and_flag *one_command, \
		t_minishell *all_command, int k)
{
	one_command->array_flags[k] = NULL;
	ft_clear_flags_from_kov(all_command);
	return (0);
}
