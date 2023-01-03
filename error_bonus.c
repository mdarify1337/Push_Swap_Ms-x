/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:14:15 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/01 21:40:39 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_linked	*ft_lstnew(int data)
{
	t_linked	*current;

	current = (t_linked *)malloc(sizeof(t_linked));
	if (!current)
		return (NULL);
	current->data = data;
	current->next = (NULL);
	return (current);
}

t_linked	*ft_lstlast(t_linked *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_linked **lst, t_linked *new)
{
	t_linked	*current;

	if (*lst)
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
	else
	{
		*lst = new;
		new->next = (NULL);
		return ;
	}
}

void	check_for_errors2(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (!av[i][0])
			printing_error();
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if ((av[i][j] >= '0' && av[i][j] <= '9') &&
				(av[i][j + 1] == '-' || av[i][j + 1] == '+'))
				printing_error();
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				printing_error();
			j++;
		}
		i++;
	}
	check_for_duplicate2(av);
}

void	check_for_duplicate2(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				printing_error();
			j++;
		}
		i++;
	}
}
