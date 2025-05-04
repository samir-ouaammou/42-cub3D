#include "../cub3D.h"

void	ft_assign_map_config_values(t_map_config *map, char **str)
{
	if (!str || !map)
		ft_exit(-1);
	map->no_texture = ft_split(str[0], ' ')[1];
	map->so_texture = ft_split(str[1], ' ')[1];
	map->we_texture = ft_split(str[2], ' ')[1];
	map->ea_texture = ft_split(str[3], ' ')[1];
	map->floor_color[0] = ft_atoi(ft_split(ft_split(str[4], ' ')[1], ',')[0]);
	map->floor_color[1] = ft_atoi(ft_split(ft_split(str[4], ' ')[1], ',')[1]);
	map->floor_color[2] = ft_atoi(ft_split(ft_split(str[4], ' ')[1], ',')[2]);
	map->ceiling_color[0] = ft_atoi(ft_split(ft_split(str[5], ' ')[1], ',')[0]);
	map->ceiling_color[1] = ft_atoi(ft_split(ft_split(str[5], ' ')[1], ',')[1]);
	map->ceiling_color[2] = ft_atoi(ft_split(ft_split(str[5], ' ')[1], ',')[2]);
	ft_parse_player_and_map_size(map, &str[6]);
}

void	ft_parse_player_and_map_size(t_map_config *map, char **str)
{
	short	i;
	short	j;

	map->map = str;
	map->player_y = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S'
				|| str[i][j] == 'E' || str[i][j] == 'W')
			{
				map->player_x = i;
				map->player_y = j;
			}
		}
		if (map->map_width < j)
			map->map_width = j;
	}
	map->map_height = i;
}
