/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:19:55 by ademaill          #+#    #+#             */
/*   Updated: 2024/10/16 10:36:44 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	move_player(t_data *data, int dir)
{
	double	move_x;
	double	move_y;
	double	new_px_x;
	double	new_px_y;

	new_px_x = *data->player->px_x;
	new_px_y = *data->player->px_y;
	move_x = cos(data->player->angle) * MOOVE_SPEED;
	move_y = sin(data->player->angle) * MOOVE_SPEED;
	if (dir == 1)
	{
		new_px_x += move_x + 1;
		new_px_y += move_y + 1;
	}
	else if (dir == -1)
	{
		new_px_x -= move_x - 1;
		new_px_y -= move_y - 1;
	}
	if (!check_pos_x(data, new_px_x, *data->player->px_x))
		*data->player->px_x = new_px_x;
	if (!check_pos_y(data, new_px_y, *data->player->px_y))
		*data->player->px_y = new_px_y;
}

static void	strafe_player(t_data *data, int dir)
{
	double	move_x;
	double	move_y;
	double	new_px_x;
	double	new_px_y;

	new_px_x = *data->player->px_x;
	new_px_y = *data->player->px_y;
	move_x = cos(data->player->angle + M_PI / 2) * MOOVE_SPEED;
	move_y = sin(data->player->angle + M_PI / 2) * MOOVE_SPEED;
	if (dir == 1)
	{
		new_px_x += move_x + 1;
		new_px_y += move_y + 1;
	}
	else if (dir == -1)
	{
		new_px_x -= move_x - 1;
		new_px_y -= move_y - 1;
	}
	if (!check_pos_x(data, new_px_x, *data->player->px_x))
		*data->player->px_x = new_px_x;
	if (!check_pos_y(data, new_px_y, *data->player->px_y))
		*data->player->px_y = new_px_y;
}

static void	rotate_player(t_data *data, int dir)
{
	if (dir == 1)
		data->player->angle -= ROTATE_SPEED;
	else if (dir == -1)
		data->player->angle += ROTATE_SPEED;
	if (data->player->angle < 0)
		data->player->angle += 2 * M_PI;
	if (data->player->angle >= 2 * M_PI)
		data->player->angle -= 2 * M_PI;
}

int	key_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 41)
		ft_exit(data);
	if (key == UP)
		move_player(data, 1);
	if (key == DOWN)
		move_player(data, -1);
	if (key == RIGHT)
		strafe_player(data, -1);
	if (key == LEFT)
		strafe_player(data, 1);
	if (key == RIGHT_ROTATE)
		rotate_player(data, 1);
	if (key == LEFT_ROTATE)
		rotate_player(data, -1);
	return (0);
}
