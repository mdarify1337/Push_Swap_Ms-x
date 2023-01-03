/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:08:10 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/31 17:28:59 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_linked **stack_a)
{
	t_linked	*cur;
	int			size;

	cur = *stack_a;
	size = 0;
	if (!(*stack_a))
		return (0);
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

void	push_to_stack_b(t_linked **a, t_linked **b, int cur, int accumu)
{
	int	k;

	k = ((cur / 2) + (accumu / 2));
	if ((*a)->data > k)
	{
		pb(a, b, 1);
		rb(b, 1);
	}
	else
		pb(a, b, 1);
}

void	all_to_stack_b(t_linked **a, t_linked **b, int j)
{
	int	size;
	int	cur;
	int	accumu;

	size = ft_lst_size(a);
	cur = size / j;
	accumu = 0;
	while (*a && ft_lst_size(a) > 5)
	{
		if ((*a) && (*a)->data <= cur && (*a)->data < size - 5)
			push_to_stack_b(a, b, cur, accumu);
		else
			ra(a, 1);
		if (ft_lst_size(b) == cur)
		{
			j = get_div(ft_lst_size(a), j);
			accumu = cur;
			cur += ft_lst_size(a) / j;
		}
	}
}

void	all_back_to_stack_a(t_linked **a, t_linked **b)
{
	int	size;
	int	index;

	size = ft_lst_size(b) - 1;
	while (*b)
	{
		if ((*b)->data == size || (*b)->data == size - 1)
		{
			pa(b, a, 1);
			if ((*a)->data == size)
				size = ft_lst_size(b) - 1;
			if ((*a) && (*a)->next && (*a)->data > (*a)->next->data)
				sa(a, 1);
		}
		else
		{
			index = check_index_num(b, size);
			if ((*b)->next && (*b)->next->data == size)
				sb(b, 1);
			else if (index < size / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
	}
}
