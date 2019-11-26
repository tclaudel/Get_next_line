#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdlib.h"
#include "unistd.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "get_next_line.h"

int			main(int ac, char **av)
{
	int		fd;
    int     ret;
	char	*line;
    int     count = 0;

	line = NULL;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
        dprintf(1, "%d | %s\n", ret, line);
        free(line);
        count++;
	}
	dprintf(1, "%d | %s\n", ret, line);
	free(line);
    printf("\n<-------------------------------->\n\n\tline readed : %d\n\n<-------------------------------->\n", count);
	close(fd);
	fclose(stdout);
}
