/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:21:08 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:22:49 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	if (s1 && s2)
	{
		i = 0;
		j = -1;
		ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
		ft_strlen(s2) + 1));
		if (!ret)
			return (NULL);
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		while (s2[++j])
			ret[i + j] = s2[j];
		ret[i + j] = '\0';
		return (ret);
	}
	return (NULL);
}
