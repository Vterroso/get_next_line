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

char    *get_next_line(int fd)
{
    static char *buf;
    /*char        *line;*/
    char        *aux;
    int         readbytes;

    readbytes = 1;
    aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!aux)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while ((ft_strchr(buf, '\n') == NULL) && (readbytes != 0))
    {
        readbytes = read(fd, aux, BUFFER_SIZE);
        buf[readbytes] = '\0';
        buf = ft_strjoin(buf, aux);
        
    }
    return (ft_strdup(buf));
    }

int main(void)
{
    int fd;
    char *line;

    fd = open("/Users/vterroso/Desktop/prueba.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("1%s\n", line);
    line = get_next_line(fd);
    printf("2%s\n", line);
    line = get_next_line(fd);
    printf("3%s*\n", line);
    close(fd);
    return (0);
}