#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*line;
	size_t	i;
	int	res;

	if (ac == 1)
	{
		fd = STDIN_FILENO;
//		fd = open("/dev/random", O_RDONLY);
		while ((res = get_next_line(fd, &line)) == 1)
		{
			printf("[ %d ] %s\n", res, line);
			free(line);
		}
		printf("[ %d ] %s\n", res, line);
		free(line);
	}
	else
	{
		i = 1;
		while (av[i])
		{
			fd = open(av[i], O_RDONLY);
			while ((res = get_next_line(fd, &line)) == 1)
			{
				printf("[ %d ] %s\n", res, line);
				free(line);
			}
			printf("[ %d ] %s\n", res, line);
			free(line);
			close(fd);
			i++;
		}
	}
	return (0);
}

