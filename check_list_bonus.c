/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:54:50 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/30 12:47:14 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s2, const char *s1, size_t len)
{
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	i = 0;
	while (i < len && (src[i] || dst[i]))
	{
		if (src[i] != dst[i])
			return (dst[i] - src[i]);
		i++;
	}
	return (0);
}

int	check_sort_list(t_linked **list)
{
	t_linked	*check;

	if (!(*list))
		return (1);
	check = *list;
	while (check)
	{
		if ((check->next) && check->data > check->next->data)
			return (0);
		check = check->next;
	}
	return (1);
}

void	check_list(t_linked **stack_a, t_linked **stack_b)
{
	if (check_sort_list(stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	checker_helper(t_linked **head_a, t_linked **head_b, char *saver)
{
	if (ft_strncmp(saver, "ra\n", 3) == 0)
		ra(head_a);
	else if (ft_strncmp(saver, "rb\n", 3) == 0)
		rb(head_b);
	else if (ft_strncmp(saver, "rrb\n", 4) == 0)
		rrb(head_b);
	else if (ft_strncmp(saver, "rrr\n", 4) == 0)
		rrr(head_a, head_b);
	else if (ft_strncmp(saver, "rra\n", 4) == 0)
		rra(head_a);
	else if (ft_strncmp(saver, "rr\n", 3) == 0)
		rr(head_a, head_b);
	else
		printing_error();
}

void	checker_job(t_linked **head_a, t_linked **head_b)
{
	char	*saver;

	while (1)
	{
		saver = get_next_line(0);
		if (!saver || saver[0] == '\n')
			break ;
		if (ft_strncmp(saver, "pa\n", 3) == 0)
			pa(head_b, head_a);
		else if (ft_strncmp(saver, "pb\n", 3) == 0)
			pb(head_a, head_b);
		else if (ft_strncmp(saver, "sa\n", 3) == 0)
			sa(head_a);
		else if (ft_strncmp(saver, "sb\n", 3) == 0)
			sb(head_b);
		else if (ft_strncmp(saver, "ss\n", 3) == 0)
			ss(head_a, head_b);
		else
			checker_helper(head_a, head_b, saver);
		free(saver);
	}
	check_list(head_a, head_b);
}
