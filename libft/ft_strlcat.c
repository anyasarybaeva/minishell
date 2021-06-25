/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:04:15 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:01:20 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i1;
	size_t	size;

	i = 0;
	i1 = 0;
	while (dst[i] && dstsize > i)
		i++;
	while (src[i1])
		i1++;
	size = dstsize - i - 1;
	if (dstsize <= i)
		return (dstsize + i1);
	i1 = i1 + i;
	while (size && *src)
	{
		dst[i] = *src;
		src++;
		i++;
		size--;
	}
	dst[i] = '\0';
	return (i1);
}
