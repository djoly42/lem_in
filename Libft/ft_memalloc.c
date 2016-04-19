/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:10:40 by djoly             #+#    #+#             */
/*   Updated: 2015/12/01 18:15:45 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	if (!size)
		return (NULL);
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
