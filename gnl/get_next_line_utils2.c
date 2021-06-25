#include "get_next_line.h"

int	tern_oper(int	read_count, char	*ostatok, char	*p_n)
{
	if (read_count == 0 && ft_strlen(ostatok) == 0 && p_n == NULL)
		return (1);
	return (0);
}

char	*lounch_strchar(char **p_n, char *buf)
{
	*p_n = ft_strchr(buf, '\n');
	return (*p_n);
}
