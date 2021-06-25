/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:35:39 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:19:16 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned char	*b1;
	size_t			i;

	i = 0;
	b1 = (unsigned char *)b;
	while (len > 0)
	{
		b1[i] = '\0';
		i++;
		len--;
	}
}
