/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:16:38 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:16:41 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_long(long nb)
{
	if (nb >= INT_MAX || nb <= INT_MIN)
		return (0);
	return (1);
}

int	is_sorted(t_stack s)
{
	while (s->next != NULL)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	return (1);
}

void	al_turk_algo(t_stack *a)
{
	t_stack	b;

	b = NULL;
	push_a(a, &b);
	sort_three(a);
	push_b(&b, a);
	fix_min(a);
	delete_t_stack(&b);
}

void	edge_case_sort(t_stack *a)
{
	if (is_sorted(*a))
	{
		delete_t_stack(a);
		return ;
	}
	if (count_total_nodes(*a) == 2)
	{
		sa(a, 1);
		delete_t_stack(a);
		return ;
	}
	if (count_total_nodes(*a) == 3)
	{
		sort_three(a);
		delete_t_stack(a);
		return ;
	}
	al_turk_algo(a);
	delete_t_stack(a);
}
