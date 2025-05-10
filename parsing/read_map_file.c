#include "../cub3D.h"

char	*ft_replace_whitespace_with_space(char *str)
{
	short	i;
	char	*res;

	if (!str)
		return (NULL);
	res = ft_malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!res)
		ft_print_error("Error\nMemory allocation failed (malloc)\n");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
			res[i] = ' ';
		else
			res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_read_map_file(t_parsing *data, short nbr, short bol)
{
	ft_init_parsing(data);
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			break ;
		data->line = ft_replace_whitespace_with_space(data->line);
		if (nbr < 6)
			data->line = ft_strtrim(data->line, " ");
		if (data->line[0] == '\n' && bol)
			bol = 42;
		if (data->line[0] != '\n')
		{
			if (bol == 42 && ft_strtrim(data->line, " \t\n\v\f\r"))
				ft_print_error("Erro\nThere is a blank line in the map.\n");
			else if (nbr < 4)
				ft_check_texture_is_valid(data, data->line, nbr);
			else if (nbr < 6)
				ft_check_colors_is_valid(data, data->line, nbr);
			else
				bol = ft_map_join(data);
			nbr++;
		}
	}
}

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

int	ft_map_join(t_parsing *data)
{
	data->tmp = ft_strjoin(data->str, data->line);
	if (!data->tmp)
		ft_print_error("Error\nMemory allocation failed (malloc)\n");
	data->str = data->tmp;
	return (1);
}
