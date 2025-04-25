#ifndef CUB3D_H
# define CUB3D_H

# include "./GarbageCollector/malloc.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct s_parsing
{
	int			fd;
	char		*line;
	char		*tmp;
	char		*str;
	char		**split;
	char		**map;
}			t_parsing;

typedef struct s_map_config
{
    char		*no_texture;
    char		*so_texture;
    char		*we_texture;
    char		*ea_texture;
    int     	floor_color[3];
    int     	ceiling_color[3];
    char    	**map;
    size_t     	map_width;
    size_t     	map_height;
    size_t       	player_x;
    size_t       	player_y;
    // double  	dir_x;
    // double  	dir_y;
    // double  	plane_x;
    // double  	plane_y;
}   t_map_config;


char		*get_next_line(int fd);
char		**ft_check_map_errors(char *filename);
void		ft_print_error(char *str);
short	ft_count_len(char **strs, short i);
int	ft_check_texture_is_valid(t_parsing *data);
int	ft_check_floor_color(t_parsing *data, int i, int len);
int	ft_check_ceiling_color(t_parsing *data, int i, int len);
void	ft_check_map(char **map, int i, int j, int player);
void	ft_check_elements(char **map, int i, int j, int len);
void	ft_read_map_file(t_parsing *data);
void	ft_init_parsing(t_parsing *data);
void	ft_assign_map_config_values(char **str, t_map_config *map);

#endif
