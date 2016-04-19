/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:43:12 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 12:05:37 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(ret->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(ret->content, content, content_size);
		ret->content_size = content_size;
		ret->next = NULL;
	}
	else
	{
		ret->content = NULL;
		ret->content_size = 0;
		ret->next = NULL;
	}
	return (ret);
}
