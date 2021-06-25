#include "ft_minishell.h"

void	export_errors(t_command_and_flag	*all, t_env *env)
{
	int	i;
	int	i1;

	i = 1;
	if (!all->array_flags[i])
		return ;
	while (all->array_flags[i])
	{
		i1 = 0;
		while (all->array_flags[i][i1] && all->array_flags[i][i1] != '=')
			i1++;
		if (all->array_flags[i][i1] == '=')
			all->array_flags[i][i1] = '\0';
		if (!ft_check_name(all->array_flags[i]) && \
		!ft_check_name(&all->array_flags[i][1]))
		{	
			ft_putstr_fd("minishell: ", 0);
			ft_putstr_fd(all->command, 0);
			ft_putstr_fd(": '", 0);
			ft_putstr_fd(all->array_flags[i], 0);
			ft_putstr_fd("': not a valid identifier\n", 0);
			env->exit_num = 1;
		}
		i++;
	}
}

void	redirect_errors(t_command_and_flag *reverse_head)
{
	if (!reverse_head)
		return ;
	if ((reverse_head->pape == LESS && (reverse_head->f_error == -3 || reverse_head->f_error == -1)) || \
	((reverse_head->pape == MORE || reverse_head->pape == DOUBLE_MORE) && \
	reverse_head->f_error == -1))
	{
		ft_putstr_fd("minishell: ", 0);
		ft_putstr_fd(reverse_head->array_flags[1], 0);
		ft_putstr_fd(": No such file or directory\n", 0);
	}
	else if ((reverse_head->pape == LESS && reverse_head->f_error == -2) || ((reverse_head->pape == MORE || \
	reverse_head->pape == DOUBLE_MORE) && reverse_head->f_error == -2))
		ft_putstr_fd(SYN_ERROR_TOK_NEW, 0);
	else if ((reverse_head->pape == MORE || reverse_head->pape == \
	DOUBLE_MORE) && reverse_head->f_error == -2)
	{
		ft_putstr_fd("minishell: ", 0);
		ft_putstr_fd(reverse_head->array_flags[1], 0);
		ft_putstr_fd(": Permission denied\n", 0);
	}
}

int	builin_errors(t_command_and_flag	*reverse_head, int	fd1, t_env	*env)
{
	if (!ft_strncmp(reverse_head->command, "export", 7) || \
	!ft_strncmp(reverse_head->command, "unset", 6))
	{
		export_errors(reverse_head, env);
		return (0);
	}
	if (!ft_strncmp(reverse_head->command, "env", 4) && fd1 != 0)
	{	
		ft_putstr_fd("env: ", 0);
		ft_putstr_fd(reverse_head->array_flags[1], 0);
		ft_putstr_fd(": No such file or directory\n", 0);
		env->exit_num = 127;
		return (0);
	}
	else if (!ft_strncmp(reverse_head->command, "cd", 3) && fd1 != 0)
	{
		ft_putstr_fd("cd: no such file or directory: ", 0);
		ft_putstr_fd(reverse_head->array_flags[1], 0);
		ft_putstr_fd("\n", 0);
		env->exit_num = 1;
		return (0);
	}
	return (exit_error(reverse_head, env));
}

void	bin_errors(t_command_and_flag *reverse_head, int fd1, t_env *env)
{
	if (reverse_head->f_error == WRONG_COMMAND && fd1 == 256)
	{
		ft_putstr_fd("zsh: command not found:", 0);
		ft_putstr_fd(reverse_head->command, 0);
		ft_putstr_fd("\n", 0);
		env->exit_num = 127;
	}
	else if (fd1 == 256)
		env->exit_num = 1;
	else
		env->exit_num = 0;
}

void	print_errors(pid_t	*pid, t_command_and_flag *reverse_head, \
int size, t_env *env)
{
	int	fd1;

	while (size >= 0)
	{	
		waitpid(pid[size], &fd1, 0);
		pid[size] = 0;
		while (reverse_head && (reverse_head->pape == MORE || \
		reverse_head->pape == DOUBLE_MORE || reverse_head->pape == LESS))
		{
			redirect_errors(reverse_head);
			reverse_head = reverse_head->next;
		}
		if (builin_errors(reverse_head, fd1, env) && fd1 != 0)
			bin_errors(reverse_head, fd1, env);
		size--;
		reverse_head = reverse_head->next;
	}
	while (reverse_head && (reverse_head->pape == MORE || reverse_head->pape == \
	DOUBLE_MORE || reverse_head->pape == LESS))
	{
		redirect_errors(reverse_head);
		reverse_head = reverse_head->next;
	}
}
