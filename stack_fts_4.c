/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:17:45 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:17:47 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_stack	temp;

	if ((*s) == NULL || (*s)->next == NULL)
		return ;
	temp = (*s)->next;
	if (temp->next != NULL)
		temp->next->prev = *s;
	(*s)->next = temp->next;
	temp->next = *s;
	temp->prev = NULL;
	(*s)->prev = temp;
	*s = temp;
	(*s)->index = 0;
	(*s)->next->index = 1;
}

void	push_to_t_stack(t_stack *s1, t_stack *s2)
{
	t_stack	temp;

	if ((*s1) == NULL || s1 == NULL)
		return ;
	temp = (*s1);
	(*s1) = (*s1)->next;
	if (*s1 != NULL)
		(*s1)->prev = NULL;
	temp->next = NULL;
	add_node_at_head(s2, temp);
	fix_index(s1);
	fix_index(s2);
}

void	rotate_t_stack(t_stack *s)
{
	t_stack	tail;
	t_stack	temp;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	tail = get_tail(*s);
	temp = (*s);
	*s = (*s)->next;
	(*s)->prev = NULL;
	temp->next = NULL;
	tail->next = temp;
	temp->prev = tail;
	fix_index(s);
}

void	reverse_rotate_t_stack(t_stack *s)
{
	t_stack	tail;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	tail = get_tail(*s);
	tail->prev->next = NULL;
	tail->prev = NULL;
	add_node_at_head(s, tail);
	fix_index(s);
}
