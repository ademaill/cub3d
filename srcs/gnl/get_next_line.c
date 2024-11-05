/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:12:43 by ymarques          #+#    #+#             */
/*   Updated: 2024/09/13 15:38:32 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}

static void	*ft_calloc(int nmemb, int size)
{
	void	*p;
	int		tmp;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	tmp = nmemb * size;
	if (tmp / size != nmemb)
		return (NULL);
	p = (void *) malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	*read_fd(int fd, char *rest)
{
	char	*buffer;
	int		bytes_read;

	if (!rest)
		rest = ft_calloc(1, 1);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		rest = concat_buff(rest, buffer);
		if (have_nl(buffer))
			break ;
	}
	free(buffer);
	return (rest);
}

char	*clean_tmp(char *str)
{
	int		i;
	char	*clean_tmp;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	clean_tmp = (char *) malloc((i + 2) * sizeof(char));
	if (!clean_tmp)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		clean_tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		clean_tmp[i] = '\0';
	else
		clean_tmp[i] = '\n';
	clean_tmp[i + 1] = '\0';
	return (clean_tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = clean_tmp(buffer);
	if (!*line)
	{
		free(line);
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = restof_tmp(buffer);
	return (line);
}
