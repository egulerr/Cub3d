/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:58:45 by eguler            #+#    #+#             */
/*   Updated: 2022/10/07 18:32:46 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (cub3d->all_double[i] && cub3d->all_double[i][0] != '1')
		i++;
	j = i;
	while (cub3d->all_double[i])
	{
		len++;
		i++;
	}
	cub3d->map = malloc(sizeof(char *) * len + 1);
	i = 0;
	while (cub3d->all_double[j])
		cub3d->map[i++] = ft_strdup(cub3d->all_double[j++]);
	cub3d->map[i] = NULL;
}

int	fill_arguments(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->all_double[i] && cub3d->all_double[i][0] != '1')
	{
		if (ft_strcmp(cub3d->all_double[i], "NO"))
			cub3d->north = ft_strdup(cub3d->all_double[i]);
		if (ft_strcmp(cub3d->all_double[i], "SO"))
			cub3d->south = ft_strdup(cub3d->all_double[i]);
		if (ft_strcmp(cub3d->all_double[i], "WE"))
			cub3d->west = ft_strdup(cub3d->all_double[i]);
		if (ft_strcmp(cub3d->all_double[i], "EA"))
			cub3d->east = ft_strdup(cub3d->all_double[i]);
		if (ft_strcmp(cub3d->all_double[i], "F"))
			cub3d->floor = ft_strdup(cub3d->all_double[i]);
		if (ft_strcmp(cub3d->all_double[i], "C"))
			cub3d->ceil = ft_strdup(cub3d->all_double[i]);
		i++;
	}
	fill_map(cub3d);
	return (1);
}

void	fill_player_position(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S' \
			|| cub3d->map[i][j] == 'W' || cub3d->map[i][j] == 'E')
			{
				cub3d->player_x = i;
				cub3d->player_y = j;
			}
			j++;
		}
		i++;
	}
}

void	fill_color(int *rgb, int flag, t_cub3d *cub3d)
{
	if (flag == 1)
		cub3d->f_rgb = rgb;
	if (flag == 2)
		cub3d->c_rgb = rgb;
}
