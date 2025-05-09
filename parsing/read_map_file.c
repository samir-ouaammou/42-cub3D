#include "../cub3D.h"

short	ft_count_len(char **strs)
{
	short	i;

	if (!strs)
		ft_exit(-1);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}
void	ft_read_map_file(t_parsing *data)
{
	short	i;
	short	nbr;
	short	bol;

	ft_init_parsing(data);
	i = 1;
	nbr = 0;
	bol = 0;
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			break;
		data->line = ft_strtrim(data->line, " \t\v\f\r");
		if (data->line[0] == '\n' && bol)
			ft_print_error("Erro\nThere is a blank line in the map.\n");
		if (data->line[0] != '\n')
		{
			if (nbr < 4)
				ft_check_texture_is_valid(data, data->line, nbr);
			else if (nbr < 6)
				ft_check_colors_is_valid(data, data->line, nbr);
			else
			{
				data->tmp = ft_strjoin(data->str, data->line);
				if (!data->tmp)
					ft_print_error("Error\nMemory allocation failed (malloc)\n");
				data->str = data->tmp;
				bol = 1;
			}
			nbr++;
		}
	}

}
