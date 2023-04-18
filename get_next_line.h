/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterroso <vterroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:16:02 by vterroso          #+#    #+#             */
/*   Updated: 2023/04/11 16:33:50 by vterroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 42
#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);
int 	ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_line(char *buf);
char    *get_next_line(int fd);
char    *ft_rest(char *buf);
char    *ft_read(int fd, char *buf);
char	*ft_substr(char *s, unsigned int start, size_t len);


#endif 