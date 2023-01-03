/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:15:20 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/01 20:46:24 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *src)
{
	long long	nbr;
	int			sgn;
	int			m;

	sgn = 1;
	nbr = 0;
	m = 0;
	if (!src)
		error_printing();
	while (src[m] == 32 || (src[m] >= 9 && src[m] <= 13))
		m++;
	if (src[m] == '-' || src[m] == '+')
	{
		if (src[m] == '-')
			sgn = -1;
		m++;
	}
	while (src[m] >= '0' && src[m] <= '9')
	{
		nbr = nbr * 10 + src[m] - '0';
		if ((nbr > 2147483647 && sgn == 1) || (nbr > 2147483648 && sgn == -1))
			error_printing();
		m++;
	}
	return ((int)nbr * sgn);
}
