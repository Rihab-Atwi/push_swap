/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:15:58 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:16:04 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_three(t_stack *a)
{
	t_stack	max;

	max = get_max(*a);
	while (max->index != 2)
		ra(a, 1);
	if ((*a)->next->data < (*a)->data)
		sa(a, 1);
}

void	min_to_top(t_stack a)
{
	t_stack	min;

	min = get_min(a);
	if (calculate_cost(min) > 0)
	{
		while (min->index != 0)
			ra(&a, 1);
	}
	else
	{
		while (min->index != 0)
			rra(&a, 1);
	}
}

void	fix_min(t_stack *a)
{
	t_stack	min;
	int		med;

	min = get_min(*a);
	med = (count_total_nodes(*a) / 2);
	while (min->index != 0)
	{
		if (min->index > med)
			rra(a, 1);
		else
			ra(a, 1);
	}
}

void	ft_while_ab(t_stack *a, t_stack *b,
		void (*f)(t_stack *, t_stack *), int n)
{
	while (n > 0)
	{
		f(a, b);
		n--;
	}
}

void	ft_while_s(t_stack *s, void (*f)(t_stack *, int), int n)
{
	while (n > 0)
	{
		f(s, 1);
		n--;
	}
}
