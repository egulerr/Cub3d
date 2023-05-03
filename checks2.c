/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:12:40 by eguler            #+#    #+#             */
/*   Updated: 2022/10/07 18:35:15 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_double_argument(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	count;
	int	len;

	count = 0;
	i = 0;
	while (cub3d->all_double[i] && cub3d->all_double[i][0] != '1')
	{
		j = 0;
		while (cub3d->all_double[j])
		{
			len = word_len(cub3d->all_double[j]);
			if (!ft_strncmp(cub3d->all_double[i], cub3d->all_double[j], len))
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		count = 0;
		i++;
	}
	return (1);
}

int	check_number_of_words(t_cub3d *cub3d)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (cub3d->all_double[i] && cub3d->all_double[i][0] != '1')
	{
		if (ft_strcmp(cub3d->all_double[i], "NO"))
			count++;
		if (ft_strcmp(cub3d->all_double[i], "SO"))
			count++;
		if (ft_strcmp(cub3d->all_double[i], "WE"))
			count++;
		if (ft_strcmp(cub3d->all_double[i], "EA"))
			count++;
		if (ft_strcmp(cub3d->all_double[i], "F"))
			count++;
		if (ft_strcmp(cub3d->all_double[i], "C"))
			count++;
		i++;
	}
	if (count != 6)
		return (0);
	return (1);
}

int	check_wrong_argument(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->all_double[i] && cub3d->all_double[i][0] != '1')
	{
		if (ft_strncmp(cub3d->all_double[i], "NO", 2) \
		&& ft_strncmp(cub3d->all_double[i], "SO", 2) \
		&& ft_strncmp(cub3d->all_double[i], "WE", 2) \
		&& ft_strncmp(cub3d->all_double[i], "EA", 2) \
		&& ft_strncmp(cub3d->all_double[i], "F", 1) \
		&& ft_strncmp(cub3d->all_double[i], "C", 1))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_is_open_path(t_cub3d *cub3d)
{
	char	**no;
	char	**so;
	char	**we;
	char	**ea;

	no = ft_split(cub3d->north, ' ');
	so = ft_split(cub3d->south, ' ');
	we = ft_split(cub3d->west, ' ');
	ea = ft_split(cub3d->east, ' ');
	if (!check_arg_count(no))
		return (0);
	if (!check_arg_count(so))
		return (0);
	if (!check_arg_count(we))
		return (0);
	if (!check_arg_count(ea))
		return (0);
	if (!check_is_open_path_2(no[1], so[1], we[1], ea[1]))
		return (0);
	cub3d->no_path = ft_strdup(no[1]);
	cub3d->so_path = ft_strdup(so[1]);
	cub3d->we_path = ft_strdup(we[1]);
	cub3d->ea_path = ft_strdup(ea[1]);
	ft_free_paths(no, so, we, ea);
	return (1);
}

int	check_space(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->all_double[i] && cub3d->all_double[i][0] != '1')
	{
		if (!check_is_any_space(cub3d->all_double[i]))
			return (0);
		i++;
	}
	return (1);
}
