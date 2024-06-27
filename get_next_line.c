#include "get_next_line.h"

 char *get_remain(char *next_line)
{
    int i;
    int j;
    int start;
    char *remain;

    i = 0;
    while(next_line[i] != '\0' && next_line[i] != '\n')
        i++;
    if(!next_line[i])
        return (NULL);
    j = i + 1;
    start = j;
    i = 0;
    while(next_line[j])
    {
        i++;
        j++;
    }
    remain = ft_calloc(i + 1, sizeof(char));
    i = 0;
    while(next_line[start])
    {
        remain[i] = next_line[start];
        i++;
        start++;
    }
    return (remain);
}

char *get_line(char *next_line)
{
    int i;
    char *line;

    i = 0;
    while(next_line[i] != '\0' && next_line[i] != '\n')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while(next_line[i] != '\0' && next_line[i] != '\n')
    {
        line[i] = next_line[i];
        i++;
    }
    if(next_line[i] && next_line[i] == '\n')
        line[i] = '\n';
    return (line);
}

char *read_line(int fd, char *buffer, char *next_line)
{
    int bytes_read;
    char *tmp;

    bytes_read = 1;
    while(ft_strchr(buffer, '\n') == NULL)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if((!*buffer && !*next_line && bytes_read == 0) || bytes_read < 0)
        {
            free(next_line);
            return (NULL);
        }
        if(bytes_read == 0)
        {
            tmp = next_line;
            next_line = ft_strdup(next_line);
            free(tmp);
            break ;
        }
        tmp = next_line;
        next_line = ft_strjoin(tmp, buffer);
        free(tmp);
    }
    return (next_line);
}

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    static char *next_line;
    char *tmp;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

    if(next_line == 0)
        next_line = ft_strdup("");

    next_line = read_line(fd, buffer, next_line);

    if(next_line == NULL)
        return (free(buffer), NULL);

    tmp = next_line;
    line = get_line(next_line);
    next_line = get_remain(tmp);
    free(tmp);
    return (free(buffer), line);
}

/* #include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file", O_RDWR);
    if(fd < 0)
        printf("error\n");
    
    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    
    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    return (0);
} */

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int i;
	int fd;
	char *res;

	i = 0;

	fd = open("teste.txt", O_RDWR);
	//1
	res = get_next_line(fd);
	printf("1: %s", res);
	free(res);
	//2
	res = get_next_line(fd);
	printf("1: %s", res);
	free(res);

	close(fd);
	fd = open("teste.txt", O_RDWR);
	//1
	res = get_next_line(fd);
	printf("1: %s", res);
	free(res);
	//2
	res = get_next_line(fd);
	printf("2: %s", res);
	free(res);
	//3
	res = get_next_line(fd);
	printf("3: %s", res);
	free(res);
	//4
	res = get_next_line(fd);
	printf("4: %s", res);
	free(res);
	//5
	res = get_next_line(fd);
	printf("5: %s", res);
	free(res);
	//6
	res = get_next_line(fd);
	printf("6: %s", res);
	free(res);
} */