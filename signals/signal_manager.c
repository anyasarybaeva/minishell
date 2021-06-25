#include "ft_minishell.h"

void	signal_manager(int sig)
{
	int	i;

	i = 0;
	if (g_global_pid != 0 && sig == SIGINT)
	{
		kill(g_global_pid, sig);
		write(1, "\n", 1);
		g_global_pid = 0;
	}
	if (g_global_pid != 0 && sig == SIGQUIT)
	{
		kill(g_global_pid, sig);
		write(1, "Quit: 3\n", 8);
		g_global_pid = 0;
	}
}
