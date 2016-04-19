/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:15:56 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:33:01 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char*)ptr;
	while (i < len)
	{
		dest[i] = (char)value;
		i++;
	}
	return (ptr);
}
