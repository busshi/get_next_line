#include "get_next_line.h"
/*
char	*get_line(char *join, size_t i)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line = ft_substr(join, 0, i);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*join;
	char		*tmp;
	size_t		i;
	int		readed;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
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
			break;
	}
	free(buf);
	if (readed < 0)
		return (-1);
	if (!join)
	{
		*line = ft_strdup("");
		return (0);
	}
	i = 0;
	while (join[i] != '\n' && join[i] != '\0')
		i++;
	tmp = get_line(join, i);
	*line = tmp;
	if (join[i] == '\n')
		tmp = ft_strdup(&join[i + 1]);
	else
		tmp = NULL;
	free(join);
	join = tmp;
	if (!join)
		return (0);
	return (1);
}
*/
int		ft_return(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr(*str, 0, i);
	if ((*str)[i] == '\n')
		tmp = ft_strdup(&(*str)[i + 1]);
	else
		tmp = NULL;
	free(*str);
	*str = tmp;
	if (!*str)
		return (0);
	return (1);
}

int		readline(int fd, char **str, char **buff)
{
	int		res;
	char	*tmp;

	while ((res = read(fd, *buff, BUFFER_SIZE)) > 0)
	{
		(*buff)[res] = '\0';
		if (!*str || !**str)
		{
			tmp = ft_strdup(*buff);
			free(*str);
			*str = tmp;
		}
		else
		{
			tmp = ft_strjoin(*str, *buff);
			free(*str);
			*str = tmp;
		}
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(*buff);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	int				res;
	static char		*str;
	char			*buff;

	if (!(buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char))))
		return (-1);
	if (fd < 0 || !line || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	res = readline(fd, &str, &buff);
	if (res < 0)
		return (-1);
	if (!str)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_return(&str, line));
}
