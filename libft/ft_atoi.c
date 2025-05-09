/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:14:22 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/04 10:56:32 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	r;

	i = 0;
	r = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ft_print_error("Error\nColor value must be between 0 and 255.\n");
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = (r * 10) + (str[i] - 48);
		if (r > 255)
			ft_print_error("Error\nColor value must be between 0 and 255.\n");
		i++;
	}
	if ((str[i] && str[i]  != '\n')|| r > 255)
		return (-1);
	return (r);
}
