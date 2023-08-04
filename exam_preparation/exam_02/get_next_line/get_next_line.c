#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int i;
	int rd;
	char c;
	char *buffer = malloc(1000);

	rd = 0;
	i = 0;
	if (BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0 )
	{
		buffer[i++] = c;
		if (c == '\n')
			break;
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
