#include "ft_minishell.h"

int	main_dup_utils(t_minishell *all_command, char **argv, \
		t_env **struct_env, char **env)
{
	all_command->ret = -1;
	if (!argv[1])
		all_command->lvl = 0;
	else
		all_command->lvl = ft_atoi(argv[1]);
	*struct_env = allocate_env(env, all_command->lvl);
	create_env_lvl(*struct_env, all_command->lvl);
	all_command->flag = 1;
	all_command->env = *struct_env;
	all_command->path = find_path();
	allocate(all_command);
	crete_or_cheak_file_history(all_command, all_command->lvl);
	create_signal_controller();
	return (0);
}

int	main_dup_utils2(t_minishell *all_command)
{
	all_command->lvl--;
	write(1, "\n", 1);
	all_command->ret = 0;
	return (0);
}

int	main_dup_utils3(t_minishell *all_command, t_env *struct_env, char *command)
{
	parser_commands(command, all_command);
	free(command);
	all_command->ret = functions_launch(&all_command->head, \
			struct_env, &all_command->lvl, all_command);
	return (0);
}

int	main_dup_utils5(t_minishell *all_command, char *command, t_env *struct_env)
{
	while (1 != 0)
	{
		command = cmd_manager(all_command);
		if (command == NULL)
		{
			main_dup_utils2(all_command);
			break ;
		}
		if (command != NULL)
		{
			if (ft_strlen(command) != 0)
			{
				main_dup_utils3(all_command, struct_env, command);
				if (all_command->ret != -1)
					break ;
				rebut(all_command);
				find_path_from_new_env(all_command);
			}
			else
				free(command);
		}
	}
	return (0);
}

int	main_dup(int argc, char **argv, char **env)
{
	t_minishell			all_command;
	t_command_and_flag	command_and_flag;
	char				*command;
	t_term_sistem		term;
	t_env				*struct_env;

	(void)argc;
	all_command.term = &term;
	all_command.head = &command_and_flag;
	main_dup_utils(&all_command, argv, &struct_env, env);
	main_dup_utils5(&all_command, command, struct_env);
	rebut(&all_command);
	clear_malloc(&all_command, all_command.env);
	ft_putstr_fd("exit\n", 0);
	return (all_command.ret);
}
