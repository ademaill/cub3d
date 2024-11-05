/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:10:13 by ymarques          #+#    #+#             */
/*   Updated: 2024/10/02 14:40:51 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	nor_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	set_ystep_sign(double angle, double *y_step)
{
	if (angle > 0 && angle < M_PI)
	{
		if (*y_step < 0)
			*y_step *= -1;
	}
	else
	{
		if (*y_step > 0)
			*y_step *= -1;
	}
}

void	set_xstep_sign(double angle, double *x_step)
{
	if (!(angle > M_PI / 2 && angle < (3 * M_PI) / 2))
	{
		if (*x_step < 0)
			*x_step *= -1;
	}
	else
	{
		if (*x_step > 0)
			*x_step *= -1;
	}
}

int	inter_check(double angle, double *delta, bool h_or_v)
{
	if (h_or_v)
	{
		if (angle > 0 && angle < M_PI)
		{
			*delta += TILE_SIZE;
			return (-1);
		}
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < (3 * M_PI) / 2))
		{
			*delta += TILE_SIZE;
			return (-1);
		}
	}
	return (1);
}
