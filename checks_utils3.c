/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:29:42 by malasaha          #+#    #+#             */
/*   Updated: 2022/10/08 18:23:07 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_is_open_path_2(char *no, char *so, char *we, char *ea)
{
	if (open(no, O_RDONLY) == -1)
		return (0);
	if (open(so, O_RDONLY) == -1)
		return (0);
	if (open(we, O_RDONLY) == -1)
		return (0);
	if (open(ea, O_RDONLY) == -1)
		return (0);
	return (1);
}

int	check_arg_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 2)
		return (0);
	return (1);
}

int	check_color_arg(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i != 3)
		return (0);
	return (1);
}

int	check_all_color_arguments(char **s, int flag, t_cub3d *cub3d)
{
	if (!check_color_arg(s))
	{
		ft_free(s);
		return (0);
	}
	if (!check_is_numeric(s))
	{
		ft_free(s);
		return (0);
	}
	if (!is_within_limit(s, flag, cub3d))
	{
		ft_free(s);
		return (0);
	}
	return (1);
}
