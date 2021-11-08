#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

static char	*ft_realloc(char *line, char c)
{
	char	*buf;
	int		i;

	buf = NULL;
	i = 0;
	while (line[i])
		i++;
	buf = malloc(sizeof(char) * (i + 2));
	if (buf == NULL)
		return (NULL);
	buf[i] = c;
	buf[i + 1] = '\0';
	while (i-- > 0)
		buf[i] = line[i];
	free(line);
	line = NULL;
	return (buf);
}

static int	ft_rec_gnl(int fd, char **line)
{
	int		ret;
	char	c;

	c = 0;
	ret = read(fd, &c, 1);
	if (ret == -1)
		return (-1);
	else if (c == '\n')
		return (1);
	else if (ret == 0)
		return (0);
	else
	{
		*line = ft_realloc(*line, c);
		if (*line == NULL)
			return (-1);
		return (ft_rec_gnl(fd, line));
	}
}

int	ft_gnl(int	fd, char **line)
{
	if (fd == -1)
		return (-1);
	else
	{
		*line = malloc(sizeof(char));
		if (*line == NULL)
			return (-1);
		*line[0] = '\0';
		return (ft_rec_gnl(fd, line));
	}
}

int	main()
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	close(fd);
	if (line)
		free(line);
	return (0);
}
