/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:30:49 by djoly             #+#    #+#             */
/*   Updated: 2016/01/13 17:01:58 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
