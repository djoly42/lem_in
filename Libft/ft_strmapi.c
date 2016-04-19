/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:03:37 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:23:32 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	i = 0;
	if (s && f)
	{
		if (!(ret = ft_memalloc(ft_strlen(s) + 1)))
			return (NULL);
		while (s[i])
		{
			ret[i] = (*f)(i, s[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
