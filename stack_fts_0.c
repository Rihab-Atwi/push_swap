/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:17:22 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:17:27 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total_nodes(t_stack st)
{
	int		count;
	t_stack	s;

	count = 0;
	s = get_head(st);
	while (s)
	{
		count++;
		s = s->next;
	}
	return (count);
}

t_stack	get_head(t_stack s)
{
	if (s == NULL)
		return (NULL);
	while (s->prev != NULL)
		s = s->prev;
	return (s);
}

t_stack	create_node(t_element data)
{
	t_stack	newnode;

	newnode = (t_stack)malloc(sizeof(struct node));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->target = NULL;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

t_stack	get_tail(t_stack s)
{
	if (s == NULL)
		return (NULL);
	while (s->next != NULL)
		s = s->next;
	return (s);
}

void	delete_t_stack(t_stack *s)
{
	t_stack	temp;

	if (s == NULL)
		return ;
	while (*s != NULL)
	{
		temp = (*s)->next;
		free(*s);
		*s = temp;
	}
}
