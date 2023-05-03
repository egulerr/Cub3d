/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:07:44 by eguler            #+#    #+#             */
/*   Updated: 2022/10/07 18:03:40 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printf_map(t_cub3d *cub3d)
{
	int	x;
	int	a;

	x = 0;
	while (x < cub3d->width)
	{
		cam_pos(cub3d, x);
		a = cub3d->draw_start;
		while (a < cub3d->draw_end)
		{
			print_map_utils(cub3d, a, x);
			a++;
		}
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->mlx_win, \
	cub3d->screen_img, 0, 0);
	mlx_put_image_to_window(cub3d->mlx, cub3d->mlx_win, \
	cub3d->chc_img, 0, 150);
}

int	main_loop(t_cub3d *cub3d)
{
	cealing_color(cub3d);
	floor_color(cub3d);
	printf_map(cub3d);
	key_update(cub3d);
	return (0);
}

int	ft_exit(void)
{
	exit(1);
	return (1);
}

void	start(t_cub3d *cub3d)
{
	get_pos(cub3d);
	get_direction(cub3d);
	cub3d->move_speed = 0.2;
	cub3d->rot_speed = 0.05;
	cub3d->bg_height = 1920;
	cub3d->bg_width = 1080;
	cub3d->img_width = 64;
	cub3d->img_heigth = 64;
	cub3d->width = 1920;
	cub3d->height = 1080;
	cub3d->mlx = mlx_init();
	cub3d->mlx_win = mlx_new_window(cub3d->mlx, \
	cub3d->width, cub3d->height, "Cub3d");
	all_image(cub3d);
	cub3d->screen_img = mlx_new_image(cub3d->mlx, cub3d->width, cub3d->height);
	cub3d->screen_img_data = (int *)mlx_get_data_addr(cub3d->screen_img, \
	&cub3d->bit_per_pixel, &cub3d->size_line, &cub3d->endian);
	cub3d->chc_img = mlx_xpm_file_to_image(cub3d->mlx, \
	"textures/chc.xpm", &cub3d->bg_height, &cub3d->bg_width);
	mlx_loop_hook(cub3d->mlx, &main_loop, cub3d);
	mlx_hook(cub3d->mlx_win, 2, 0, &key_press, cub3d);
	mlx_hook(cub3d->mlx_win, 3, 0, &key_release, cub3d);
	mlx_hook(cub3d->mlx_win, 17, 0, &ft_exit, cub3d);
	mlx_loop(cub3d->mlx);
}

int	main(int ac, char **av)
{
	t_cub3d	*cub3d;
	int		flag;

	flag = 0;
	if (ac == 2)
	{
		cub3d = ft_calloc(sizeof(t_cub3d), 1);
		flag = checks_and_setup(av[1], cub3d);
		if (flag != 0)
			error_message(flag);
		else
			start(cub3d);
	}
	else
		error_message(flag);
}
