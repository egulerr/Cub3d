/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:48:05 by eguler            #+#    #+#             */
/*   Updated: 2022/10/05 15:23:40 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	word_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 32)
		i++;
	return (i);
}

int	check_is_any_space(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (1);
	else
		return (0);
}

int	check_comma(char *str)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			count++;
	}
	j = -1;
	while (str[++j])
	{
		if (str[j] <= '9' && str[j] >= '0')
			break ;
	}
	if (count == 2 && str[j - 1] == ',')
		return (0);
	if (str[i - 1] == ',')
		return (0);
	if (count != 2)
		return (0);
	else
		return (1);
}

int	check_is_numeric(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_is_full_wall(char *str, int index)
{
	while (str[index])
	{
		if (str[index] != '1')
			return (0);
		index++;
	}
	return (1);
}
