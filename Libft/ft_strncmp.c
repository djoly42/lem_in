/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:14:46 by djoly             #+#    #+#             */
/*   Updated: 2016/04/01 18:33:01 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (n == 0)
		return (0);
	i = ft_strlen(s1) + 1;
	j = ft_strlen(s2) + 1;
	if (j <= i)
		i = j;
	if (n < i)
		i = n;
	return (ft_memcmp(s1, s2, i));
}
