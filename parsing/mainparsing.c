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

void	ft_map_for_exomple(void)
{
	printf("Error\nMissing blank line before the map layout. A newline");
	printf(" is required between texture/color definitions and the map.\n");
	printf("Expected format:\n\nNO ./path_to_the_north_texture\n");
	printf("SO ./path_to_the_south_texture\nWE ./path_to_the_west_texture\n");
	printf("EA ./path_to_the_east_texture\n\nF 220,100,0\nC 225,30,0\n");
	printf("1111111111111111\n1000N00000000011\n1111111111111111\n");
	ft_exit(-1);
}

void	ft_read_map_file(t_parsing *data)
{
	int	i;

	if (!data)
		ft_exit(-1);
	ft_init_parsing(data);
	i = 1;
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line && i != 1)
			break ;
		if ((!data->line || data->line[0] == '\n') && i != 5 && i != 8)
		{
			printf("Error\nEmpty line detected at line [%d].\n", i);
			ft_exit(-1);
		}
		if ((i == 5 || i == 8) && data->line[0] != '\n')
			ft_map_for_exomple();
		data->tmp = ft_strjoin(data->str, data->line);
		if (!data->tmp)
			ft_print_error("Error\nFailed to read the file.\n");
		data->str = data->tmp;
		i++;
	}
	data->map = ft_split(data->str, '\n');
}

short	ft_count_len(char **strs, short i)
{
	if (!strs)
		ft_exit(-1);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	ft_check_texture_is_valid(t_parsing *data)
{
	data->split = ft_split(data->map[0], ' ');
	if (ft_count_len(data->split, 0) != 2 || ft_strcmp(data->split[0], "NO"))
		ft_print_error("Error\nInvalid texture identifier. Expected 'NO'.\n");
	if (open(data->split[1], O_RDONLY) == -1)
		return (write(2, "Error\nInvalid path for north texture (NO). ", 43),
			ft_print_error("Please provide a valid file path.\n"), 0);
	data->split = ft_split(data->map[1], ' ');
	if (ft_count_len(data->split, 0) != 2 || ft_strcmp(data->split[0], "SO"))
		ft_print_error("Error\nInvalid texture identifier. Expected 'SO'.\n");
	if (open(data->split[1], O_RDONLY) == -1)
		return (write(2, "Error\nInvalid path for south texture (SO). ", 43),
			ft_print_error("Please provide a valid file path.\n"), 0);
	data->split = ft_split(data->map[2], ' ');
	if (ft_count_len(data->split, 0) != 2 || ft_strcmp(data->split[0], "WE"))
		ft_print_error("Error\nInvalid texture identifier. Expected 'WE'.\n");
	if (open(data->split[1], O_RDONLY) == -1)
		return (write(2, "Error\nInvalid path for west texture (WE). ", 42),
			ft_print_error("Please provide a valid file path.\n"), 0);
	data->split = ft_split(data->map[3], ' ');
	if (ft_count_len(data->split, 0) != 2 || ft_strcmp(data->split[0], "EA"))
		ft_print_error("Error\nInvalid texture identifier. Expected 'EA'.\n");
	if (open(data->split[1], O_RDONLY) == -1)
		return (write(2, "Error\nInvalid path for east texture (EA). ", 42),
			ft_print_error("Please provide a valid file path.\n"), 0);
	return (0);
}

int	ft_check_floor_color(t_parsing *data, int i, int len)
{
	if (!data)
		ft_exit(-1);
	data->split = ft_split(data->map[4], ' ');
	if (ft_count_len(data->split, 0) != 2 || ft_strcmp(data->split[0], "F"))
		return (write(2, "Error\nInvalid floor color. Expected: ", 37)
			, ft_print_error("F R,G,B (e.g. F 220,100,0)\n"), 0);
	while (data->split && data->split[1][++i])
	{
		if (data->split[1][i] == ',' && data->split[1][i + 1]
			&& data->split[1][i + 1] == ',')
			return (write(2, "Error\nfloor color format error — ", 33),
				ft_print_error("double comma found.\n"), 0);
		if (data->split[1][i] == ',')
			len++;
	}
	data->split = ft_split(data->split[1], ',');
	if (len != 2 || ft_count_len(data->split, 0) != 3)
		return (write(2, "Error\nInvalid floor color — repeated ,detected.", 49)
			, ft_print_error(" Format must be: F R,G,B.\n"), 0);
	if (ft_atoi(data->split[0]) == -1 || ft_atoi(data->split[1]) == -1
		|| ft_atoi(data->split[2]) == -1)
		return (write(2, "Error\nFloor color must contain only ", 36),
			ft_print_error("integers. Invalid characters detected.\n"), 0);
	return (0);
}

int	ft_check_ceiling_color(t_parsing *data, int i, int len)
{
	data->split = ft_split(data->map[5], ' ');
	if (ft_count_len(data->split, 0) != 2 || ft_strcmp(data->split[0], "C"))
	{
		write(2, "Error\nInvalid ceiling color format. Expected: ", 46);
		ft_print_error("C R,G,B (e.g. C 225,30,0).\n");
	}
	while (data->split && data->split[1][++i])
	{
		if (data->split[1][i] == ',' && data->split[1][i + 1]
			&& data->split[1][i + 1] == ',')
			return (write(2, "Error\nCeiling color format error", 32),
				ft_print_error(" — double comma found.\n"), 0);
		if (data->split[1][i] == ',')
			len++;
	}
	data->split = ft_split(data->split[1], ',');
	if (len != 2 || ft_count_len(data->split, 0) != 3)
		return (write(2, "Error\nCeiling color format error — double ','", 47)
			, ft_print_error(" found. Expected: C R,G,B.\n"), 0);
	if (ft_atoi(data->split[0]) == -1 || ft_atoi(data->split[1]) == -1
		|| ft_atoi(data->split[2]) == -1)
		return (write(2, "Error\nCeiling color must contain only integers.", 47)
			, ft_print_error(" Invalid characters detected.\n"), 0);
	return (0);
}

int	ft_cheh_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	ft_check_map(char **map, int i, int j, int player)
{
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_cheh_is_player(map[i][j]) && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != ' ')
			{
				write(2, "Error\nInvalid character found. Only '1', '0', ", 46);
				ft_print_error("'N', 'S', 'E', 'W', and space are allowed.\n");
			}
			if (ft_cheh_is_player(map[i][j]))
				player++;
		}
	}
	if (player != 1)
	{
		write(2, "Error\nThere must be exactly one player starting position ",
			57);
		ft_print_error("('N', 'S', 'E', or 'W') in the map.\n");
	}
}

void	ft_check_elements(char **map, int i, int j, int len)
{
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || ft_cheh_is_player(map[i][j]))
			{
				if (i == 0 || j == 0 || i == len - 1 || j == ft_strlen(map[i])
					- 1 || !map[i][j + 1] || map[i][j + 1] == ' ' || map[i][j
					- 1] == ' ' || !map[i + 1][j] || map[i + 1][j] == ' '
					|| map[i - 1][j] == ' ' || ft_strlen(map[i + 1]) < j + 1
					|| ft_strlen(map[i - 1]) < j + 1)
				{
					printf("Error\nMap is not closed around (%d,%d).\n", i + 9,
						j + 1);
					ft_exit(-1);
				}
			}
		}
	}
}

void	ft_check_map_elements(t_parsing *data)
{
	if (!data)
		ft_exit(-1);
	ft_check_texture_is_valid(data);
	ft_check_floor_color(data, -1, 0);
	ft_check_ceiling_color(data, -1, 0);
	ft_check_map(&data->map[6], -1, 0, 0);
	ft_check_elements(&data->map[6], -1, 0, ft_count_len(&data->map[6], 0));
}

char	**ft_parsing(char *filename)
{
	t_parsing	data;
	int			len;

	ft_init_parsing(&data);
	data.str = ft_strrchr(filename, '/');
	if (data.str && data.str[0] == '/' && data.str[1] && data.str[1] == '.')
		filename = data.str;
	len = ft_strlen(filename);
	if ((len < 5) || (ft_strcmp(&filename[len - 4], ".cub") != 0))
	{
		write(2, "Error\nInvalid map file name. ", 29);
		ft_print_error("Please use a valid file, like map.cub\n");
	}
	data.fd = open(filename, O_RDONLY);
	if (data.fd == -1)
		ft_print_error("Error\nError opening file map\n");
	ft_read_map_file(&data);
	if (ft_count_len(data.map, 0) < 9)
		ft_print_error("Error\nInvalid map.\n");
	ft_check_map_elements(&data);
	return (data.map);
}
