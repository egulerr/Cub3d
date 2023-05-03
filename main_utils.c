/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:05:34 by malasaha          #+#    #+#             */
/*   Updated: 2022/10/07 15:29:37 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_direction(t_cub3d *cub3d)
{
	if (cub3d->direction == 'N')
	{
		cub3d->dir_x = -1;
		cub3d->fov_y = 0.90;
	}
	if (cub3d->direction == 'W')
	{
		cub3d->dir_y = -1;
		cub3d->fov_x = -0.90;
	}
	if (cub3d->direction == 'S')
	{
		cub3d->dir_x = 1;
		cub3d->fov_y = -0.90;
	}
	if (cub3d->direction == 'E')
	{
		cub3d->dir_y = 1;
		cub3d->fov_x = 0.90;
	}
}

void	all_image(t_cub3d *cub3d)
{
	int	a;
	int	b;

	a = 64;
	b = 64;
	if (cub3d->north)
		no_start(cub3d, a, b);
	if (cub3d->south)
		so_start(cub3d, a, b);
	if (cub3d->east)
		ea_start(cub3d, a, b);
	if (cub3d->west)
		we_start(cub3d, a, b);
}

void	get_pos(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'W' \
			|| cub3d->map[i][j] == 'E' || cub3d->map[i][j] == 'S')
			{
				cub3d->pos_x = i;
				cub3d->pos_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	get_character(cub3d);
}

void	get_character(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'E' \
			|| cub3d->map[i][j] == 'W' || cub3d->map[i][j] == 'S')
			{
				cub3d->direction = cub3d->map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
}
