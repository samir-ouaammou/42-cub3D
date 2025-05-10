#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line/get_next_line.h"
# include "./GarbageCollector/malloc.h"
# include "./libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <X11/X.h>
# include <mlx.h>

# define BUFFER_SIZE 1

typedef struct s_map_config
{
    char            *mlx;
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

typedef struct s_parsing
{
	int			    fd;
	char		    *line;
	char		    *tmp;
	char		    *str;
	char		    **split;
	char		    **map;
    t_map_config    *data;
}			t_parsing;
int	ft_map_join(t_parsing *data);
void	ft_player_location_and_map_size(t_parsing *data, char **str);
void	ft_check_texture_is_valid(t_parsing *data, char *str, int nbr);
void	ft_check_path_to_the_north_texture_is_valid(t_parsing *data);
void	ft_check_path_to_the_south_texture_is_valid(t_parsing *data);
void	ft_check_path_to_the_west_texture_is_valid(t_parsing *data);
void	ft_check_path_to_the_east_texture_is_valid(t_parsing *data);
void	ft_check_colors_is_valid(t_parsing *data, char *str, int nbr);
void	ft_check_floor_color(t_parsing *data);
void	ft_check_ceiling_color(t_parsing *data);
t_map_config	*ft_parsing_map_file(t_map_config *map, char *filename);
void	            ft_init_parsing(t_parsing *data);
void		        ft_print_error(char *str);
char	*get_next_line(int fd);
void	ft_read_map_file(t_parsing *data, short nbr, short bol);
short	            ft_count_len(char **strs);
//char		        **ft_check_map_errors(char *filename);
//short	            ft_check_texture_is_valid(t_parsing *data);
void	            ft_check_dor_errors(char **map, size_t i, size_t j);
//void	            ft_check_map(char **map, short i, short j, short player);
//short	            ft_check_floor_color(t_parsing *data, short i, short len);
void	            ft_check_elements(char **map, size_t i, size_t j, size_t len);
//void	            ft_assign_map_config_values(t_map_config *map, char **str);
//short	            ft_check_ceiling_color(t_parsing *data, short i, short len);
//void	            ft_parse_player_and_map_size(t_map_config *map, char **str);

#endif
