/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:32:07 by ehosu             #+#    #+#             */
/*   Updated: 2021/08/11 12:29:42 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Clear a string
 * @param s - string
 * @param n - number of steps
 *
 * @return void
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

/**
 * Alocates memory in the HEAP
 * @param nitems - number of items
 * @param size - size of memory
 *
 * @return c - address to that memory in the HEAP
*/
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*c;

	c = malloc(nitems * size);
	if (c == NULL)
		return (NULL);
	ft_bzero(c, nitems * size);
	return (c);
}

/**
 * Move a certain number memory from source to destination
 * @param str1 - destination
 * @param str2 - source
 * @param n - size
 *
 * @return str1 - destination
*/
void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*dest;
	char		*source;
	char		*temp;

	dest = (char *)str1;
	source = (char *)str2;
	temp = (char *)malloc(n + 1);
	i = 0;
	while (i < n)
	{
		temp[i] = source[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest[i] = temp[i];
		i++;
	}
	free(temp);
	return (str1);
}

/**
 * Copy a certain length memory from source to destination
 * @param dest - destination
 * @param src - source
 * @param len - size
 *
 * @return str1 - destination
*/
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/**
 * Length of a string
 * @param str - string
 *
 * @return i - length of string
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
	{
		return (0);
	}
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
