/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:12:32 by eguler            #+#    #+#             */
/*   Updated: 2022/09/28 12:39:31 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    error_message(void)
{
    printf("Error\n");
    return ;
}

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

int fill_arguments(t_cub3d *cub3d)
{
    int i;

    i = 0;
    while (cub3d->all_double[i] && cub3d->all_double[i][0] != '1')
    { //duvar yollarını ve renklerin degiskenlerinde degisiklik yapıcaksak ft_strdup eklicem.
        if (ft_strcmp(cub3d->all_double[i], "NO"))
            cub3d->north = cub3d->all_double[i];
        if (ft_strcmp(cub3d->all_double[i], "SO"))
            cub3d->south = cub3d->all_double[i];
        if (ft_strcmp(cub3d->all_double[i], "WE"))
            cub3d->west = cub3d->all_double[i];
        if (ft_strcmp(cub3d->all_double[i], "EA"))
            cub3d->east = cub3d->all_double[i];
		if (ft_strcmp(cub3d->all_double[i], "F"))
            cub3d->floor = cub3d->all_double[i];
		if (ft_strcmp(cub3d->all_double[i], "C"))
            cub3d->ceil = cub3d->all_double[i];
        i++;
    }
	//fill_paths(cub3d);
	fill_map(cub3d);
    return (1);
}

int word_len(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != 32)
        i++;
    return (i);
}

int check_double_argument(t_cub3d *cub3d)
{
    int i;
    int j;
    int count;
    int len;

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

int	check_wrong_argument(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->all_double[i] && cub3d->all_double[i][0] != '1')
    {
        if (ft_strncmp(cub3d->all_double[i], "NO", 2)
        && ft_strncmp(cub3d->all_double[i], "SO", 2)
        && ft_strncmp(cub3d->all_double[i], "WE", 2)
        && ft_strncmp(cub3d->all_double[i], "EA", 2)
        && ft_strncmp(cub3d->all_double[i], "F", 1)
        && ft_strncmp(cub3d->all_double[i], "C", 1))
        {
            return (0);
        }
        i++;
	}
    return (1);
}

int	check_is_there_path(t_cub3d *cub3d)
{
	if (!ft_strstr(cub3d->north, "./"))
		return (0);
	if (!ft_strstr(cub3d->south, "./"))
		return (0);
	if (!ft_strstr(cub3d->west, "./"))
		return (0);
	if (!ft_strstr(cub3d->east, "./"))
		return (0);
	return (1);
}

int checks_and_setup(char *file, t_cub3d *cub3d)
{ 
    if (!check_cub(file)) //.cub uzantısı kontrolü
        return (0);
    if (!read_file(file, cub3d)) //dosya okuma yazma işlemi
        return (0);
    if (!check_double_argument(cub3d)) //aynı argümandan 2 tane var mı kontrolü
        return (0);
    if (!check_number_of_words(cub3d)) //argümanlarım 6 tane olmak zorunda. onun checki.
        return (0);
	if (!check_wrong_argument(cub3d)) //mapa kadar satır satır kontrol ediyor. 
		return (0);
    if (!fill_arguments(cub3d)) //.cub uzantılı dosyayı degiskenlere aktarma. 
        return (0);
	if (!check_is_there_path(cub3d)) // NO,SO,WE,EA'lardan sonra path var mı kontrolü
		return (0);
	/* if (!check_is_open_path(cub3d)) // açılıyo mu kontrolü fotoları bulduktan sonra yaz.
		return (0); */
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