/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:26:54 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:11:28 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		*dst1 = *src1;
		if (*src1 == (unsigned char)c)
			return (dst1 + 1);
		dst1++;
		src1++;
		n--;
	}
	return (NULL);
}
