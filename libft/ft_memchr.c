/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:30:12 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:12:44 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)s;
	while (n != i)
	{
		if (s1[i] == (unsigned char)c)
			return (&s1[i]);
		i++;
	}
	return (0);
}
