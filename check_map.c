/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:23:08 by eguler            #+#    #+#             */
/*   Updated: 2022/10/03 15:54:25 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_surrounded_by_walls(t_cub3d *cub3d)
{
	int	i;
	int	current_len;
	int	next_len;

	i = 0;
	while (cub3d->map[i])
	{
		if (cub3d->map[i + 1] == NULL)
			break ;
		current_len = ft_strlen(cub3d->map[i]);
		next_len = ft_strlen(cub3d->map[i + 1]);
		if (current_len < next_len)
		{
			if (!check_is_full_wall(cub3d->map[i + 1], current_len))
				return (0);
		}
		else
		{
			if (!check_is_full_wall(cub3d->map[i], next_len))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_corner(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if ((j == 0 && cub3d->map[i][j] != '1') \
			|| (cub3d->map[i][j + 1] == '\0' && cub3d->map[i][j] != '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_walls(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map[0][i])
	{
		if (cub3d->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (cub3d->map[i + 1])
		i++;
	j = 0;
	while (cub3d->map[i][j])
	{
		if (cub3d->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_number_of_char(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S' \
			|| cub3d->map[i][j] == 'W' || cub3d->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		return (0);
	if (count == 1)
		return (1);
	else
		return (0);
}

int	check_char(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] != '1' \
			&& cub3d->map[i][j] != '0' \
			&& cub3d->map[i][j] != 'N' \
			&& cub3d->map[i][j] != 'S' \
			&& cub3d->map[i][j] != 'E' \
			&& cub3d->map[i][j] != 'W')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
