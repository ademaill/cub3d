/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:48:15 by ymarques          #+#    #+#             */
/*   Updated: 2024/10/28 17:07:48 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	free_content(t_data *data)
{
	int	i;

	i = 0;
	if (data->mapfile->content && data->mapfile->content[i])
	{
		while (data->mapfile->content[i])
		{
			free(data->mapfile->content[i]);
			i++;
		}
		free(data->mapfile->content);
	}
}

static void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->arr)
	{
		while (data->map->arr[i])
		{
			free(data->map->arr[i]);
			i++;
		}
		free(data->map->arr[i]);
		free(data->map->arr);
	}
	i = 0;
	if (data->map->arr_cpy)
	{
		while (data->map->arr_cpy[i])
		{
			free(data->map->arr_cpy[i]);
			i++;
		}
		free(data->map->arr_cpy[i]);
		free(data->map->arr_cpy);
	}
}

static void	free_data(t_data *data)
{
	free(data->player->px_x);
	free(data->player->px_y);
	free(data->player->x);
	free(data->player->y);
	free(data->player);
	free(data->map);
	free(data->ray);
	if (data->mapfile->no_text_path)
		free(data->mapfile->no_text_path);
	if (data->mapfile->so_text_path)
		free(data->mapfile->so_text_path);
	if (data->mapfile->we_text_path)
		free(data->mapfile->we_text_path);
	if (data->mapfile->ea_text_path)
		free(data->mapfile->ea_text_path);
	if (data->mapfile->f_color)
		free(data->mapfile->f_color);
	if (data->mapfile->c_color)
		free(data->mapfile->c_color);
	free(data->mapfile);
}

void	free_all(t_data *data)
{
	if (data->mapfile->content)
		free_content(data);
	if (data->map->arr)
		free_map(data);
	if (data)
		free_data(data);
	if (data)
		free(data);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr && arr[i])
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}
