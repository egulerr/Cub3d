/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:18:33 by malasaha          #+#    #+#             */
/*   Updated: 2022/10/07 17:31:35 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_update(t_cub3d *cub3d)
{
	if (cub3d->w_key)
		press_w_key(cub3d);
	if (cub3d->s_key)
		press_s_key(cub3d);
	if (cub3d->a_key)
		press_a_key(cub3d);
	if (cub3d->d_key)
		press_d_key(cub3d);
	if (cub3d->rot_a_key)
		press_rot_a_key(cub3d);
	if (cub3d->rot_d_key)
		press_rot_d_key(cub3d);
}

int	key_press(int key, t_cub3d *cub3d)
{
	if (key == 53)
	{
		exit(0);
	}
	else if (key == 13)
		cub3d->w_key = 1;
	else if (key == 1)
		cub3d->s_key = 1;
	else if (key == 0)
		cub3d->a_key = 1;
	else if (key == 2)
		cub3d->d_key = 1;
	else if (key == 123)
		cub3d->rot_a_key = 1;
	else if (key == 124)
		cub3d->rot_d_key = 1;
	return (0);
}

int	key_release(int key, t_cub3d *cub3d)
{
	if (key == 53)
	{
		exit(0);
	}
	else if (key == 13)
		cub3d->w_key = 0;
	else if (key == 1)
		cub3d->s_key = 0;
	else if (key == 0)
		cub3d->a_key = 0;
	else if (key == 2)
		cub3d->d_key = 0;
	else if (key == 123)
		cub3d->rot_a_key = 0;
	else if (key == 124)
		cub3d->rot_d_key = 0;
	return (0);
}
