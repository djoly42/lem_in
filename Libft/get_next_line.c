/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 09:37:17 by djoly             #+#    #+#             */
/*   Updated: 2016/03/30 11:49:55 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int					ft_find(char **str, char **line)
{
	char				*rm;

	rm = *str;
	*line = ft_strsub(*str, 0, ft_strchr(*str, '\n') - *str);
	*str = ft_strsub(*str, ft_strchr(*str, '\n') - *str + 1,
	ft_strlen(ft_strchr(*str, '\n')));
	free(rm);
	return (1);
}

static int					ft_end(char **str, char **line)
{
	*line = ft_strdup(*str);
	*str = ("");
	return (1);
}

static char					*ft_join_free(char *s1, char *s2)
{
	char				*tmp;

	tmp = s1;
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	return (s1);
}

static int					ft_find_line(int ret, char **str, char **line)
{
	if (ret == -1)
		return (-1);
	if (ft_strchr(*str, '\n') || ret > 0)
		return (ft_find(str, line));
	else if (ft_strlen(*str) > 0)
		return (ft_end(str, line));
	*line = NULL;
	return (0);
}

int							get_next_line(int const fd, char **line)
{
	static char			*str[256];
	char				*tmp;
	int					ret;

	if (BUFF_SIZE == 0)
		return (0);
	if (fd < 0 || line == NULL || fd > 256)
		return (-1);
	str[fd] = str[fd] ? str[fd] : ft_strnew(0);
	tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		str[fd] = ft_join_free(str[fd], tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free(tmp);
	return (ft_find_line(ret, &str[fd], line));
}
