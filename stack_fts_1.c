/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:17:29 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:17:31 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_head(t_stack *s, t_element data)
{
	t_stack	new_node;

	new_node = create_node(data);
	if (!new_node)
		exit(1);
	if (*s == NULL)
		(*s) = new_node;
	else
	{
		new_node->next = *s;
		(*s)->prev = new_node;
		*s = new_node;
	}
	fix_index(s);
}

void	add_tail(t_stack *s, t_element data)
{
	t_stack	new_node;
	t_stack	curr;

	curr = *s;
	new_node = create_node(data);
	if (!new_node)
		exit(1);
	if (*s == NULL)
	{
		(*s) = new_node;
		new_node->index = 0;
	}
	else
	{
		curr = get_tail(*s);
		curr ->next = new_node;
		new_node->prev = curr;
		new_node->index = (curr-> index) + 1;
	}
}

void	add_node_at_head(t_stack *s, t_stack snode)
{
	if (!snode || s == NULL)
		exit(1);
	if (*s == NULL)
		(*s) = snode;
	else
	{
		snode->next = (*s);
		(*s)->prev = snode;
		(*s) = snode;
	}
	fix_index(s);
}

void	free_t_stack(t_stack *s)
{
	t_stack	temp;

	while (*s != NULL)
	{
		temp = *s;
		*s = (*s)->next;
		free(temp);
	}
}

void	sa(t_stack *a, int flag)
{
	swap(a);
	if (flag == 1)
		write(1, "sa\n", 3);
}
