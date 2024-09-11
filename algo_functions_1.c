/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:16:25 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:16:27 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_node_a(t_stack s, t_stack node)
{
	t_element	e;
	t_stack		temp;
	t_stack		max;

	e = INT_MIN;
	temp = NULL;
	max = s;
	if (s == NULL)
		exit(-1);
	while (s != NULL)
	{
		if (s->data < node->data && e < s->data)
		{
			temp = s;
			e = temp->data;
		}
		s = s->next;
	}
	if (temp == NULL)
		node->target = get_max(max);
	else
		node->target = temp;
}

void	set_target_node_b(t_stack s, t_stack node)
{
	t_element	e;
	t_stack		temp;
	t_stack		min;

	e = INT_MAX;
	temp = NULL;
	min = s;
	if (s == NULL)
		exit(-1);
	while (s != NULL)
	{
		if (s->data > node->data && e > s->data)
		{
			temp = s;
			e = temp->data;
		}
		s = s->next;
	}
	if (temp == NULL)
		node->target = get_min(min);
	else
		node->target = temp;
}

void	initialize_t_stack_b(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	while (count_total_nodes(*a) > 3 && count < 2)
	{
		pb(a, b);
		count++;
	}
}

void	push_b(t_stack *b, t_stack *a)
{
	while (count_total_nodes(*b) != 0)
	{
		set_target_node_b(*a, (*b));
		if ((*b)->target->index != 0)
		{
			if (calculate_cost((*b)->target) < 0)
			{
				while ((*b)->target->index != 0)
					rra(a, 1);
			}
			else
			{
				while ((*b)->target->index != 0)
					ra(a, 1);
			}
		}
		pa(a, b);
	}
}
