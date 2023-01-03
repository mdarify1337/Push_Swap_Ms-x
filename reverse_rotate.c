/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:32:06 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/02 16:01:09 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_linked **stack_a, int k)
{
	t_linked	*temp;
	t_linked	*curr;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	curr = (*stack_a)->next;
	while (curr->next)
	{
		temp = curr;
		curr = curr->next;
	}
	temp->next = NULL;
	curr->next = *stack_a;
	*stack_a = curr;
	if (k == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_linked **stack_b, int k)
{
	t_linked	*temp;
	t_linked	*curr;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	curr = (*stack_b)->next;
	while (curr->next)
	{
		temp = curr;
		curr = curr->next;
	}
	temp->next = NULL;
	curr->next = *stack_b;
	*stack_b = curr;
	if (k == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_linked **stack_a, t_linked **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
}
