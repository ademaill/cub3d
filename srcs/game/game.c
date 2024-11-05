/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:51:29 by ademaill          #+#    #+#             */
/*   Updated: 2024/10/29 10:55:21 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_exit(t_data *data)
{
	if (data->ea_img)
		mlx_destroy_image(data->mlx, data->ea_img);
	if (data->we_img)
		mlx_destroy_image(data->mlx, data->we_img);
	if (data->so_img)
		mlx_destroy_image(data->mlx, data->so_img);
	if (data->no_img)
		mlx_destroy_image(data->mlx, data->no_img);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_all(data);
	exit(0);
}

int	window_hook(int event, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (event == 0)
		ft_exit(data);
	return (0);
}

int	render_frame(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	if (data->mouse_lock == true)
		mlx_mouse_move(data->mlx, data->win, SCREEN_W / 2, SCREEN_H / 2);
	mlx_on_event(data->mlx, data->win, MLX_KEYDOWN, key_hook, data);
	mlx_on_event(data->mlx, data->win, MLX_MOUSEDOWN, mouse_hook, data);
	mlx_on_event(data->mlx, data->win, MLX_WINDOW_EVENT, window_hook, data);
	cast_rays(data);
	return (0);
}

int	game(t_data *data)
{
	int	height;
	int	width;

	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "Cub3D");
	if (!data->win)
		return (0);
	data->no_img = mlx_png_file_to_image(data->mlx,
			data->mapfile->no_text_path, &width, &height);
	data->so_img = mlx_png_file_to_image(data->mlx,
			data->mapfile->so_text_path, &width, &height);
	data->we_img = mlx_png_file_to_image(data->mlx,
			data->mapfile->we_text_path, &width, &height);
	data->ea_img = mlx_png_file_to_image(data->mlx,
			data->mapfile->ea_text_path, &width, &height);
	mlx_set_fps_goal(data->mlx, 80);
	mlx_mouse_hide();
	data->mouse_lock = true;
	mlx_loop_hook(data->mlx, render_frame, data);
	mlx_loop(data->mlx);
	return (0);
}
