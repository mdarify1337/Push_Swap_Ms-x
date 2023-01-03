/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:47:18 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/03 08:31:16 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_linked	*ft_lstnew(int data)
{
	t_linked	*current;

	current = (t_linked *)malloc(sizeof(t_linked));
	if (current == 0)
		return (NULL);
	current->data = data;
	current->next = NULL;
	return (current);
}

void	sort_big_numbers(t_linked **st_a, t_linked **st_b, int k)
{
	stack_index(st_a);
	all_to_stack_b(st_a, st_b, k);
	sort_five(st_a, st_b);
	all_back_to_stack_a(st_a, st_b);
}

int	ft_sort_list(t_linked **stack_a)
{
	t_linked	*new;

	if (!(*stack_a))
		return (1);
	new = *stack_a;
	while (new->next)
	{
		if (new->data > new->next->data)
			return (0);
		new = new->next;
	}
	return (1);
}

void	ft_sort_list2(t_linked **stack_a, t_linked **stack_b, char **av,
		int argc)
{
	t_linked	*new;
	int			i;

	i = 0;
	while (av[++i])
	{
		new = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(stack_a, new);
	}
	if (ft_sort_list(stack_a) == 1)
		return ;
	if (argc == 3)
		sa(stack_a, 1);
	if (argc > 3)
	{
		if (argc <= 6)
			sort_small_numbers(stack_a, stack_b, argc);
		else if (argc > 6 && argc <= 100)
			sort_big_numbers(stack_a, stack_b, 4);
		else if (argc > 100)
			sort_big_numbers(stack_a, stack_b, 7);
	}
}
