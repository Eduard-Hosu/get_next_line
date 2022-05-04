/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:28:52 by ehosu             #+#    #+#             */
/*   Updated: 2022/05/04 09:29:11 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_char(char *buffer, char c)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (&buffer[i]);
		i++;
	}
	return (NULL);
}

int	ft_copy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (size == 0)
	{
		while(src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		size--;
		while(i < size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (i);
}

char	*find_new_line(char *buffer, char *output)
{
	char	*tmp;
	int		copy_size;

	copy_size = (find_char(buffer, '\n') - buffer) + 1;
	tmp = (char *)malloc(copy_size + 1);
	if (!tmp)
		return (NULL);
	ft_copy(tmp, buffer, copy_size + 1);
	output = ft_realoc(output, tmp, 1, 1);
	ft_copy(buffer, &buffer[copy_size], 0);
	return (output);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_realoc(char *s1, char *s2, int free_s1, int free_s2)
{
	int		s1_len;
	int		s2_len;
	char	*output;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);

	output = (char *)malloc(s1_len + s2_len + 1);
	if (!output)
		return (NULL);
	ft_copy(output, s1, 0);
	ft_copy(&output[s1_len], s2, 0);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (output);
}

char	*handle_gnl(int fd, char *buffer, char *output)
{
	int	read_result;

	while (1)
	{
		if (buffer[0])
		{
			if (find_char(buffer, '\n'))
				return (find_new_line(buffer, output));
			output = ft_realoc(output, buffer, 1, 0);
		}
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result == -1 || (read_result == 0 && output[0] == '\0' ))
		{
			free(output);
			return(NULL);
		}
		buffer[read_result] = '\0';
		if (read_result == 0)
			return (output);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;

	if ((fd < 0) || BUFFER_SIZE <=0)
		return (NULL);
	output = (char *)malloc(BUFFER_SIZE + 1);
	if (!output)
		return (NULL);
	output[0] = '\0';
	return (handle_gnl(fd, buffer, output));
}
