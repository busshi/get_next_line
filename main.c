#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	(void)ac;
	int	fd;
	size_t	i;
	char	*line;

	i = 1;
	while (av[i])
	{
		fd = open(av[i], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
			free(line);
		}
		free(line);
		close(fd);
		i++;
	}
	return (0);
}

