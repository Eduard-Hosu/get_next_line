/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:01:22 by ehosu             #+#    #+#             */
/*   Updated: 2022/05/04 09:29:22 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*find_char(char *buffer, char c);
int		ft_copy(char *dst, char *src, int size);
char	*find_new_line(char *buffer, char *output);
int		ft_strlen(char *str);
char	*ft_realoc(char *s1, char *s2, int free_s1, int free_s2);
char	*handle_gnl(int fd, char *buffer, char *output);
char	*get_next_line(int fd);

#endif