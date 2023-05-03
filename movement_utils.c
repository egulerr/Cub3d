/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:19:29 by malasaha          #+#    #+#             */
/*   Updated: 2022/10/07 15:35:22 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	press_w_key(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->pos_x + cub3d->dir_x * cub3d->move_speed)] \
	[(int)(cub3d->pos_y)] != '1')
		cub3d->pos_x += cub3d->dir_x * cub3d->move_speed;
	if (cub3d->map[(int)(cub3d->pos_x)] \
	[(int)(cub3d->pos_y + cub3d->dir_y * cub3d->move_speed)] != '1')
		cub3d->pos_y += cub3d->dir_y * cub3d->move_speed;
}

void	press_s_key(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->pos_x - cub3d->dir_x * cub3d->move_speed)] \
	[(int)(cub3d->pos_y)] != '1')
		cub3d->pos_x -= cub3d->dir_x * cub3d->move_speed;
	if (cub3d->map[(int)(cub3d->pos_x)] \
	[(int)(cub3d->pos_y - cub3d->dir_y * cub3d->move_speed)] != '1')
		cub3d->pos_y -= cub3d->dir_y * cub3d->move_speed;
}

void	press_a_key(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->pos_x - cub3d->fov_x * cub3d->move_speed)] \
	[(int)(cub3d->fov_y)] != '1')
		cub3d->pos_x -= cub3d->fov_x * cub3d->move_speed;
	if (cub3d->map[(int)(cub3d->pos_x)] \
	[(int)(cub3d->pos_y - cub3d->fov_y * cub3d->move_speed)] != '1')
		cub3d->pos_y -= cub3d->fov_y * cub3d->move_speed;
}

void	press_d_key(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->pos_x + cub3d->fov_x * cub3d->move_speed)] \
	[(int)(cub3d->pos_y)] != '1')
		cub3d->pos_x += cub3d->fov_x * cub3d->move_speed;
	if (cub3d->map[(int)(cub3d->pos_x)] \
	[(int)(cub3d->pos_y + cub3d->fov_y * cub3d->move_speed)] != '1')
		cub3d->pos_y += cub3d->fov_y * cub3d->move_speed;
}

void	press_rot_d_key(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = cub3d->dir_x;
	cub3d->dir_x = cub3d->dir_x * cos(-cub3d->rot_speed) \
	- cub3d->dir_y * sin(-cub3d->rot_speed);
	cub3d->dir_y = old_dir_x * sin(-cub3d->rot_speed) \
	+ cub3d->dir_y * cos(-cub3d->rot_speed);
	old_fov_x = cub3d->fov_x;
	cub3d->fov_x = cub3d->fov_x * cos(-cub3d->rot_speed) \
	- cub3d->fov_y * sin(-cub3d->rot_speed);
	cub3d->fov_y = old_fov_x * sin(-cub3d->rot_speed) \
	+ cub3d->fov_y * cos(-cub3d->rot_speed);
}
