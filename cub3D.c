#include "cub3D.h"

int main(int ac, char **av)
{
    char **map;

    if (ac != 2)
    {
        write (2, "Error\nMap not found — please ensure the map is", 48);
        write(2, " correctly defined and follows the required format.\n", 52);
        exit (-1);
    }
    map = ft_parsing(av[1]);
    // if (map);
        // ft_raycasting();

    while (*map)
        printf("%s\n", *map++);

    return (0);
}