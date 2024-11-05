/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:31:58 by ademaill          #+#    #+#             */
/*   Updated: 2024/11/05 12:20:21 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_name(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (ft_strlen(str) < 4 || (ft_strlen(str) >= 4
			&& (str[i - 1] != 'b' || str[i - 2] != 'u'
				|| str[i - 3] != 'c' || str[i - 4] != '.')))
	{
		ft_error("Error\nmap need to be .cub\n", data);
		return (-1);
	}
	return (1);
}

static int	check_png(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 4)
		return (0);
	if (str[i - 1] == 'g' && str[i - 2] == 'n'
		&& str[i - 3] == 'p' && str[i - 4] == '.')
		return (1);
	return (0);
}

char	*check_readable(char *line, t_data *data)
{
	if (open(&line[2], O_RDONLY, 0777) >= 0 && check_png(&line[2]))
	{
		data->mapfile->param_count ++;
		return (ft_strdup(&line[2]));
	}
	ft_error("Error\nTexture is not readable\n", data);
	return (NULL);
}
