/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:17:39 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:17:41 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b, int flag)
{
	rotate_t_stack(b);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a, int flag)
{
	reverse_rotate_t_stack(a);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int flag)
{
	reverse_rotate_t_stack(b);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
