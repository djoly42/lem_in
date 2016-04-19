/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:22:59 by djoly             #+#    #+#             */
/*   Updated: 2016/04/01 18:32:43 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + 1;
	j = ft_strlen(s2) + 1;
	if (i > j)
		i = j;
	return (ft_memcmp(s1, s2, i));
}
