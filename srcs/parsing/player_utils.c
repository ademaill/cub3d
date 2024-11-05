/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:26:04 by ymarques          #+#    #+#             */
/*   Updated: 2024/10/28 16:00:04 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_uniq_ply(t_data *data)
{
	int		i;
	int		j;
	int		ply_cnt;
	char	**arr;

	i = 0;
	arr = data->map->arr;
	ply_cnt = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'N' || arr[i][j] == 'S'
				|| arr[i][j] == 'E' || arr[i][j] == 'W')
				ply_cnt++;
			j++;
		}
		i++;
	}
	if (ply_cnt == 0 || ply_cnt > 1)
		return (false);
	return (true);
}

void	fill_player_angle(t_data *data, char c)
{
	if (c == 'N')
		data->player->angle = 3 * M_PI / 2;
	if (c == 'S')
		data->player->angle = M_PI / 2;
	if (c == 'E')
		data->player->angle = 2 * M_PI;
	if (c == 'W')
		data->player->angle = M_PI;
}

void	fill_player_pos(t_data *data)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	arr = data->map->arr;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if (arr[i][j] == 'N' || arr[i][j] == 'S'
				|| arr[i][j] == 'E' || arr[i][j] == 'W')
			{
				*data->player->x = j;
				*data->player->y = i;
				fill_player_angle(data, arr[i][j]);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
