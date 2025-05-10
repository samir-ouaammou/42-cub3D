#include "../cub3D.h"

void	ft_init_parsing(t_parsing *data)
{
	data->line = NULL;
	data->split = NULL;
	data->tmp = NULL;
	data->str = NULL;
	data->map = NULL;
}

void	ft_print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	ft_exit(-1);
}

t_map_config	*ft_parsing_map_file(t_map_config *map, char *filename)
{
	t_parsing	data;
	short		len;

	ft_init_parsing(&data);
	data.data = map;
	data.str = ft_strrchr(filename, '/');
	if (data.str && data.str[0] == '/' && data.str[1] && data.str[1] == '.')
		filename = &data.str[1];
	len = ft_strlen(filename);
	if ((len < 5) || (ft_strcmp(&filename[len - 4], ".cub") != 0))
	{
		write(2, "Error\nInvalid map file name. ", 29);
		ft_print_error("Please use a valid file, like map.cub\n");
	}
	data.fd = open(filename, O_RDONLY);
	if (data.fd == -1)
		ft_print_error("Error\nError opening file map\n");
	ft_read_map_file(&data, 0, 0);
	data.map = ft_split(data.str, '\n');
	ft_check_elements(data.map, -1, -1, ft_count_len(data.map));
	ft_player_location_and_map_size(&data, data.map);
	return (data.data);
}
