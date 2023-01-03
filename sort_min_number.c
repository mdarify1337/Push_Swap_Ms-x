/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:49:35 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/02 21:44:47 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sml_index(t_linked **stack_a)
{
	t_linked	*tmp;
	int			r;
	int			i;
	int			j;

	tmp = *stack_a;
	r = tmp->data;
	i = 0;
	j = 0;
	while (tmp)
	{
		if (tmp->next)
		{
			if (r > tmp->next->data)
			{
				r = tmp->next->data;
				j = i + 1;
			}
		}
		i++;
		tmp = tmp->next;
	}
	return (j);
}

void	bring_sml(t_linked **stack_a, int x)
{
	int	i;
	int	y;

	i = ft_lst_size(stack_a);
	y = x;
	if (x >= i / 2)
	{
		while (x < i)
		{
			rra(stack_a, 1);
			x++;
		}
	}
	if (y < i / 2)
	{
		while (y > 0)
		{
			ra(stack_a, 1);
			y--;
		}
	}
}

void	sort_five(t_linked **stack_a, t_linked **stack_b)
{
	int	x;
	int	y;

	x = sml_index(stack_a);
	y = 2;
	while (y > 0)
	{
		bring_sml(stack_a, x);
		pb(stack_a, stack_b, 1);
		x = sml_index(stack_a);
		y--;
	}
	sort_three(stack_a);
	pa(stack_b, stack_a, 1);
	pa(stack_b, stack_a, 1);
}
