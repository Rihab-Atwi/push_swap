/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:16:44 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:16:46 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_index(t_stack *st)
{
	t_stack	s;

	s = *st;
	if (st == NULL || *st == NULL)
		return ;
	if (s->prev == NULL && s->index != 0)
		s->index = 0;
	s = s->next;
	while (s && s->prev != NULL)
	{
		s->index = s->prev->index + 1;
		s = s->next;
	}
}

int	calculate_cost(t_stack node)
{
	int	cost;

	cost = 0;
	if (node->index <= (count_total_nodes(node) / 2))
		cost = node->index;
	else if (node->index > (count_total_nodes(node) / 2))
		cost = -(count_total_nodes(node) - node->index);
	return (cost);
}

int	cost_to_top(t_stack node, t_stack target_node)
{
	int	cost_a;
	int	cost_b;
	int	cost;

	cost_a = 0;
	cost_b = 0;
	cost = 0;
	if (node->index != 0)
		cost_a = calculate_cost(node);
	if (target_node->index != 0)
		cost_b = calculate_cost(target_node);
	if (node->index != 0 && target_node->index != 0)
	{
		if (cost_a * cost_b > 0)
			cost = ft_max(cost_a, cost_b);
		else
		{
			cost = ft_abs(cost_a) + ft_abs(cost_b);
		}
	}
	else
	{
		cost = ft_abs(cost_a) + ft_abs(cost_b);
	}
	return (cost);
}

int	get_cost(t_stack s, t_stack node)
{
	t_stack	target_node;
	int		cost;

	cost = 0;
	set_target_node_a(s, node);
	target_node = node->target;
	if (node->index != 0 || target_node->index != 0)
		cost = cost_to_top(node, target_node);
	return (cost);
}

t_stack	search_min_cost(t_stack a, t_stack b)
{
	int		min;
	int		cost;
	t_stack	min_cost;

	min = INT_MAX;
	min_cost = NULL;
	while (a)
	{
		cost = get_cost(b, a);
		if (cost == 0)
			return (a);
		if (min > cost)
		{
			min = cost;
			min_cost = a;
		}
		a = a->next;
	}
	return (min_cost);
}
