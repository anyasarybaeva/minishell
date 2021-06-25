/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:03:50 by lbones            #+#    #+#             */
/*   Updated: 2020/11/25 20:36:50 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

	i = 0;
	if (!s)
		return ("\0");
	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	if (!f)
		return (s1);
	while (s1[i])
	{
		s1[i] = (*f)(i, s[i]);
		i++;
	}
	return (s1);
}
