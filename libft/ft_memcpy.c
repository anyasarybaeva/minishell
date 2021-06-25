/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:43:42 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:11:54 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			n1;

	n1 = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		dst1[n1] = src1[n1];
		n1++;
		n--;
	}
	return (dst1);
}
