/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:20:41 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/25 11:24:14 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_linked **stack_a, int k)
{
	int	swap;

	if (!(*stack_a) || !(*stack_a)->next || !(stack_a))
		return ;
	swap = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = swap;
	if (k == 1)
		write(1, "sa\n", 3);
}

void	sb(t_linked **stack_a, int k)
{
	int	swap;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	swap = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = swap;
	if (k == 1)
		write(1, "sb\n", 3);
}

void	ss(t_linked **stack_a, t_linked **stack_b, int k)
{
	sa(stack_a, k);
	sb(stack_b, k);
}
