#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	(void)av;
	int	fd;
	char	*line;

	if (ac == 1)
	{
		fd = -1;
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
			free(line);
		}
		free(line);
	}
	return (0);
}

