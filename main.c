/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:07:44 by eguler            #+#    #+#             */
/*   Updated: 2022/09/24 22:01:18 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        t_cub3d *cub3d;
        cub3d = malloc(sizeof(t_cub3d));
        if (!checks_and_setup(av[1], cub3d))
            error_message();
    }
    else
        error_message();
}