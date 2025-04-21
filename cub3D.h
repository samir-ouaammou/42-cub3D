#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include "./GarbageCollector/malloc.h"

# define BUFFER_SIZE 1

typedef struct s_parsing
{
    int     fd;
    int     raycasting;
    char    *line;
    char    *tmp;
    char    *str;
    char    **split;
    char    **map;
}           t_parsing;

char		*get_next_line(int fd);
char    **ft_parsing(char *filename);
void    ft_print_error(char *str);

#endif
