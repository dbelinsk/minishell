/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:30:17 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/27 18:32:12 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				get_next_line(const int fd, char **line);
size_t			gnl_strlen(const char *str);
char			*gnl_strdup(const char *s);
char			*gnl_strjoin(char const *s1, char const *s2);
char			*gnl_substr(char const *s, unsigned int start, size_t len);
void			gnl_strdel(char **str);

#endif
