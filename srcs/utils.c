/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <yann.marques@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:26:04 by ymarques          #+#    #+#             */
/*   Updated: 2024/10/29 14:42:56 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_error(char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	free_all(data);
	exit(0);
}
