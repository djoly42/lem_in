/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:59:09 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:23:46 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			ret[i] = f(s[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
