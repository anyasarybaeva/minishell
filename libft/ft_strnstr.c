/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:16:34 by lbones            #+#    #+#             */
/*   Updated: 2021/04/30 17:57:12 by lbones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i1;

	i1 = 0;
	i = 0;
	while (needle[i1])
		i1++;
	if (i1 == 0)
		return ((char *)haystack);
	while (len && *haystack)
	{
		while (*(haystack + i) == *(needle + i) && *(needle + i)
			&& (haystack + i) && (len - i))
			i++;
		if (i1 == i)
			return ((char *)(haystack));
		haystack++;
		len--;
		i = 0;
	}
	return (0);
}
