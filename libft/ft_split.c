/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:58:20 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:04:46 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		free(c[i++]);
	free(c);
}

int	ft_len(int i, const char *s, char c)
{
	int	len;
	int	i3;

	i3 = i;
	len = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		if ((len == 0 || i != i3) || s[i])
			len++;
		while (s[i] == c && s[i])
			i++;
	}
	return (len);
}

char	**ft_fill(const char *s, char c, int i, char **s1)
{
	int	i3;
	int	len;
	int	i1;

	i1 = 0;
	i3 = 0;
	len = ft_len(i, s, c);
	while (len > i1)
	{
		i = i3;
		while (s[i++] == c)
			i3++;
		while (s[i] != c && s[i])
			i++;
		s1[i1] = ft_substr(s, i3, i - i3);
		if (!s1[i1])
		{
			ft_free(s1);
			return (NULL);
		}
		i3 = i;
		i1++;
	}
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**s1;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	len = ft_len(i, s, c);
	s1 = (char **)malloc(sizeof(char *) * (len + 1));
	if (!s1)
		return (NULL);
	s1[len] = NULL;
	return (ft_fill(s, c, i, s1));
}
