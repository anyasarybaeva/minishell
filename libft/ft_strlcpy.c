/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:27:10 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:00:55 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i1;

	i1 = 0;
	i = 0;
	if (!src)
		return (0);
	while (src[i])
		i++;
	if (dstsize >= 1)
	{
		while ((dstsize - 1) > i1 && *(src + i1))
		{
			*(dst + i1) = *(src + i1);
			i1++;
		}
		dst[i1] = '\0';
	}
	return (i);
}
