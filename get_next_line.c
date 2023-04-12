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


char *get_next_line(int fd)
{
    char        *buf;
    const char  *line;

    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
        return (NULL);
    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    
    read(fd, buf, BUFFER_SIZE);
    return (line);
}