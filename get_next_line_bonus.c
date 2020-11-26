/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:29:59 by aldubar           #+#    #+#             */
/*   Updated: 2020/11/26 00:01:33 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		get_line(int readed, t_list *join, char **line)
{
	size_t	i;
	char	*tmp;

	if (readed < 0)
		return (-1);
	if (!join)
	{
		*line = ft_strdup("");
		return (0);
	}
	i = 0;
	tmp = join->content;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	*line = ft_substr_light(tmp, 0, i);
	if (tmp[i] == '\n')
	{
		join->content = join->content + i + 1;
		return (1);
	}
	else
	{
		join->content = NULL;
		return (0);
	}
}

static int		ft_check(int fd, char **buf)
{
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (0);
	if (read(fd, *buf, 0) < 0)
	{
		free(*buf);
		return (0);
	}
	return (1);
}

static t_list	*ft_lstnew(void *content, int file)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->file = file;
	new->next = NULL;
	return (new);
}

static t_list	*get_fd(int fd, t_list **lst)
{
	t_list	*tmp;
	int		file;

	tmp = *lst;
	while (tmp)
	{
		file = tmp->file;
		if (fd == file)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	if (*lst)
		tmp->next = *lst;
	*lst = tmp;
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	char			*buf;
	int				readed;
	static t_list	*files;
	t_list			*tmp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || !ft_check(fd, &buf))
		return (-1);
	readed = 1;
	tmp = get_fd(fd, &files);
	while (readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = '\0';
		if (!tmp->content)
			tmp->content = ft_strdup(buf);
		else
			tmp->content = ft_strjoin(tmp->content, buf);
		if (ft_strchr(tmp->content, '\n'))
			break ;
	}
	free(buf);
	return (get_line(readed, tmp, line));
}
