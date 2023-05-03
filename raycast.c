/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:22:08 by malasaha          #+#    #+#             */
/*   Updated: 2022/10/07 15:48:27 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallcheck(t_cub3d *cub3d)
{
	if (cub3d->ray_dir_x < 0)
	{
		cub3d->step_x = -1;
		cub3d->side_dist_x = (cub3d->pos_x - cub3d->ray_x) \
		* cub3d->delta_dist_x;
	}
	else
	{
		cub3d->step_x = 1;
		cub3d->side_dist_x = (cub3d->ray_x + 1.0 - cub3d->pos_x) \
		* cub3d->delta_dist_x;
	}
	if (cub3d->ray_dir_y < 0)
	{
		cub3d->step_y = -1;
		cub3d->side_dist_y = (cub3d->pos_y - cub3d->ray_y) \
		* cub3d->delta_dist_y;
	}
	else
	{
		cub3d->step_y = 1;
		cub3d->side_dist_y = (cub3d->ray_y + 1.0 - cub3d->pos_y) \
		* cub3d->delta_dist_y;
	}
}

void	hit_check(t_cub3d *cub3d)
{
	while (cub3d->hit == 0)
	{
		if (cub3d->side_dist_x < cub3d->side_dist_y)
		{
			cub3d->side_dist_x += cub3d->delta_dist_x;
			cub3d->ray_x += cub3d->step_x;
			cub3d->side = 0;
		}
		else
		{
			cub3d->side_dist_y += cub3d->delta_dist_y;
			cub3d->ray_y += cub3d->step_y;
			cub3d->side = 1;
		}
		if (cub3d->ray_x < 0 || cub3d->ray_y < 0)
		{
			if (cub3d->ray_x < 0)
				cub3d->ray_x = 0;
			if (cub3d->ray_y < 0)
				cub3d->ray_y = 0;
		}
		if (cub3d->map[cub3d->ray_x][cub3d->ray_y] == '1')
			cub3d->hit = 1;
	}
}

void	get_distance(t_cub3d *cub3d)
{
	if (cub3d->side == 0)
		cub3d->perp_wall_dist = (cub3d->ray_x - cub3d->pos_x \
		+ (1 - cub3d->step_x) / 2) / cub3d->ray_dir_x;
	else
		cub3d->perp_wall_dist = (cub3d->ray_y - cub3d->pos_y \
		+ (1 - cub3d->step_y) / 2) / cub3d->ray_dir_y;
	cub3d->line_height = (int)(cub3d->height / cub3d->perp_wall_dist);
	cub3d->draw_start = -cub3d->line_height / 2 + cub3d->height / 2;
	if (cub3d->draw_start < 0)
		cub3d->draw_start = 0;
	cub3d->draw_end = cub3d->line_height / 2 + cub3d->height / 2;
	if (cub3d->draw_end >= cub3d->height)
		cub3d->draw_end = cub3d->height - 1;
}

void	set_image_value(t_cub3d *cub3d)
{
	cub3d->next_pos = cub3d->map[cub3d->ray_x][cub3d->ray_y];
	if (cub3d->side == 0)
		cub3d->wall_x = cub3d->pos_y + cub3d->perp_wall_dist * cub3d->ray_dir_y;
	else
		cub3d->wall_x = cub3d->pos_x + cub3d->perp_wall_dist * cub3d->ray_dir_x;
	cub3d->wall_x -= floor(cub3d->wall_x);
	cub3d->tex_x = (int)(cub3d->wall_x * (double)cub3d->img_width);
	if (cub3d->side == 0 && cub3d->ray_dir_x > 0)
		cub3d->tex_x = cub3d->img_width - cub3d->tex_x - 1;
	if (cub3d->side == 1 && cub3d->ray_dir_y < 0)
		cub3d->tex_x = cub3d->img_width - cub3d->tex_x - 1;
	cub3d->step = 1.0 * cub3d->img_heigth / cub3d->line_height;
	cub3d->tex_pos = (cub3d->draw_start - cub3d->height \
	/ 2 + cub3d->line_height / 2) * cub3d->step;
}

void	cam_pos(t_cub3d *cub3d, int x)
{
	cub3d->camera_x = 2 * x / (double)cub3d->width - 1;
	cub3d->ray_dir_x = cub3d->dir_x + cub3d->fov_x * cub3d->camera_x;
	cub3d->ray_dir_y = cub3d->dir_y + cub3d->fov_y * cub3d->camera_x;
	cub3d->ray_x = (int)cub3d->pos_x;
	cub3d->ray_y = (int)cub3d->pos_y;
	cub3d->delta_dist_x = fabs(1 / cub3d->ray_dir_x);
	cub3d->delta_dist_y = fabs(1 / cub3d->ray_dir_y);
	cub3d->hit = 0;
	wallcheck(cub3d);
	hit_check(cub3d);
	get_distance(cub3d);
	set_image_value(cub3d);
}
