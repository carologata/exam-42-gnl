
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_remain(char *next_line);
char *get_line(char *next_line);
char *read_line(int fd, char *buffer, char *next_line);
char *get_next_line(int fd);

void *ft_calloc(size_t nmemb, size_t size);
char *ft_strchr(char *str, unsigned char c);
int ft_strlen(char *str);
char *ft_strjoin(char *str1, char *str2);
char *ft_strdup(char *str);

#endif