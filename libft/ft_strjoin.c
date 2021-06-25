/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:21:57 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:02:24 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	s = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (NULL);
	while (++i < len1)
		s[i] = s1[i];
	i = 0;
	while (i < len2)
	{
		s[len1 + i] = s2[i];
		i++;
	}
	s[len1 + i] = '\0';
	return (s);
}
