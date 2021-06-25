/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:59:01 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 17:57:44 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	i;
	size_t	i1;

	i = 0;
	if (num < 1)
		return (0);
	while (num > 1 && *s1 == *s2 && *s1 && *s2)
	{
		num--;
		s1++;
		s2++;
	}
	i = *s1;
	i1 = *s2;
	if (i > i1)
		return (1);
	else if (i == i1)
		return (0);
	return (-1);
}
