/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:40:33 by dmadelei          #+#    #+#             */
/*   Updated: 2020/12/01 18:18:37 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	lounch_read(int	*read_count, int	fd, char	*buf)
{
	*read_count = read(fd, buf, 32);
	return (*read_count);
}

char	*lounch_stjoin(char	**result, char	*buf)
{
	*result = ft_strjoin(*result, buf);
	return (*result);
}

char	*read_in_buffer(int fd, char **ostatok, int *key)
{
	int		read_count;
	char	*p_n;
	char	*result;
	char	*tmp;
	char	buf[33];

	read_count = 0;
	p_n = chek_remain(*ostatok, &result);
	while ((!p_n && lounch_read(&read_count, fd, buf)) != 0)
	{
		buf[read_count] = '\0';
		if (lounch_strchar(&p_n, buf))
		{
			*p_n = '\0';
			p_n++;
			free(*ostatok);
			*ostatok = ft_strdup(p_n);
		}
		tmp = result;
		if ((lounch_stjoin(&result, buf)) == NULL)
			return (NULL);
		free(tmp);
	}
	*key = tern_oper(read_count, *ostatok, p_n);
	return (result);
}

char	*chek_remain(char *ostatoc, char **result)
{
	char	*p_n;

	p_n = NULL;
	if (ostatoc)
	{
		if (lounch_strchar(&p_n, ostatoc))
		{
			*p_n = '\0';
			*result = ft_strdup(ostatoc);
			p_n++;
			ft_strcpy(ostatoc, p_n);
		}
		else
		{
			*result = ft_strdup(ostatoc);
			while (*ostatoc)
			{
				*ostatoc = '\0';
				ostatoc++;
			}
		}
	}
	return (p_n);
}

char	*ft_strcpy(char	*dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
