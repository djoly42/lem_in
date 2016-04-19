/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:51:07 by djoly             #+#    #+#             */
/*   Updated: 2015/12/02 10:47:33 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	ft_isnegative(&n, &neg);
	len = ft_nbrlen(n);
	len = len + neg;
	if ((s = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	s[--len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
