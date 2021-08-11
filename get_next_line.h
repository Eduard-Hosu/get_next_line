/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:27:05 by ehosu             #+#    #+#             */
/*   Updated: 2021/08/10 16:00:16 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t len);

#endif