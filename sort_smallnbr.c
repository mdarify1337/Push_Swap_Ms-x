/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:28:33 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/30 18:14:23 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_linked **s_a)
{
	int	i;
	int	j;
	int	k;

	i = (*s_a)->data;
	j = (*s_a)->next->data;
	k = (*s_a)->next->next->data;
	if (i > j && i > k && j < k)
		ra(s_a, 1);
	if (i > j && i > k && j > k)
	{
		ra(s_a, 1);
		sa(s_a, 1);
	}
	if (i < j && j > k && i > k)
		rra(s_a, 1);
	if (i < j && j > k && i < k)
	{
		sa(s_a, 1);
		ra(s_a, 1);
	}
	if (i < k && j < k && i > j)
		sa(s_a, 1);
}

int	minmum(t_linked **head_a)
{
	int			min;
	t_linked	*temp;

	min = (*head_a)->data;
	temp = *head_a;
	while (temp != NULL)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

void	four_number(t_linked **head_a, t_linked **head_b)
{
	int			min;
	t_linked	*temp;

	temp = *head_a;
	min = minmum(head_a);
	while (temp != NULL)
	{
		if (temp->data != min)
			ra(head_a, 1);
		else if (temp->data == min)
		{
			pb(head_a, head_b, 1);
			sort_three(head_a);
			pa(head_a, head_b, 1);
			break ;
		}
		temp = *head_a;
	}
}

void	five_number(t_linked **head_a, t_linked **head_b)
{
	int	x;
	int	y;

	x = sml_index(head_a);
	y = 2;
	while (y > 0)
	{
		bring_sml(head_a, x);
		pb(head_a, head_b, 1);
		x = sml_index(head_a);
		y--;
	}
	sort_three(head_a);
	pa(head_b, head_a, 1);
	pa(head_b, head_a, 1);
}

void	sort_small_numbers(t_linked **a, t_linked **b, int ac)
{
	if (ac == 4)
		sort_three(a);
	if (ac == 5)
		four_number(a, b);
	if (ac == 6)
		five_number(a, b);
}
