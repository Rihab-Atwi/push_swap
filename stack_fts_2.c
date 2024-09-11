/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:17:33 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:17:37 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b, int flag)
{
	swap(b);
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	push_to_t_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push_to_t_stack(a, b);
	write(1, "pb\n", 3);
}

void	ra(t_stack *a, int flag)
{
	rotate_t_stack(a);
	if (flag == 1)
		write(1, "ra\n", 3);
}
