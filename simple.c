/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayyas <bmayyas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:57:06 by bmayyas           #+#    #+#             */
/*   Updated: 2026/11/09 17:36:15 by bmayyas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_min_position(t_stack *a)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		pos;

	current = a->top;
	min = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack *a)
{
	int	pos;

	pos = find_min_position(a);
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < a->size)
		{
			rra(a);
			pos++;
		}
	}
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (1);
	while (a->size > 0)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
