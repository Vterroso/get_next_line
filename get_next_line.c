/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterroso <vterroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:14:30 by vterroso          #+#    #+#             */
/*   Updated: 2023/04/11 19:19:25 by vterroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *ft_line(char *buf)
{
    int     i;
    char    *str;

    i = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    str = malloc((i + 2) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (buf[i] && buf[i] != '\n')
    {
        str[i] = buf[i];
        i++;
    }
    str[i] = '\0';
    return(str);
}


static char    *ft_rest(char *buf)
{
    int     i;
    char    *str;

    i = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    str = malloc((ft_strlen(buf) - i + 1) * sizeof(char));
    if (!str)
        return (NULL);
    while (buf[i])
    {
        str[i] = buf[i];
        i++;
    }
    str[i] = '\0';
    return(str);
}

static char    *ft_read(int fd, char *buf)
{
    char    *aux;
    int     read_bytes;

    read_bytes = 1;
    aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!aux)
        return (NULL);
    while (!ft_strchr(buf, '\n') && (read_bytes != 0))
    {
        read_bytes = read(fd, aux, BUFFER_SIZE);
        aux[read_bytes] = '\0';
        buf = ft_strjoin(buf, aux);  
    }
    free(aux);
    return (buf);
    }
    

char    *get_next_line(int fd)
{
    static char *buf;
    char        *line;


    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = ft_read(fd, buf);
    if (!buf)
        return (NULL);
    line = ft_line(buf);
    buf = ft_rest(buf);
    return (line);
}

int main(void)
{
    int fd;
    char *line;

    fd = open("/Users/vterroso/Desktop/prueba.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    return (0);
}