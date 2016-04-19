/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:05:04 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:29:39 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(s2);
	if (s2[0] == '\0' || s2 == NULL)
		return ((char*)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[j + i])
		{
			if (j == len - 1)
				return ((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
