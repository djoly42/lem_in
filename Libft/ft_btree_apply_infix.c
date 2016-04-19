/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:40:55 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:59:53 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		if (root->left)
			btree_apply_infix(root->left, applyf);
		(*applyf)(root->item);
		if (root->right)
			btree_apply_infix(root->right, applyf);
	}
}
