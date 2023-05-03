/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:12:32 by eguler            #+#    #+#             */
/*   Updated: 2022/10/08 18:32:20 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(int flag)
{
	if (flag == 1)
		printf("\033[0;31mWrong argument entry.\n");
	if (flag == 2)
		printf("\033[0;31mFile read failed.\n");
	if (flag == 3)
		printf("\033[0;31mDouble argument entry prohibited\n");
	if (flag == 4)
		printf("\033[0;31mArgument count is not correct.\n");
	if (flag == 5)
		printf("\033[0;31mWrong argument entry.\n");
	if (flag == 6)
		printf("\033[0;31mMust be at least one space between the arguments.\n");
	if (flag == 8)
		printf("\033[0;31mFile not found.\n");
	if (flag == 9)
		printf("\033[0;31mWrong floor entry.\n");
	if (flag == 10)
		printf("\033[0;31mWrong ceil entry.\n");
	if (flag == 11)
		printf("\033[0;31mWrong map entry.\n");
	printf("Error.\n");
	return ;
}

int	check_map(t_cub3d *cub3d)
{
	if (!check_map_space(cub3d))
		return (0);
	if (!check_char(cub3d))
		return (0);
	if (!check_number_of_char(cub3d))
		return (0);
	if (!check_walls(cub3d))
		return (0);
	if (!check_corner(cub3d))
		return (0);
	if (!check_surrounded_by_walls(cub3d))
		return (0);
	fill_player_position(cub3d);
	return (1);
}

int	checks_and_setup(char *file, t_cub3d *cub3d)
{
	if (!check_cub(file))
		return (1);
	if (!read_file(file, cub3d))
		return (2);
	if (!check_double_argument(cub3d))
		return (3);
	if (!check_number_of_words(cub3d))
		return (4);
	if (!check_wrong_argument(cub3d))
		return (5);
	if (!check_space(cub3d))
		return (6);
	if (!fill_arguments(cub3d))
		return (7);
	if (!check_is_open_path(cub3d))
		return (8);
	if (!check_color(cub3d->floor, cub3d))
		return (9);
	if (!check_color(cub3d->ceil, cub3d))
		return (10);
	convert_rgb_to_hex(cub3d);
	if (!check_map(cub3d))
		return (11);
	ft_free(cub3d->all_double);
	return (0);
}
