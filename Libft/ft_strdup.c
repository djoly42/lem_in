/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:02:20 by djoly             #+#    #+#             */
/*   Updated: 2015/12/30 11:39:01 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*dest;
	int		count;

	count = 0;
	length = 0;
	while (s1[length] != '\0')
		length++;
	dest = (char*)malloc(sizeof(*s1) * (length + 1));
	if (!dest)
		return (NULL);
	while (count < length)
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
