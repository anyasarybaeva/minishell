/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:17:36 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 18:18:49 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ar;

	ar = malloc(count * size);
	if (!ar)
		return (NULL);
	ft_bzero(ar, size * count);
	return ((void *)ar);
}
