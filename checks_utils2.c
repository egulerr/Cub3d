/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:32:56 by eguler            #+#    #+#             */
/*   Updated: 2022/10/08 18:29:02 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cub(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'b' || file[i - 2] != 'u' || \
	file[i - 3] != 'c' || file[i - 4] != '.' || i < 4)
		return (0);
	return (1);
}

int	is_within_limit(char **s, int flag, t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	*rgb;

	i = 0;
	while (s[i])
		i++;
	rgb = malloc(sizeof(int) * i);
	i = -1;
	while (s[++i])
		rgb[i] = ft_atoi(s[i]);
	j = 0;
	while (j < i)
	{
		if (!(rgb[j] <= 255 && rgb[j] >= 0))
		{
			free(rgb);
			return (0);
		}
		j++;
	}
	fill_color(rgb, flag, cub3d);
	return (1);
}

int	check_map_space(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == ' ')
				cub3d->map[i][j] = '1';
				j++;
		}
		i++;
	}
	return (1);
}

int	check_color(char *str, t_cub3d *cub3d)
{
	int		i;
	char	**s;
	int		flag;

	flag = 0;
	if (str[0] == 'F')
		flag = 1;
	if (str[0] == 'C')
		flag = 2;
	if (!check_comma(str))
		return (0);
	i = -1;
	while (str[++i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			break ;
	}
	if (str[i - 1] != 32 && !(str[i - 1] == '+'))
		return (0);
	s = ft_split(&str[i], ',');
	if (!check_all_color_arguments(s, flag, cub3d))
		return (0);
	ft_free(s);
	return (1);
}

long	convert_rgb_to_hex(t_cub3d *cub3d)
{
	cub3d->f_hex = ((cub3d->f_rgb[0] & 0xff) << 16) + \
	((cub3d->f_rgb[1] & 0xff) << 8) + (cub3d->f_rgb[2] & 0xff);
	cub3d->c_hex = ((cub3d->c_rgb[0] & 0xff) << 16) + \
	((cub3d->c_rgb[1] & 0xff) << 8) + (cub3d->c_rgb[2] & 0xff);
	return (1);
}
