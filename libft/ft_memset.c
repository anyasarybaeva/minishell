/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:41:09 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:09:36 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b1;

	b1 = (unsigned char *)b;
	while (len > 0)
	{
		*b1 = (unsigned char)c;
		b1++;
		len--;
	}
	return (b);
}
