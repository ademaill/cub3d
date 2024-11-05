/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:31:58 by ademaill          #+#    #+#             */
/*   Updated: 2024/11/05 14:33:47 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	remove_spaces(char *line)
{
	char	**line_cp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line_cp = &line;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
		{
			line[j] = line[i];
			j++;
		}
		i++;
	}
	line[j] = '\0';
	line = ft_strdup(line);
	free(*line_cp);
}

int	fill_metadata(char *line, t_data *data)
{
	remove_spaces(line);
	if (ft_strncmp(line, "NO", 2) == 0)
		data->mapfile->no_text_path = check_readable(line, data);
	else if (ft_strncmp(line, "SO", 2) == 0)
		data->mapfile->so_text_path = check_readable(line, data);
	else if (ft_strncmp(line, "WE", 2) == 0)
		data->mapfile->we_text_path = check_readable(line, data);
	else if (ft_strncmp(line, "EA", 2) == 0)
		data->mapfile->ea_text_path = check_readable(line, data);
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		data->mapfile->f_color = str_to_rgb(line, data);
		data->mapfile->param_count ++;
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		data->mapfile->c_color = str_to_rgb(line, data);
		data->mapfile->param_count ++;
	}
	else 
		data->mapfile->param_count++;
	return (1);
}

int	process_metadata(t_data *data)
{
	char	*line;
	int		i;
	bool	end_meta;

	i = -1;
	end_meta = false;
	while (data->mapfile->content[++i])
	{
		line = data->mapfile->content[i];
		if (line_is_space(line))
			continue ;
		if (!end_meta)
			fill_metadata(line, data);
		else if (data->mapfile->i_mstart == 0)
			data->mapfile->i_mstart = i;
		if (data->mapfile->c_color && data->mapfile->f_color
			&& data->mapfile->ea_text_path
			&& data->mapfile->we_text_path && data->mapfile->so_text_path
			&& data->mapfile->no_text_path && data->mapfile->param_count == 6)
				end_meta = true;
	}
	if (data->mapfile->i_mstart == 0)
		return (-1);
	data->mapfile->i_mend = i;
	return (1);
}

int	extract_file_content(t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	if (get_file_lines(data->mapfile) == -1)
		return (-1);
	data->mapfile->content = ft_calloc(data->mapfile->c_l + 1, sizeof(char *));
	if (!data->mapfile->content)
		return (-1);
	fd = open(data->mapfile->path, O_RDONLY, 0764);
	if (fd == -1)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		data->mapfile->content[i++] = line;
		line = get_next_line(fd);
		if (line && ft_strlen(line) > 2)
			line[ft_strlen(line) - 1] = '\0';
	}
	close(fd);
	if (process_metadata(data) == -1)
		return (-1);
	return (1);
}

int	parse(int argc, char **argv, t_data *data)
{
	if (argc == 1)
		ft_error("Error\nNeed map\n", data);
	if (argc > 2)
		ft_error("Error\nToo many arguments\n", data);
	if (open(argv[1], O_RDONLY, 0777) <= -1)
		ft_error("Error\nMap is not reachable\n", data);
	check_name(argv[1], data);
	data->mapfile->path = argv[1];
	if (parse_map(data) == -1)
		return (-1);
	return (1);
}
