/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:33:21 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/03 09:10:26 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	wordcounter(char const *s, char sep)
{
	int	index_word;
	int	m;

	index_word = 0;
	m = 0;
	while (s[m])
	{
		while (s[m] && s[m] == sep)
			m++;
		if (s[m] && s[m] != sep)
			index_word++;
		while (s[m] && s[m] != sep)
			m++;
	}
	return (index_word);
}

int	main(int ac, char **av)
{
	t_linked	*stack_a;
	t_linked	*stack_b;
	int			i;
	char		*joined;

	i = 0;
	joined = NULL;
	if (ac == 1)
		exit(0);
	while (i < ac)
	{
		if (ft_strcmp(av[i], " ") == 0 || ft_strcmp(av[i], "") == 0)
			error_printing();
		joined = ft_strjoin(joined, av[i++]);
		joined = ft_strjoin(joined, " ");
	}
	av = ft_split(joined, ' ');
	ac = wordcounter(joined, ' ');
	i = -1;
	check_for_errors(av);
	while (++i < ac)
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			error_printing();
	ft_sort_list2(&stack_a, &stack_b, av, ac);
}
