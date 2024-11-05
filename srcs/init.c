/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:48:45 by ademaill          #+#    #+#             */
/*   Updated: 2024/10/29 14:42:13 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	init(t_data *data)
{
	if (!data)
		return (-1);
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (-1);
	data->mapfile = ft_calloc(1, sizeof(t_mapfile));
	if (!data->mapfile)
		return (-1);
	data->player = ft_calloc(1, sizeof(t_player));
	data->player->px_x = ft_calloc(1, sizeof(int));
	data->player->px_y = ft_calloc(1, sizeof(int));
	data->player->x = ft_calloc(1, sizeof(int));
	data->player->y = ft_calloc(1, sizeof(int));
	data->player->angle = 2 * M_PI;
	data->player->fov = (FOV * M_PI) / 180;
	if (!data->player)
		return (-1);
	data->ray = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (-1);
	return (0);
}
