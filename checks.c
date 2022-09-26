/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:12:32 by eguler            #+#    #+#             */
/*   Updated: 2022/09/26 22:03:50 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    error_message(void)
{
    printf("Error\n");
    return ;
}

int check_path(t_cub3d *cub3d)
{
    int i;

    i = 0;
    while (cub3d->all_double[i])
    {
        if (ft_strcmp(cub3d->all_double[i], "NO"))
            cub3d->north = cub3d->all_double[i];
        if (ft_strcmp(cub3d->all_double[i], "SO"))
            cub3d->south = cub3d->all_double[i];
        if (ft_strcmp(cub3d->all_double[i], "WE"))
            cub3d->west = cub3d->all_double[i];
        if (ft_strcmp(cub3d->all_double[i], "EA"))
            cub3d->east = cub3d->all_double[i];
        i++;
    }
    return (1);
}

int check_double_argument(t_cub3d *cub3d)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (cub3d->all_double[i])
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

int checks_and_setup(char *file, t_cub3d *cub3d)
{
    if (!check_cub(file)) //.cub uzantısı kontrolü
        return (0);
    if (!read_file(file, cub3d)) //dosya okuma yazma işlemi
        return (0);
    if (!check_double_argument(cub3d)) //aynı argümandan 2 tane var mı kontrolü ve
        return (0);
   /*  if (!check_wrong_argument(cub3d)) //herhangi bir satırında istenilen argümanların dışında bir argüman olup olmadığını kontrol etme
        return (0); */
    if (!check_path(cub3d))
        return (0);
    return (1);
}

int check_cub(char *file)
{
    int i;

    i = 0;
    while (file[i])
        i++;
    if (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c' || file[i - 4] != '.' || i < 4)
        return (0);
    return (1);
}