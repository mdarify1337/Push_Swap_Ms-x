/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:22:07 by mdarify           #+#    #+#             */
/*   Updated: 2022/12/31 10:35:08 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line_bonus.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_linked_list
{
	int						data;
	struct s_linked_list	*next;
	struct s_linked_list	*stack_a;
	struct s_linked_list	*stack_b;
}							t_linked;

t_linked					*ft_lstlast(t_linked *lst);
char						**ft_split(char const *s, char c);
int							check_tab_sorted(int *tab, int k);
void						error_printing(void);
void						tab_to_list(int *arr, t_linked *tmp);
int							*swap_table(int *arr, int j);
void						sort_table(int *tab, int k);
void						check_list(t_linked **stack_a);
t_linked					*ft_lstnew(int data);
void						ft_lstadd_front(t_linked **list, t_linked *new);
int							sml_index(t_linked **stack_a);
void						bring_sml(t_linked **stack_a, int x);
void						sort_three(t_linked **stack_a);
int							ft_atoi(const char *src);
void						all_to_stack_b(t_linked **a, t_linked **b, int j);
void						all_back_to_stack_a(t_linked **a, t_linked **b);
void						sort_big_numbers(t_linked **a, t_linked **b, int j);
int							ft_lst_size(t_linked **stack_a);
void						ft_addfront(t_linked **list, t_linked *new);
void						ft_sort_list2(t_linked **stack_a,
								t_linked **stack_b,
								char **av, int argc);
void						sort_five(t_linked **stack_a, t_linked **stack_b);
void						sort_small_numbers(t_linked **a, t_linked **b,
								int ac);
int							check_index_num(t_linked **st, int k);
void						stack_index(t_linked **a);
int							get_div(int y, int j);
void						push_to_stack_b_push(t_linked **a, t_linked **b,
								int cur, int accumu);
void						sa(t_linked **stack_a, int k);
void						sb(t_linked **stack_a, int k);
void						ft_putstr(char *str);
void						check_for_errors(char **av);
void						check_for_errors2(char **av);
void						check_for_duplicate(char **av);
void						check_for_duplicate2(char **av);
int							ft_sort_list(t_linked **stack_a);
void						ra(t_linked **stack_a, int k);
void						rb(t_linked **stack_b, int k);
int							check_error(const char *str);
void						rra(t_linked **stack_a, int k);
void						rrb(t_linked **stack_b, int k);
void						pa(t_linked **head_a, t_linked **head_b,
								int display);
void						pb(t_linked **head_b, t_linked **head_a,
								int display);
int							check_dup(char **ch, char *str, int j);
void						rr(t_linked **stack_a, t_linked **stack_b);
void						rrr(t_linked **stack_a, t_linked **stack_b);
void						ss(t_linked **stack_a, t_linked **stack_b, int k);
void						ft_lstadd_back(t_linked **lst, t_linked *new);
void						five_number(t_linked **head_a, t_linked **head_b);
void						four_number(t_linked **head_a, t_linked **head_b);
int							minmum(t_linked **head_a);

#endif