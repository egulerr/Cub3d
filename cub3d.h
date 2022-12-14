#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct s_cub3d
{
    int     fd;
    char    *all; //tek pointer .cubun hepsi
	char	**all_double; //çift pointer .cubun hepsi
    char    **path_color; //path ve color kısmı
    char    **map; //map
    char    *north; //
    char	*south;
	char	*west;
	char	*east;
    char	*floor;
	char	*ceil;
}   t_cub3d;

//checks

int     checks_and_setup(char *file, t_cub3d *cub3d);
int		check_cub(char *str);
int     check_wrong_argument(t_cub3d *cub3d);
//error

void	error_message(void);

//read

char	*ft_read(int fd, char *left_str);
int     read_file(char *file, t_cub3d *cub3d);
#endif