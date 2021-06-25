#include "ft_minishell.h"
pid_t	test(t_command_and_flag	*all, int	*pipe_1, \
int	*pipe_2, t_env	*env)
{
	struct stat	buff;
	pid_t		pid;

	if (pipe_2 != 0)
		pipe(pipe_2);
	pid = fork();
	g_global_pid = pid;
	if (!pid)
	{
		check_build_in(all, pipe_1, env->fd[0], env);
		check_build_in2(all, pipe_1, env->fd[0], env);
		redirect_pipe(pipe_1, 1);
		redirect_pipe(pipe_2, 0);
		redirect_fd(env->fd[0], 1);
		redirect_fd(env->fd[1], 0);
		if (!ft_strncmp(all->command, "minishell", 10) || \
		!ft_strncmp(all->command, "exit", 5))
			exit(0);
		if (stat(all->command, &buff))
			exit(1);
		if (execve(all->command, all->array_flags, env->env))
			exit(0);
	}
	close_pipe(pipe_1);
	return (pid);
}

void	fd_init(t_env	*env, int flag)
{
	if (flag)
	{
		env->fd[0] = 0;
		env->fd[1] = 0;
	}
	else
	{
		if (env->fd[1] != 0)
			close(env->fd[1]);
		if (env->fd[0] != 0)
			close(env->fd[0]);
		env->fd[0] = 0;
		env->fd[1] = 0;
	}
}

void	find_function(int size, t_env *env, t_command_and_flag *head, \
t_command_and_flag *reverse_head)
{
	int		**pipe;
	int		i;
	pid_t	*pid;

	i = -1;
	pipe = make_pipe(size);
	pid = malloc(sizeof(pid) * (size + 1));
	if (!pid)
		return ;
	fd_init(env, 1);
	while (++i <= size)
	{
		if (head && (head->pape == MORE || head->pape == DOUBLE_MORE || \
		head->pape == LESS))
			redirect(head, &env->fd[0], &env->fd[1]);
		while (head && (head->pape == MORE || head->pape == \
		DOUBLE_MORE || head->pape == LESS))
			head = redirect2(head);
		pid[i] = test(head, pipe[i], pipe[i + 1], env);
		head = head->next;
		fd_init(env, 0);
	}
	print_errors(pid, reverse_head, size, env);
	free_find_fubction(pipe, pid);
}

int	builtin_launch(t_env	*struct_env, int	size, \
t_command_and_flag	*tmp)
{
	if (!ft_strncmp(tmp->command, "export", 7) && size == 0)
	{
		ft_export(tmp, 0, struct_env);
		export_errors(tmp, struct_env);
		return (0);
	}
	else if (!ft_strncmp(tmp->command, "unset", 6) && size == 0)
	{
		ft_unset(tmp, struct_env);
		export_errors(tmp, struct_env);
		return (0);
	}
	else if (size == 0 && !ft_strncmp(tmp->command, "cd", 3))
	{	
		if (ft_cd(tmp, struct_env->env) == 10)
		{	
			ft_putstr_fd("cd: no such file or directory: ", 0);
			if (tmp->array_flags[1])
				ft_putstr_fd(tmp->array_flags[1], 0);
			ft_putstr_fd("\n", 0);
		}
		return (0);
	}
	return (1);
}

int	functions_launch(t_command_and_flag	**head,	\
t_env	*struct_env, int	*lvl, t_minishell *all)
{
	t_command_and_flag	*current_head;
	t_command_and_flag	*tmp;
	int					size;
	int					ret;

	ret = -1;
	tmp = 0;
	current_head = *head;
	size = 0;
	number_of_pipes(&size, &current_head, &tmp, all);
	if (builtin_launch(struct_env, size, tmp))
	{
		if ((!ft_strncmp(tmp->command, "exit", 5) || \
		!ft_strncmp(current_head->command, "exit", 5)) && size == 0)
			ret = ft_exit(tmp, struct_env);
		else if (size >= 0)
			find_function(size, struct_env, tmp, *head);
	}
	ft_list_clear(tmp);
	if (!ft_strncmp(current_head->command, "minishell", 10))
		ft_minishell_name(lvl, struct_env);
	return (ret);
}
