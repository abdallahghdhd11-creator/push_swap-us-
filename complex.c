/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayyas <bmayyas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:29:45 by bmayyas           #+#    #+#             */
/*   Updated: 2026/11/09 17:18:27 by bmayyas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		max = max >> 1;
		bits ++;
	}
	return (bits);
}

void	complex(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;
	int	i;
	int	size;
	
	if (!a || !b || a->size < 2)
		return ;
	rank_indexing(a);
	size = a->size;
	bit = 0;
	max_bits = get_max_bits(size);
	while (max_bits > bit)
	{
		i = 0;
		while (size > i)
		{
		if (((a->top->index >> bit) & 1) == 0)
			pb (a, b);
		else
			ra (a);
		i ++;
		}
		while (b->size > 0)
			pa (a, b);
		bit ++;
	}
}
