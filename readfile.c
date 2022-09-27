/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:00:17 by eguler            #+#    #+#             */
/*   Updated: 2022/09/27 15:44:27 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_file(char *file, t_cub3d *cub3d)
{
	cub3d->fd = open(file, O_RDONLY);
    if (cub3d->fd < 0) 
        return (0);
    cub3d->all = ft_read(cub3d->fd, cub3d->all);
    cub3d->all_double = ft_split(cub3d->all, '\n');
	return (1);
}

char	*ft_read(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	rd_bytes = 1;
	left_str = ft_strdup("");
	buff = malloc(sizeof(char) * 2);
	while (rd_bytes != 0)
	{
		if (!buff)
			return (NULL);
		rd_bytes = read(fd, buff, 1);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}
