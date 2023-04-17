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

char    *ft_line(char *buf)
{
    int     i;
    char    *str;

    i = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    str = malloc((i + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (buf[i] && buf[i] != '\n' )
    {
        str[i] = buf[i];
        i++;
    }
    if (buf[i] == '\n' || buf[i] == '\0')
    {
        str[i] = buf [i];
        i++;
    }
    str[i] = '\0';
    return(str);
}


char    *ft_rest(char *buf)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    if (!buf || buf[i] == '\0')
    {
        free(buf);
        return (NULL);
    }
    str = malloc((ft_strlen(buf) - i + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (buf[i])
        str[j++] = buf[i++];
    str[j] = '\0';
    free(buf);
    return (str);
}

char    *ft_read(int fd, char *buf)
{
    char    *aux;
    int     read_bytes;

    aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!aux)
        return (NULL);
    read_bytes = 1;
    while (!(ft_strchr(buf, '\n')) && (read_bytes != 0))
    {
        read_bytes = read(fd, aux, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(buf);
            return (NULL);
        }
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
/*     if (!line)
    {
        free (buf);
        return (NULL);
    } */
    buf = ft_rest(buf);
    if (!buf)
        return (NULL);
    return (line);
}

int main()
{
    char    *line;
    int     fd;
    fd = open("prueba.txt", O_RDONLY);
    if (fd == -1)
    {
        close(fd);
        return (0);
    }
    line = "";
    while (line != NULL)
    {
        line = get_next_line(fd);
        if (!line)
        {
            free (line);
            break;
        }
        printf("%s", line);
        free(line);
    }
    printf("%s", line);
    free(line);
    close(fd);
    //system("leaks -q a.out");
    return (0);
}