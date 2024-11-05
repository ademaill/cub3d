/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:23:23 by ademaill          #+#    #+#             */
/*   Updated: 2024/10/02 14:29:03 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	mouse_hook(int button, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 3)
	{
		mlx_mouse_show();
		data->mouse_lock = false;
	}
	if (button == 1)
	{
		mlx_mouse_hide();
		data->mouse_lock = true;
	}
	return (0);
}
