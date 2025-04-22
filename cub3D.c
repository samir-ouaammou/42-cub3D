#include "cub3D.h"

int main(int ac, char **av)
{
    char **map;

    if (ac != 2)
        return (1);
    map = ft_parsing(av[1]);
    // if (map);
        // ft_raycasting();

    while (*map)
        printf("%s\n", *map++);

    return (0);
}