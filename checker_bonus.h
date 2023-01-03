/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:43:58 by mdarify           #+#    #+#             */
/*   Updated: 2023/01/01 20:57:00 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line_bonus.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_linked_list
{
	int						data;
	struct s_linked_list	*next;
}							t_linked;

int							ft_strcmp(const char *s1, const char *s2);
int							ft_strncmp(const char *s2, const char *s1,
								size_t len);
t_linked					*ft_lstnew(int data);
t_linked					*ft_lstlast(t_linked *lst);
void						ft_lstadd_back(t_linked **lst, t_linked *new);
void						push(t_linked **head, int value);
void						check_list(t_linked **stack_a, t_linked **stack_b);
void						checker_helper(t_linked **head_a, t_linked **head_b,
								char *saver);
void						checker_job(t_linked **head_a, t_linked **head_b);
void						sa(t_linked **stack_a);
void						sb(t_linked **stack_b);
void						ss(t_linked **stack_a, t_linked **stack_b);
void						pa(t_linked **head_a, t_linked **head_b);
void						pb(t_linked **head_a, t_linked **head_b);
void						ra(t_linked **stack_a);
void						rb(t_linked **stack_b);
void						rr(t_linked **stack_a, t_linked **stack_b);
void						rra(t_linked **stack_a);
void						rrb(t_linked **stack_b);
void						rrr(t_linked **stack_a, t_linked **stack_b);
void						check(t_linked **stack_a, int i, char **argv);
void						printing_error(void);
int							check_sort_list(t_linked **list);
int							ft_atoi(const char *src);
void						check_for_errors2(char **av);
void						check_for_duplicate2(char **av);
int							word_counter(char const *s, char sep);
char						**ft_split(char const *s, char c);

#endif
