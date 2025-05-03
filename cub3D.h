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
	int			    fd;
	char		    *line;
	char		    *tmp;
	char		    *str;
	char		    **split;
	char		    **map;
}			t_parsing;

typedef struct s_map_config
{
    char		    *no_texture;
    char		    *so_texture;
    char		    *we_texture;
    char		    *ea_texture;
    int     	    floor_color[3];
    int     	    ceiling_color[3];
    char    	    **map;
    short     	    map_width;
    short     	    map_height;
    short       	player_x;
    short       	player_y;
}   t_map_config;


char		        *get_next_line(short fd);
void		        ft_print_error(char *str);
void	            ft_init_parsing(t_parsing *data);
void	            ft_read_map_file(t_parsing *data);
short	            ft_count_len(char **strs, short i);
char		        **ft_check_map_errors(char *filename);
short	            ft_check_texture_is_valid(t_parsing *data);
void	            ft_check_dor_errors(char **map, short i, short j);
void	            ft_check_map(char **map, short i, short j, short player);
short	            ft_check_floor_color(t_parsing *data, short i, short len);
void	            ft_check_elements(char **map, short i, short j, short len);
void	            ft_assign_map_config_values(char **str, t_map_config *map);
short	            ft_check_ceiling_color(t_parsing *data, short i, short len);

#endif
