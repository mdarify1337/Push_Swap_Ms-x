/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:11:39 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/01 17:39:54 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_atoi(const char *src)
{
	long long	nbr;
	int			sgn;
	int			m;

	sgn = 1;
	nbr = 0;
	m = 0;
	if (!src)
		printing_error();
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
			printing_error();
		m++;
	}
	return ((int)nbr * sgn);
}
