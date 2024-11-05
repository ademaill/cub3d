/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:33:51 by ymarques          #+#    #+#             */
/*   Updated: 2024/11/05 12:11:37 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define _USE_MATH_DEFINES

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

# include "../libft/libft.h"
# include "../srcs/gnl/get_next_line.h"
# include "../mlx/includes/mlx.h"
# include "../mlx/includes/mlx_profile.h"

# define SCREEN_W 1920
# define SCREEN_H 1080
# define FOV 60
# define TILE_SIZE 300
# define IMG_SIZE 300
# define MOOVE_SPEED 50
# define ROTATE_SPEED 0.05
# define UP 26
# define DOWN 22
# define RIGHT 4
# define LEFT 7
# define RIGHT_ROTATE 80
# define LEFT_ROTATE 79

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_mapfile
{
	char	*path;
	char	**content;
	char	*no_text_path;
	char	*so_text_path;
	char	*we_text_path;
	char	*ea_text_path;
	t_rgb	*f_color;
	t_rgb	*c_color;
	int		c_l;
	int		i_mstart;
	int		i_mend;
	int		param_count;
}	t_mapfile;

typedef struct s_player
{
	int		*px_x;
	int		*px_y;
	int		*x;
	int		*y;
	double	fov;
	double	angle;
}	t_player;

typedef struct s_map
{
	char	**arr;
	char	**arr_cpy;
	int		width;
	int		height;
}	t_map;

typedef struct s_ray
{
	double	angle;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*no_img;
	void		*so_img;
	void		*we_img;
	void		*ea_img;
	bool		mouse_lock;
	t_player	*player;
	t_map		*map;
	t_mapfile	*mapfile;
	t_ray		*ray;
}	t_data;

// parse_map.c
int		parse(int argc, char **argv, t_data *data);
int		parse_map(t_data *data);
int		flood_fill(t_data *data, int y, int x);
int		cast_rays(t_data *data);
int		ft_isspace(char c);
int		line_is_space(char *line);
int		strlen_new_line(char *line);
t_rgb	*str_to_rgb(char *str, t_data *data);

//parse_file.c
int		get_file_lines(t_mapfile *mapfile);
int		fill_metadata(char *line, t_data *data);
int		process_metadata(t_data *data);
int		extract_file_content(t_data *data);

//name_utils.c
int		check_name(char *str, t_data *data);
char	*check_readable(char *line, t_data *data);

//player_utils.c
bool	is_uniq_ply(t_data *data);
void	fill_player_angle(t_data *data, char c);
void	fill_player_pos(t_data *data);

//initialisation
int		init(t_data *data);

//game
int		game(t_data *data);
int		key_hook(int key, void *param);
int		mouse_hook(int button, void *param);
void	ft_exit(t_data *data);

//game/utils
double	nor_angle(double angle);
void	set_ystep_sign(double angle, double *y_step);
void	set_xstep_sign(double angle, double *x_step);
int		inter_check(double angle, double *delta, bool h_or_v);
int		get_good_color(t_data *data, int pos);
bool	check_pos_y(t_data *data, double new_pos, double old_pos);
bool	check_pos_x(t_data *data, double new_pos, double old_pos);

//game/wall_utils.c
bool	wall_is_hit(double v_x, double v_y, t_data *data);
void	*get_texture(t_data *data);
void	render_wall(t_data *data, int ray);

//utils
void	ft_error(char *str, t_data *data);

//free
void	free_all(t_data *data);
void	free_arr(char **arr);

#endif