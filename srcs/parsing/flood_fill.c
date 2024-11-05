/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:08:59 by ademaill          #+#    #+#             */
/*   Updated: 2024/10/29 11:51:00 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	flood_fill(t_data *data, int y, int x)
{
	if (data->map->height > 500 || data->map->width > 500)
		ft_error("Error,\nMap too big\n", data);
	if (y < 0 || x < 0 || !data->map->arr_cpy[y])
		return (-1);
	if (data->map->arr_cpy[y][x] == '\n'
		|| data->map->arr_cpy[y][x] == '\0' || data->map->arr_cpy[y][x] == '*')
		return (-1);
	if (data->map->arr_cpy[y][x] != '1')
	{
		data->map->arr_cpy[y][x] = '1';
		if (flood_fill(data, y + 1, x) == -1)
			return (-1);
		if (flood_fill(data, y - 1, x) == -1)
			return (-1);
		if (flood_fill(data, y, x + 1) == -1)
			return (-1);
		if (flood_fill(data, y, x - 1) == -1)
			return (-1);
	}
	return (0);
}
