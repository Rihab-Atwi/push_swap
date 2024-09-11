/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:17:18 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:17:20 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>

typedef int	t_element;

typedef struct node
{
	t_element		data;
	int				index;
	struct node		*target;
	struct node		*next;
	struct node		*prev;
}*t_stack;

void		sort_three(t_stack *a);
void		min_to_top(t_stack a);
void		fix_min(t_stack *a);
void		ft_while_ab(t_stack *a, t_stack *b,
				void (*f)(t_stack *, t_stack *), int n);
void		ft_while_s(t_stack *s, void (*f)(t_stack *, int), int n);
void		set_target_node_a(t_stack s, t_stack node);
void		set_target_node_b(t_stack s, t_stack node);
void		initialize_t_stack_b(t_stack *a, t_stack *b);
void		push_b(t_stack *b, t_stack *a);
void		push_a_nn(t_stack *a, t_stack *b, int cost_a, int cost_b);
void		push_a_np(t_stack *a, t_stack *b, int cost_a, int cost_b);
void		push_a_pn(t_stack *a, t_stack *b, int cost_a, int cost_b);
void		push_a_pp(t_stack *a, t_stack *b, int cost_a, int cost_b);
void		push_a(t_stack *a, t_stack *b);
void		fix_index(t_stack *st);
int			calculate_cost(t_stack node);
int			cost_to_top(t_stack node, t_stack target_node);
int			get_cost(t_stack s, t_stack node);
t_stack		search_min_cost(t_stack a, t_stack b);
void		free_and_delete_stack(char *ptr, t_stack *s);
const char	*skip_whitespace(const char *str);
char		*extract_word(const char *start, size_t length);
int			process_word(t_stack *s, const char *word);
void		ft_split(t_stack *s, const char *str);
int			check_long(long nb);
int			is_sorted(t_stack s);
void		al_turk_algo(t_stack *a);
void		edge_case_sort(t_stack *a);
long		ft_atol(const char *nptr);
int			is_whitespace(char c);
int			is_valid_integer(const char *s);
int			ft_isspace(char c);
int			ft_isdigit(int c);
int			has_duplicates_t_stack(t_stack s);
int			ft_strcmp(char *s1, char *s2);
int			has_duplicates(int argc, char *argv[]);
t_stack		get_min(t_stack s);
t_stack		get_max(t_stack s);
int			ft_max(int n1, int n2);
int			ft_min(int n1, int n2);
int			ft_abs(int n);
char		*ft_strncpy(char *dest, const char *src, unsigned int n);
int			count_total_nodes(t_stack st);
t_stack		get_head(t_stack s);
t_stack		create_node(t_element data);
t_stack		get_tail(t_stack s);
void		delete_t_stack(t_stack *s);
void		add_head(t_stack *s, t_element data);
void		add_tail(t_stack *s, t_element data);
void		add_node_at_head(t_stack *s, t_stack snode);
void		free_t_stack(t_stack *s);
void		sa(t_stack *a, int flag);
void		sb(t_stack *b, int flag);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a, int flag);
void		rb(t_stack *b, int flag);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a, int flag);
void		rrb(t_stack *b, int flag);
void		rrr(t_stack *a, t_stack *b);
void		swap(t_stack *s);
void		push_to_t_stack(t_stack *s1, t_stack *s2);
void		rotate_t_stack(t_stack *s);
void		reverse_rotate_t_stack(t_stack *s);
void		handle_single_argument(t_stack *s, char *arg);
void		handle_multiple_arguments(int argc, char **argv, t_stack *s);
int			validate_and_add_arguments(int argc, char **argv, t_stack *s);
void		cleanup_and_exit(t_stack *s);
#endif
