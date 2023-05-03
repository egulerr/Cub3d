/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:34:42 by malasaha          #+#    #+#             */
/*   Updated: 2022/10/07 15:44:12 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	press_rot_a_key(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = cub3d->dir_x;
	cub3d->dir_x = cub3d->dir_x * cos(cub3d->rot_speed) \
	- cub3d->dir_y * sin(cub3d->rot_speed);
	cub3d->dir_y = old_dir_x * sin(cub3d->rot_speed) \
	+ cub3d->dir_y * cos(cub3d->rot_speed);
	old_fov_x = cub3d->fov_x;
	cub3d->fov_x = cub3d->fov_x * cos(cub3d->rot_speed) \
	- cub3d->fov_y * sin(cub3d->rot_speed);
	cub3d->fov_y = old_fov_x * sin(cub3d->rot_speed) \
	+ cub3d->fov_y * cos(cub3d->rot_speed);
}

void	print_map_utils(t_cub3d *cub3d, int a, int x)
{
	cub3d->tex_y = (int)cub3d->tex_pos & (cub3d->img_heigth - 1);
	cub3d->tex_pos += cub3d->step;
	if (cub3d->ray_dir_x > 0 && cub3d->side != 1)
		cub3d->color = cub3d->so_data \
		[cub3d->img_heigth * cub3d->tex_y + cub3d->tex_x];
	else if (cub3d->ray_dir_x < 0 && cub3d->side != 1)
		cub3d->color = cub3d->no_data \
		[cub3d->img_heigth * cub3d->tex_y + cub3d->tex_x];
	else if ((cub3d->ray_dir_x < 2 && cub3d->ray_dir_y > 0) \
	&& cub3d->side == 1)
		cub3d->color = cub3d->ea_data \
		[cub3d->img_heigth * cub3d->tex_y + cub3d->tex_x];
	else
		cub3d->color = cub3d->we_data \
		[cub3d->img_heigth * cub3d->tex_y + cub3d->tex_x];
	cub3d->screen_img_data[a * cub3d->width + x] = cub3d->color;
}
