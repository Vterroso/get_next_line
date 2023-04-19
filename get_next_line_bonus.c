/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterroso <vterroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:22:37 by vterroso          #+#    #+#             */
/*   Updated: 2023/04/19 15:31:54 by vterroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buf[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buf[fd] = ft_read(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = ft_line(buf[fd]);
	buf[fd] = ft_rest(buf[fd]);
	return (line);
}
/*
int	main(void)
{
    char    *line1;
	char    *line2;
	char    *line3;
	
    int     fd1;
	int		fd2;
	int		fd3;
	

    fd1 = open("prueba.txt", O_RDONLY);
	fd2 = open("prueba2.txt", O_RDONLY);
	fd3 = open("prueba3.txt", O_RDONLY);
    if (fd1 == -1)
    {
        close(fd1);
        return (0);
    }
    line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
    
	printf("%s", line1);
	printf("%s", line2);
	printf("%s", line3);

	line1 = get_next_line
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
    
	printf("%s", line1);
	printf("%s", line2);
	printf("%s", line3);

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
    
	printf("%s", line1);
	printf("%s", line2);
	printf("%s", line3);
	
    free(line1);
	free(line2);
	free(line3);
    close(fd1);
	close(fd2);
	close(fd3);
    system("leaks -q a.out");
    return (0);
}*/
