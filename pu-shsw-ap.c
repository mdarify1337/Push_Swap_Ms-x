/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu-shsw-ap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:04:04 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/03 09:10:02 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_printing(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_for_errors(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (!av[i][0])
			error_printing();
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if ((av[i][j] >= '0' && av[i][j] <= '9') &&
				(av[i][j + 1] == '-' || av[i][j + 1] == '+'))
				error_printing();
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				error_printing();
			j++;
		}
		i++;
	}
	check_for_duplicate(av);
}

void	check_for_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error_printing();
			j++;
		}
		i++;
	}
}
