#include "../cub3D.h"

void	ft_check_dor_errors(char **map, short i, short j)
{
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == 'D' || map[i][j] == 'O')
				&& (map[i][j - 1] != '1' || map[i][j + 1] != '1'
				|| ft_strlen(map[i - 1]) < j || ft_strlen(map[i + 1]) < j
				|| map[i - 1][j] == ' ' || map[i + 1][j] == ' '))
				ft_print_error("error dooooooooooooooooooooooooor\n");
		}
	}
}