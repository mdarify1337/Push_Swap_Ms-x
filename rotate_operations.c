/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:21:42 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/30 19:44:02 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_linked **stack_a, int k)
{
	t_linked	*head;
	t_linked	*cur;

	head = *stack_a;
	if (head == NULL || head->next == NULL)
		return ;
	*stack_a = head->next;
	head->next = NULL;
	cur = *stack_a;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = head;
	if (k == 1)
		write(1, "ra\n", 3);
}

void	rb(t_linked **stack_b, int k)
{
	t_linked	*head;
	t_linked	*cur;

	head = *stack_b;
	if (head == NULL || head->next == NULL)
		return ;
	*stack_b = head->next;
	head->next = NULL;
	cur = *stack_b;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = head;
	if (k == 1)
		write(1, "rb\n", 3);
}

void	rr(t_linked **stack_a, t_linked **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
