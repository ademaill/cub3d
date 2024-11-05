/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:08:59 by ademaill          #+#    #+#             */
/*   Updated: 2024/11/04 16:07:53 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	wall_is_hit(double v_x, double v_y, t_data *data)
{
	int	x;
	int	y;

	if (v_x <= 0 || v_y <= 0)
		return (true);
	x = floor(v_x / TILE_SIZE);
	y = floor(v_y / TILE_SIZE);
	if (x >= data->map->width || y >= data->map->height
		|| x <= 0 || y <= 0)
		return (true);
	if (data->map->arr[y] && x <= (int)ft_strlen(data->map->arr[y]))
		if (data->map->arr[y][x] == '1')
			return (true);
	return (false);
}

void	*get_texture(t_data *data)
{
	data->ray->angle = nor_angle(data->ray->angle);
	if (data->ray->flag == 0)
	{
		if (data->ray->angle > M_PI / 2 && data->ray->angle < 3 * (M_PI / 2))
			return (data->we_img);
		else
			return (data->ea_img);
	}
	else
	{
		if (data->ray->angle > 0 && data->ray->angle < M_PI)
			return (data->so_img);
		else
			return (data->no_img);
	}
}

static void	draw_wall(t_data *data, int t_pix, int b_pix, int ray)
{
	int		texture_x;
	int		texture_y;
	int		y;
	double	wall_hit_x;
	double	wall_hit_y;

	y = 0;
	wall_hit_x = *data->player->px_x
		+ data->ray->distance * cos(data->ray->angle);
	wall_hit_y = *data->player->px_y
		+ data->ray->distance * sin(data->ray->angle);
	if (!data->ray->flag)
		texture_x = (int)(wall_hit_y) % TILE_SIZE * IMG_SIZE / TILE_SIZE;
	else
		texture_x = (int)(wall_hit_x) % TILE_SIZE * IMG_SIZE / TILE_SIZE;
	while (y < b_pix)
	{
		texture_y = (y - t_pix) * IMG_SIZE / (b_pix - t_pix);
		mlx_set_image_pixel(data->mlx, data->img, ray, y,
			mlx_get_image_pixel(data->mlx, get_texture(data),
				texture_x, texture_y));
		y++;
	}
}

static void	set_and_draw(t_data *data, int t_pix, int ray, int b_pix)
{
	int	y;

	y = 0;
	draw_wall(data, t_pix, b_pix, ray);
	while (y < t_pix)
	{
		mlx_set_image_pixel(data->mlx, data->img, ray,
			y, get_good_color(data, 1));
		y++;
	}
	y = b_pix;
	while (y < SCREEN_H)
	{
		mlx_set_image_pixel(data->mlx, data->img,
			ray, y, get_good_color(data, 2));
		y++;
	}
}

void	render_wall(t_data *data, int ray)
{
	int	wall_h;
	int	b_pix;
	int	t_pix;

	data->ray->distance *= cos(nor_angle(data->ray->angle
				- data->player->angle));
	wall_h = (TILE_SIZE / data->ray->distance)
		* ((SCREEN_W / 2) / tan(data->player->fov / 2));
	b_pix = (SCREEN_H / 2) + (wall_h / 2);
	t_pix = (SCREEN_H / 2) - (wall_h / 2);
	if (b_pix > SCREEN_H)
		b_pix = SCREEN_H;
	if (t_pix < 0)
		t_pix = 0;
	set_and_draw(data, t_pix, ray, b_pix);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
