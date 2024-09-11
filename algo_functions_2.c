/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:16:32 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:16:34 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_nn(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	int	min;

	min = ft_min(cost_a, cost_b);
	ft_while_ab(a, b, &rrr, min);
	if (ft_abs(cost_a) > ft_abs(cost_b))
		ft_while_s(a, &rra, ft_abs(cost_a) - min);
	else
		ft_while_s(b, &rrb, ft_abs(cost_b) - min);
}

void	push_a_np(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	ft_while_s(a, &rra, ft_abs(cost_a));
	ft_while_s(b, &rb, cost_b);
}

void	push_a_pn(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	ft_while_s(a, &ra, cost_a);
	ft_while_s(b, &rrb, ft_abs(cost_b));
}

void	push_a_pp(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	int	min;

	min = ft_min(cost_a, cost_b);
	ft_while_ab(a, b, &rr, min);
	if (cost_a > cost_b)
		ft_while_s(a, &ra, cost_a - min);
	else
		ft_while_s(b, &rb, cost_b - min);
}

void	push_a(t_stack *a, t_stack *b)
{
	t_stack	node_to_push;
	int		cost_a;
	int		cost_b;

	initialize_t_stack_b(a, b);
	while (count_total_nodes(*a) > 3)
	{
		node_to_push = search_min_cost(*a, *b);
		cost_a = calculate_cost(node_to_push);
		cost_b = calculate_cost(node_to_push->target);
		if (node_to_push->target->index != 0 || node_to_push->index != 0)
		{
			if (cost_a <= 0 && cost_b <= 0)
				push_a_nn(a, b, cost_a, cost_b);
			else if (cost_a >= 0 && cost_b <= 0)
				push_a_pn(a, b, cost_a, cost_b);
			else if (cost_a <= 0 && cost_b >= 0)
				push_a_np(a, b, cost_a, cost_b);
			else if (cost_a >= 0 && cost_b >= 0)
				push_a_pp(a, b, cost_a, cost_b);
		}
		pb(a, b);
	}
}
