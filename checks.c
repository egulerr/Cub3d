/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:12:32 by eguler            #+#    #+#             */
/*   Updated: 2022/09/24 22:01:37 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    error_message(void)
{
    printf("Error\n");
    return ;
}

int checks_and_setup(char *file, t_cub3d *cub3d)
{
    if (!cub_check(file))
        return (0);
    cub3d->fd = open(file, O_RDONLY);
    if (cub3d->fd < 0)
        return (0);
    cub3d->all = ft_read(cub3d->fd, cub3d->all);
    cub3d->all_double = ft_split(cub3d->all, '\n');
    return (1);
}

int cub_check(char *file)
{
    int i;

    i = 0;
    while (file[i])
        i++;
    if (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c' || file[i - 4] != '.' || i < 4)
        return (0);
    return (1);
}