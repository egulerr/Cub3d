/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:44:26 by eguler            #+#    #+#             */
/*   Updated: 2022/10/08 18:29:22 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_cub3d
{
	int		img_width;
	int		img_heigth;
	int		width;
	int		height;

	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	int		*img_data;
	void	*screen_img;
	int		*screen_img_data;
	void	*chc_img;
	int		img_x;
	int		img_y;
	double	move_speed;
	double	rot_speed;

	char	direction;

	int		a_key;
	int		rot_a_key;
	int		d_key;
	int		rot_d_key;
	int		w_key;
	int		s_key;

	int		fd2;

	int		bg_width;
	int		bg_height;

	void	*ea;
	void	*no;
	void	*we;
	void	*so;

	int		*ea_data;
	int		*we_data;
	int		*so_data;
	int		*no_data;

	char	*ea_path;
	char	*we_path;
	char	*no_path;
	char	*so_path;

	double	pos_x;
	double	pos_y;
	int		next_pos;
	double	step;

	int		ray_x;
	int		ray_y;

	double	side_dist_x;
	double	side_dist_y;

	double	delta_dist_x;
	double	delta_dist_y;

	int		step_x;
	int		step_y;

	int		hit;

	int		side;

	int		line_height;
	int		draw_start;
	int		draw_end;

	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;

	int		color;

	double	perp_wall_dist;

	double	dir_x;
	double	dir_y;
	double	ray_dir_x;
	double	ray_dir_y;

	double	camera_x;

	double	fov_x;
	double	fov_y;

	int		bit_per_pixel;
	int		size_line;
	int		endian;
	int		fd;
	char	*all;
	char	**all_double;
	char	**path_color;
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceil;
	int		*f_rgb;
	int		*c_rgb;
	int		player_x;
	int		player_y;

	long	f_hex;
	long	c_hex;
}	t_cub3d;

//raycast

void	cam_pos(t_cub3d *cub3d, int x);
void	set_image_value(t_cub3d *cub3d);
void	get_distance(t_cub3d *cub3d);
void	hit_check(t_cub3d *cub3d);
void	wallcheck(t_cub3d *cub3d);

//main utils

void	get_direction(t_cub3d *cub3d);
void	all_image(t_cub3d *cub3d);
void	get_pos(t_cub3d *cub3d);
void	get_character(t_cub3d *cub3d);
void	print_map_utils(t_cub3d *cub3d, int a, int x);
void	no_start(t_cub3d *cub3d, int a, int b);
void	so_start(t_cub3d *cub3d, int a, int b);
void	ea_start(t_cub3d *cub3d, int a, int b);
void	we_start(t_cub3d *cub3d, int a, int b);

//movement

void	key_update(t_cub3d *cub3d);
int		key_press(int key, t_cub3d *cub3d);
int		key_release(int key, t_cub3d *cub3d);

//movement utils

void	press_w_key(t_cub3d *cub3d);
void	press_s_key(t_cub3d *cub3d);
void	press_a_key(t_cub3d *cub3d);
void	press_d_key(t_cub3d *cub3d);
void	press_rot_d_key(t_cub3d *cub3d);
void	press_rot_a_key(t_cub3d *cub3d);

//color

void	cealing_color(t_cub3d *cub3d);
void	floor_color(t_cub3d *cub3d);

//utils

int		word_len(char *str);
int		check_comma(char *str);
int		check_is_numeric(char **str);
int		check_is_full_wall(char *str, int index);
int		check_is_any_space(char *str);
int		is_within_limit(char **s, int flag, t_cub3d *cub3d);
int		check_all_color_arguments(char **s, int flag, t_cub3d *cub3d);
//fill

void	fill_map(t_cub3d *cub3d);
void	fill_paths(t_cub3d *cub3d);
int		fill_arguments(t_cub3d *cub3d);
void	fill_player_position(t_cub3d *cub3d);
void	fill_color(int *rgb, int flag, t_cub3d *cub3d);

//checks

int		checks_and_setup(char *file, t_cub3d *cub3d);
int		check_cub(char *str);
int		check_wrong_argument(t_cub3d *cub3d);
int		check_double_argument(t_cub3d *cub3d);
int		check_number_of_words(t_cub3d *cub3d);
int		check_is_open_path(t_cub3d *cub3d);
int		check_space(t_cub3d *cub3d);
int		check_surrounded_by_walls(t_cub3d *cub3d);
int		check_corner(t_cub3d *cub3d);
int		check_walls(t_cub3d *cub3d);
int		check_number_of_char(t_cub3d *cub3d);
int		check_char(t_cub3d *cub3d);
int		check_map_space(t_cub3d *cub3d);
int		check_color(char *str, t_cub3d *cub3d);
int		check_is_open_path_2(char *no, char *so, char *we, char *ea);
int		check_arg_count(char **str);

long	convert_rgb_to_hex(t_cub3d *cub3d);
//error

void	error_message(int flag);

//read

char	*ft_read(int fd, char *left_str);
int		read_file(char *file, t_cub3d *cub3d);

//free

void	ft_free(char **str);
void	ft_free_paths(char **no, char **so, char **we, char **ea);

#endif