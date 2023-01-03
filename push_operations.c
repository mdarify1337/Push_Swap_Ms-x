/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:02:10 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/30 19:39:24 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_linked **head_a, t_linked **head_b, int display)
{
	t_linked	*first;

	if (*head_a == NULL)
		return ;
	first = *head_a;
	*head_a = (*head_a)->next;
	first->next = *head_b;
	*head_b = first;
	if (display == 1)
		write(1, "pa\n", 3);
}

void	pb(t_linked **head_b, t_linked **head_a, int display)
{
	t_linked	*first;

	if (*head_b == NULL)
		return ;
	first = *head_b;
	*head_b = (*head_b)->next;
	first->next = *head_a;
	*head_a = first;
	if (display == 1)
		write(1, "pb\n", 3);
}
