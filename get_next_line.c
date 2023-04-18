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

char	*ft_line(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	str = ft_substr(buf, 0, i + 1);
	return (str);
}

char	*ft_rest(char *buf)
{
	int		i;
	size_t	len;
	char	*str;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	len = ft_strlen(buf);
	len = len - i;
	str = ft_substr(buf, (i + 1), len);
	free(buf);
	return (str);
}

char	*ft_read(int fd, char *buf)
{
	char	*aux;
	int		read_bytes;

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
			free(aux);
			return (NULL);
		}
		aux[read_bytes] = '\0';
		buf = ft_strjoin(buf, aux);
	}
	free(aux);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_line(buf);
	buf = ft_rest(buf);
	return (line);
}
/*
int	main(void)
{
    char    *line;
    int     fd;

    fd = open("pruebaa.txt", O_RDONLY);
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
            break ;
        }
        printf("%s", line);
        free(line);
    }
    printf("%s", line);
    free(line);
    close(fd);
    system("leaks -q a.out");
    return (0);
}*/
