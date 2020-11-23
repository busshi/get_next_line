/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:29:59 by aldubar           #+#    #+#             */
/*   Updated: 2020/11/23 22:01:08 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(int readed, char **join, char **line)
{
	size_t	i;
	char	*tmp;

	if (readed < 0)
		return (-1);
	if (!*join)
	{
		*line = ft_strdup("");
		return (0);
	}
	i = 0;
	while ((*join)[i] != '\n' && (*join)[i] != '\0')
		i++;
	*line = ft_substr(*join, 0, i);
	if ((*join)[i] == '\n')
		tmp = ft_strdup(&(*join)[i + 1]);
	else
		tmp = NULL;
	free(*join);
	*join = tmp;
	if (!*join)
		return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*join;
	char		*tmp;
	int			readed;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	if (!line || BUFFER_SIZE < 1 || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((readed = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readed] = '\0';
		if (!join)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(join, buf);
		free(join);
		join = tmp;
		if (ft_strchr(join, '\n'))
			break ;
	}
	free(buf);
	return (get_line(readed, &join, line));
}
