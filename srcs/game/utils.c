/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:07:01 by ademaill          #+#    #+#             */
/*   Updated: 2024/10/16 10:51:03 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_good_color(t_data *data, int pos)
{
	int	color;
	int	aplha;

	aplha = 255;
	if (pos == 1)
	{
		color = (aplha << 24) | (data->mapfile->c_color->red << 16)
			| (data->mapfile->c_color->green << 8)
			| data->mapfile->c_color->blue;
		return (color);
	}
	else if (pos == 2)
	{
		color = (aplha << 24) | (data->mapfile->f_color->red << 16)
			| (data->mapfile->f_color->green << 8)
			| data->mapfile->f_color->blue;
		return (color);
	}
	return (0);
}

bool	check_pos_x(t_data *data, double new_pos, double old_pos)
{
	int	map_px;
	int	map_py;
	int	buffer;

	map_px = (int)(*data->player->px_x / TILE_SIZE);
	map_py = (int)(*data->player->px_y / TILE_SIZE);
	buffer = 200;
	if (new_pos >= old_pos)
	{
		map_px = (int)((new_pos + buffer) / TILE_SIZE);
		if (data->map->arr[map_py][map_px] == '1')
			return (true);
		return (false);
	}
	else
	{
		map_px = (int)((new_pos - buffer) / TILE_SIZE);
		if (data->map->arr[map_py][map_px] == '1')
			return (true);
		return (false);
	}
	return (true);
}

bool	check_pos_y(t_data *data, double new_pos, double old_pos)
{
	int	map_px;
	int	map_py;
	int	buffer;

	map_px = (int)(*data->player->px_x / TILE_SIZE);
	map_py = (int)(*data->player->px_y / TILE_SIZE);
	buffer = TILE_SIZE / 4;
	if (new_pos >= old_pos)
	{
		map_py = (int)((new_pos + buffer) / TILE_SIZE);
		if (data->map->arr[map_py][map_px] == '1')
			return (true);
		return (false);
	}
	else
	{
		map_py = (int)((new_pos - buffer) / TILE_SIZE);
		if (data->map->arr[map_py][map_px] == '1')
			return (true);
		return (false);
	}
	return (true);
}
