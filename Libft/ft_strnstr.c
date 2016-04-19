/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:04:40 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:29:29 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[i] == '\0')
		return (char *)(&s1[i]);
	while (s1[i] != '\0')
	{
		k = i;
		while ((s1[i] == s2[j]) && (i < n) && (s2[j] != '\0'))
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return (char *)&(s1[i - j]);
		}
		j = 0;
		i = k;
		i++;
	}
	return (NULL);
}
