/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:15:01 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/31 10:21:08 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_index_num(t_linked **st, int k)
{
	t_linked	*tmp;
	int			frst;
	int			lst;
	int			i;

	tmp = *st;
	frst = 0;
	lst = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->data == k)
		{
			if (frst == 0)
				frst = i;
			lst = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (frst <= ft_lst_size(st) - lst)
		return (frst);
	return (lst);
}

void	stack_index(t_linked **a)
{
	int			*arr;
	t_linked	*tmp;
	int			k;
	int			i;

	i = 0;
	k = ft_lst_size(a);
	arr = malloc((k * sizeof(int)) + 1);
	tab_to_list(arr, *a);
	sort_table(arr, k);
	tmp = *a;
	while (i < k && tmp)
	{
		if (tmp->data == arr[i])
		{
			tmp->data = i;
			tmp = tmp->next;
			i = -1;
		}
		i++;
	}
	free(arr);
}

int	get_div(int y, int j)
{
	if (y >= 350 && y <= 450)
		j = 7;
	if (y >= 250 && y < 350)
		j = 6;
	if (y > 100 && y < 250)
		j = 4;
	if (y <= 100)
		j = 3;
	if (y <= 50)
		j = 4;
	return (j);
}
