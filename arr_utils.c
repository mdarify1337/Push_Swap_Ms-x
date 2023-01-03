/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:28:04 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/30 20:59:07 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_tab_sorted(int *tab, int k)
{
	int	i;

	i = 1;
	if (!tab)
		return (1);
	while (i < k)
	{
		if (tab[i] < tab[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	tab_to_list(int *tab, t_linked *new)
{
	int	i;

	i = 0;
	while (new)
	{
		tab[i] = new->data;
			i++;
		new = new->next;
	}
}

void	sort_table(int *tab, int k)
{
	int	swap;
	int	j;

	j = 1;
	while (!check_tab_sorted(tab, k))
	{
		if (tab[j] < tab[j - 1])
		{
			swap = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = swap;
		}
		j++;
		if (j == k)
			j = 1;
	}
}
