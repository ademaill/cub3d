/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:26:04 by ymarques          #+#    #+#             */
/*   Updated: 2024/10/29 14:28:27 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_file_lines(t_mapfile *mapfile)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(mapfile->path, O_RDONLY, 0764);
	if (fd == -1)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	mapfile->c_l = i;
	close(fd);
	return (1);
}

int	ft_isspace(char c)
{
	return ((c >= 8 && c <= 13) || c == ' ');
}

int	line_is_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	strlen_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

t_rgb	*str_to_rgb(char *str, t_data *data)
{
	t_rgb	*color;
	char	**a;

	color = ft_calloc(1, sizeof(t_rgb));
	if (!str || !color)
		return (NULL);
	a = ft_split(&str[1], ',');
	if (!a[0] || !a[1] || !a[2])
	{
		free_arr(a);
		free(color);
		ft_error("Error.\nYou need to put 3 values\n", data);
	}
	if (ft_atoi(a[0]) < 0 || ft_atoi(a[1]) < 0 || ft_atoi(a[2]) < 0
		|| ft_atoi(a[0]) > 255 || ft_atoi(a[1]) > 255 || ft_atoi(a[2]) > 255)
	{
		free_arr(a);
		free(color);
		ft_error("Error.\nColor needs to be an int between 0 and 255\n", data);
	}
	color->red = ft_atoi(a[0]);
	color->green = ft_atoi(a[1]);
	color->blue = ft_atoi(a[2]);
	free_arr(a);
	return (color);
}
