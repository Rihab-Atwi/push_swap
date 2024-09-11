/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:17:14 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:17:16 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	get_min(t_stack s)
{
	t_stack		min_node;
	t_element	min;

	if (s == NULL)
		return (NULL);
	if (s->prev == NULL && s->next == NULL)
		return (s);
	min_node = s;
	min = s->data;
	while (s != NULL)
	{
		if (s->data < min)
		{
			min = s->data;
			min_node = s;
		}
		s = s->next;
	}
	return (min_node);
}

t_stack	get_max(t_stack s)
{
	t_stack		max_node;
	t_element	max;

	if (s == NULL)
		return (NULL);
	if (s->prev == NULL && s->next == NULL)
		return (s);
	max_node = s;
	max = s->data;
	while (s != NULL)
	{
		if (s->data > max)
		{
			max = s->data;
			max_node = s;
		}
		s = s->next;
	}
	return (max_node);
}

int	ft_max(int n1, int n2)
{
	n1 = ft_abs(n1);
	n2 = ft_abs(n2);
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	ft_min(int n1, int n2)
{
	n1 = ft_abs(n1);
	n2 = ft_abs(n2);
	if (n1 < n2)
		return (n1);
	return (n2);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
