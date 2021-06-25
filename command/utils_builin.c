#include "ft_minishell.h"

int	ft_check_name(char *name)
{
	int	i;

	i = i;
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	while (name[i] && name[i] != '=')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	ft_value_name(char *str, int *end_of_key, int *value)
{
	*end_of_key = 0;
	while (str[*end_of_key] && str[*end_of_key] != '=')
		(*end_of_key)++;
	if (str[*end_of_key] == '=')
		*value = ft_strlen(str) - 1;
	else
		*value = 0;
	str[*end_of_key] = '\0';
	if (!ft_check_name(str))
	{
		if (*value)
			str[*end_of_key] = '=';
		return ;
	}
	if (*value)
		str[*end_of_key] = '=';
}

int	check_exit_num(char	*str)
{
	if (ft_strlen(str) > 10)
	{
		ft_putstr_fd("minishell: exit:", 0);
		ft_putstr_fd(str, 0);
		ft_putstr_fd(": numeric argument required\n", 0);
		return (1);
	}
	return (0);
}

int	ft_exit(t_command_and_flag	*tmp, t_env *env)
{
	long long	ret;

	if (tmp->array_flags[1])
	{
		if (check_exit_num(tmp->array_flags[1]) == 1)
		{
			env->exit_num = 255;
			return (-1);
		}
		if (ft_atoi(tmp->array_flags[1]) > 0)
			ret = ft_atoi(tmp->array_flags[1]) % 256;
		else
		{
			ret = ft_atoi(tmp->array_flags[1]);
			while (ret < 0)
				ret = 256 + ret;
		}
	}
	else
		ret = 0;
	return ((int)ret);
}

void	ft_minishell_name(int *lvl, t_env *struct_env)
{
	char	**argv;
	char	*tmp_2;
	int		i;

	i = 0;
	(*lvl)++;
	argv = (char **)malloc(sizeof(char *) * 3);
	if (!argv)
		return ;
	argv[0] = ft_strdup("a.out");
	tmp_2 = ft_itoa(*(lvl));
	argv[1] = ft_strdup(tmp_2);
	free(tmp_2);
	argv[2] = 0;
	struct_env->exit_num = main_dup(2, argv, struct_env->env);
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
