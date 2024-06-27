#include "get_next_line.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    size_t i;
    size_t total_size;
    size_t size_max;
    void *r;
    unsigned char *str;

    total_size = nmemb * size;

    if(size == 0 || nmemb == 0)
        return (malloc(0));
    
    size_max = -1;
    if(size != 0 && (nmemb >= size_max / size))
        return (NULL);
    
    r = malloc(total_size);
    str = (unsigned char *)r;

    i = 0;
    while(i < total_size)
    {
        str[i] = 0;
        i++;
    }
    return (str);
}

char *ft_strchr(char *str, unsigned char c)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == c)
            return (&str[i+1]);
        i++;
    }
    if(str[i] == c)
        return (&str[i]);
    return (NULL);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *str1, char *str2)
{
    int i;
    int j;
    char *str;
    int len1;
    int len2;

    if(str1 == NULL || str2 == NULL)
        return (NULL);

    len1 = ft_strlen(str1);
    len2 = ft_strlen(str2);
    str = malloc(len1 + len2 + 1);

    i = 0;
    j = 0;
    while(i < len1)
    {
        str[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while(i < len2)
    {
        str[j] = str2[i];
        i++;
        j++;
    }
    str[j] = '\0';
    return (str);
}

char *ft_strdup(char *str)
{
    int i;
    int len;
    char *strdup;

    if(str == NULL)
        return (NULL);

    len = ft_strlen(str);
    strdup = malloc(len + 1);

    i = 0;
    while(str[i])
    {
        strdup[i] = str[i];
        i++;
    }
    strdup[i] = '\0';
    return (strdup);
}
