/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:10:13 by ymarques          #+#    #+#             */
/*   Updated: 2024/10/29 14:05:49 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static double	get_v_distance(t_data *data, double ray_angle)
{
	double	x_step;
	double	y_step;
	double	dx;
	double	dy;
	int		d_pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(ray_angle);
	dx = floor(*data->player->px_x / TILE_SIZE) * TILE_SIZE;
	d_pixel = inter_check(ray_angle, &dx, false);
	dy = *data->player->px_y + (dx - *data->player->px_x) * tan(ray_angle);
	set_xstep_sign(ray_angle, &x_step);
	set_ystep_sign(ray_angle, &y_step);
	while (!wall_is_hit(dx - d_pixel, dy, data))
	{
		dx += x_step;
		dy += y_step;
	}
	return (sqrt(pow(dx - *data->player->px_x, 2)
			+ pow(dy - *data->player->px_y, 2)));
}

static double	get_h_distance(t_data *data, double ray_angle)
{
	double	x_step;
	double	y_step;
	double	dx;
	double	dy;
	int		d_pixel;

	x_step = TILE_SIZE / tan(ray_angle);
	y_step = TILE_SIZE;
	dy = floor(*data->player->px_y / TILE_SIZE) * TILE_SIZE;
	d_pixel = inter_check(ray_angle, &dy, true);
	dx = *data->player->px_x + (dy - *data->player->px_y) / tan(ray_angle);
	set_xstep_sign(ray_angle, &x_step);
	set_ystep_sign(ray_angle, &y_step);
	while (!wall_is_hit(dx, dy - d_pixel, data))
	{
		dx += x_step;
		dy += y_step;
	}
	return (sqrt(pow(dx - *data->player->px_x, 2)
			+ pow(dy - *data->player->px_y, 2)));
}

int	cast_rays(t_data *data)
{
	int		ray;
	double	h_distance;
	double	v_distance;

	ray = 0;
	data->ray->angle = data->player->angle - (data->player->fov / 2);
	while (ray < SCREEN_W)
	{
		data->ray->flag = 0;
		v_distance = get_v_distance(data, nor_angle(data->ray->angle));
		h_distance = get_h_distance(data, nor_angle(data->ray->angle));
		if (v_distance == 0 || h_distance == 0)
			return (-1);
		if (v_distance <= h_distance)
			data->ray->distance = v_distance;
		else
		{
			data->ray->flag = 1;
			data->ray->distance = h_distance;
		}
		render_wall(data, ray++);
		data->ray->angle = nor_angle(data->ray->angle
				+ data->player->fov / SCREEN_W);
	}
	return (0);
}
