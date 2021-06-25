/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:50:32 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:10:52 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (!dst1 && !src1)
		return (0);
	if (dst >= src)
	{
		dst1 = dst1 + len;
		src1 = src1 + len;
		while (len--)
			*--dst1 = *--src1;
	}
	else
	{
		while (len--)
			*dst1++ = *src1++;
	}
	return (dst);
}
