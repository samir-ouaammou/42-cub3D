#include "cub3D.h"

int main(int ac, char **av)
{
    t_map_config map;

    if (ac != 2)
    {
        write (2, "Error\nMap not found — please ensure the map is", 48);
        write(2, " correctly defined and follows the required format.\n", 52);
        exit (-1);
    }
    ft_assign_map_config_values(&map, ft_check_map_errors(av[1]));

    // ------------------------
    // printf("TEXTUSE:\n%s\n", map.no_texture);
    // printf("%s\n", map.so_texture);
    // printf("%s\n", map.we_texture);
    // printf("%s\n\n", map.ea_texture);
    // printf("FLOOR COLORS:\n%d\t%d\t%d\n\n", map.floor_color[0], map.floor_color[1], map.floor_color[2]);
    // printf("CEILING COLORS:\n%d\t%d\t%d\n\n", map.ceiling_color[0], map.ceiling_color[1], map.ceiling_color[2]);
    // printf("LEN MAP:\n%zu\n%zu\n\n", map.map_height, map.map_width);
    // printf("PLAYER POSITION:\n%zu\n%zu\n\n", map.player_x + 1, map.player_y + 1);
    // printf("MAP:\n");
    // while (*map.map)
    //     printf("%s\n", *map.map++);
    // ------------------------

    return (0);
}