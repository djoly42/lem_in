/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:07:13 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 17:21:32 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		beg;
	int		end;
	char	**tab;

	tab = NULL;
	i = 0;
	j = 0;
	if (s && (tab = (char **)malloc(sizeof(*tab) * (ft_words(s, c) + 1))))
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			beg = i;
			while (s[i] && s[i] != c)
				i++;
			end = i;
			if (end > beg)
				tab[j++] = ft_strsub(s, beg, (end - beg));
		}
		tab[j] = NULL;
	}
	return (tab);
}
