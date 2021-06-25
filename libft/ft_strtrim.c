/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:39:33 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 17:52:58 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	i1;
	char	*s;

	i1 = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1);
	while (len && ft_strchr(set, (int)s1[len - 1]))
		len--;
	i = 0;
	while (s1[i] && i <= len && ft_strchr(set, (int)s1[i]))
		i++;
	s = (char *)malloc(sizeof(char) * (len + 1 - i));
	if (!s)
		return (NULL);
	while (len > i)
		s[i1++] = (char)s1[i++];
	s[i1] = '\0';
	return (s);
}
