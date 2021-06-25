/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:41:44 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 17:52:22 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;
	size_t	i1;

	i1 = 0;
	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	s1 = (char *)malloc(len + 1);
	if (!s1)
		return (NULL);
	while (i1 < len && start < i)
		s1[i1++] = s[start++];
	s1[i1] = '\0';
	return (s1);
}
