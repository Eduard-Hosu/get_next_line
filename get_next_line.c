/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:38:10 by ehosu             #+#    #+#             */
/*   Updated: 2021/08/10 14:53:58 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/**
 * Join 2 strings in to one
 * @param s1 - string
 * @param s2 - string
 * 
 * @return	string
*/
static char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	total_l;
	unsigned int	prefix_l;
	unsigned int	sufix_l;
	char			*result;

	prefix_l = ft_strlen(s1);
	sufix_l = ft_strlen(s2);
	total_l = prefix_l + sufix_l;
	result = (char *)malloc(total_l + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, prefix_l);
	ft_memcpy(result + prefix_l, s2, sufix_l);
	free((char *)s1);
	result[total_l] = '\0';
	return (result);
}

/**
 * Check if there is \n or \o in the given string
 * @param str
 * 
 * @return	the specific position in the sting
*/
static char	*ft_strrchr(const char *str)
{
	char	*s;
	int		len;

	len = 0;
	s = (char *)str;
	while (s[len])
	{
		if (s[len] == '\n' || s[len] == '\0')
			return (&s[len]);
		len++;
	}
	return (NULL);
}

/**
 * If in the given string it's a \n or \o return what's until then
 * second part move it in front and clean the remaining space
 * @param buff 
 *
 * @return line_to_return 
*/
static	char	*is_end_line(char *buff)
{
	size_t	i;
	size_t	j;
	char	*line_to_return;

	i = 0;
	j = 1;
	while (buff[i])
	{
		if (buff[i] == '\n' || buff[i] == '\0')
		{
			line_to_return = (char *)ft_calloc(j + 1, sizeof(char));
			if (line_to_return == NULL)
				return (NULL);
			ft_memcpy(line_to_return, buff, j);
			if (BUFFER_SIZE == j)
				ft_bzero(buff, BUFFER_SIZE);
			ft_memmove(buff, buff + j, BUFFER_SIZE - j);
			ft_bzero(&buff[BUFFER_SIZE - j], j);
			return (line_to_return);
		}
		i++;
		j++;
	}
	return (NULL);
}

/**
 * main logic in get the line from a file
 * if there is nothing left in the buff-er read again from file
 * until is eof. If in the given buff-er is not \n then just store it and join it
 * to temp_buff until you find \n and then just return it
 * @param check - read() successful
 * @param buff - static variable from where to extract
 * @param fd - file
 *
 * @return line including \n from a file 
*/
static	char	*line_to_be_returned(int check, char *buff, int fd)
{
	char	*temp_buff;
	char	*temp_adress;

	if (check != 0)
		temp_buff = (char *)ft_calloc(1, sizeof(char));
	while (check > 0)
	{
		if (ft_strrchr(buff) == NULL)
			temp_buff = ft_strjoin(temp_buff, buff);
		else
		{
			temp_adress = is_end_line(buff);
			temp_buff = ft_strjoin(temp_buff, temp_adress);
			free(temp_adress);
			return (temp_buff);
		}
		check = read(fd, buff, BUFFER_SIZE);
		if (check == 0 && ft_strrchr(buff) == NULL)
		{
			ft_bzero(buff, BUFFER_SIZE + 1);
			return (temp_buff);
		}
		buff[check] = '\0';
	}
	return (NULL);
}

/**
 * mail function to be called in main.c
 * @param fd - file
 *
 * @return line_to_retun()
*/
char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			check;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!buff[0])
	{
		check = read(fd, buff, BUFFER_SIZE);
		buff[check] = '\0';
	}
	else
		check = 1;
	return (line_to_be_returned(check, buff, fd));
}
