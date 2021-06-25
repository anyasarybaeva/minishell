#include "ft_minishell.h"

void	ft_unset_env_lvl(t_env	*struct_env, char	*str, int	len)
{
	int	i;

	i = -1;
	while (struct_env->env_lvl[++i])
	{
		if (!ft_strncmp(struct_env->env_lvl[i], str, len) && \
		struct_env->env_lvl[i][len] == '\0')
		{
			struct_env->env_lvl = new_array_rm(struct_env->env_lvl, i);
			break ;
		}
	}
}

void	ft_unset_loop(char	*str, t_env	*struct_env)
{
	int	len;
	int	i;

	i = -1;
	if (ft_check_name(str))
	{
		len = ft_strlen(str);
		while (struct_env->env[++i])
		{
			if (!ft_strncmp(struct_env->env[i], str, len) && \
			struct_env->env[i][len] == '=')
			{
				struct_env->env = new_array_rm(struct_env->env, i);
				struct_env->keys = new_array_rm(struct_env->keys, i);
				struct_env->values = new_array_rm(struct_env->values, i);
				break ;
			}
		}
		if (!struct_env->env_lvl)
			return ;
		ft_unset_env_lvl(struct_env, str, len);
	}
}

int	ft_unset(t_command_and_flag	*all, t_env	*struct_env)
{
	int	i;
	int	len;
	int	i1;
	int	num;

	num = 0;
	i1 = 0;
	i = 0;
	if (!all->array_flags[1])
		return (0);
	while (all->array_flags[++num])
	{
		if (all->array_flags[num][0] == '$')
			ft_unset_loop(&all->array_flags[num][1], struct_env);
		else
			ft_unset_loop(all->array_flags[num], struct_env);
	}
	return (0);
}
