/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:34:19 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:29:59 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	if ((char)c == '\0')
		return (char *)(&s[i + 1]);
	while (s[i] != '\0')
	{
		if (s[i] == ((char)c))
			return (char *)(&s[i]);
		else
			i--;
	}
	return (NULL);
}
