/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:06:40 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:02:53 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	size_t	i1;

	i1 = 0;
	i = ft_strlen((char *)s1);
	s2 = (char *)malloc(i + 1);
	if (!s2)
		return (NULL);
	while (i >= i1)
	{
		s2[i1] = s1[i1];
		i1++;
	}
	return (s2);
}
