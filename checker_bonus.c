/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:12:07 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/02 15:53:52 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	printing_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
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

void	push(t_linked **head, int value)
{
	t_linked	*new;

	new = ft_lstnew(value);
	ft_lstadd_back(head, new);
}

void	check(t_linked **stack_a, int i, char **argv)
{
	if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		printing_error();
	push(stack_a, ft_atoi(argv[i]));
}

int	main(int ac, char **av)
{
	t_linked	*stack_a;
	t_linked	*stack_b;
	char		*joined;
	int			i;

	i = 1;
	joined = NULL;
	if (ac == 1)
		exit(0);
	while (i < ac)
	{
		if (ft_strcmp(av[i], " ") == 0 || ft_strcmp(av[i], "") == 0)
			printing_error();
		joined = ft_strjoin(joined, av[i++]);
		joined = ft_strjoin(joined, " ");
	}
	av = ft_split(joined, ' ');
	ac = word_counter(joined, ' ');
	i = -1;
	check_for_errors2(av);
	while (++i < ac)
		check(&stack_a, i, av);
	checker_job(&stack_a, &stack_b);

}
