/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:26:04 by ymarques          #+#    #+#             */
/*   Updated: 2024/10/29 14:17:19 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	fill_map(t_data *data)
{
	int		i;
	int		j;
	char	*line;

	if (extract_file_content(data) == -1)
		return (-1);
	i = data->mapfile->i_mstart;
	j = data->mapfile->i_mend;
	data->map->height = j - i;
	data->map->arr = ft_calloc((j - i) + 1, sizeof(char *));
	data->map->arr_cpy = ft_calloc((j - i) + 1, sizeof(char *));
	if (!data->map->arr || !data->map->arr_cpy)
		return (-1);
	j = 0;
	data->map->width = 0;
	while (data->mapfile->content[i])
	{
		line = data->mapfile->content[i++];
		if (strlen_new_line(line) > data->map->width)
			data->map->width = strlen_new_line(line);
		data->map->arr[j++] = ft_strdup(line);
	}
	return (1);
}

char	*transform_map_line(t_data *data, char *line)
{
	char	*new_line;
	bool	eof;
	int		i;

	i = 0;
	eof = false;
	new_line = ft_calloc(data->map->width + 2, sizeof(char));
	while (i < data->map->width)
	{
		if (!eof && line[i] && line[i] != '\n')
		{
			if (ft_isspace(line[i]))
				new_line[i] = '*';
			else
				new_line[i] = line[i];
		}
		else
			eof = true;
		if (eof)
			new_line[i] = '*';
		i++;
	}
	new_line[data->map->width] = '\n';
	return (new_line);
}

int	normalize_map(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (data->map->arr[i])
	{
		line = data->map->arr[i];
		data->map->arr[i] = transform_map_line(data, line);
		data->map->arr_cpy[i] = transform_map_line(data, line);
		free(line);
		i++;
	}
	return (1);
}

int	check_forbid_char(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (data->map->arr[i])
	{
		while (data->map->arr[i][j])
		{
			c = data->map->arr[i][j];
			if (c != '0' && c != '1' && c != 'N' && c != 'E'
				&& c != 'W' && c != 'S' && !ft_isspace(c))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	parse_map(t_data *data)
{
	if (fill_map(data) == -1)
	{
		ft_error("Error,\nInvalid description of map\n", data);
		return (-1);
	}
	if (!is_uniq_ply(data))
	{
		ft_error("Error\nYou need to have one player\n", data);
		return (-1);
	}
	if (!check_forbid_char(data))
	{
		ft_error("Error\nForbidden caractere\n", data);
		return (-1);
	}
	fill_player_pos(data);
	normalize_map(data);
	if (flood_fill(data, *data->player->y, *data->player->x) == -1)
	{
		ft_error("Error\nInvalid map, is not closed\n", data);
		return (-1);
	}
	*data->player->px_x = *data->player->x * TILE_SIZE + TILE_SIZE / 2;
	*data->player->px_y = *data->player->y * TILE_SIZE + TILE_SIZE / 2;
	return (1);
}
