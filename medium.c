/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayyas <bmayyas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:01:37 by bmayyas           #+#    #+#             */
/*   Updated: 2026/11/04 16:43:04 by bmayyas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk <= size / chunk)
		chunk++;
	return (chunk);
}

static int	find_chunk_position(t_stack *a, int end)
{
	t_node	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if (cur->index < end)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	end;
	int	pos;

	end = chunk;
	while (a->size > 0)
	{
		pos = find_chunk_position(a, end);
		if (pos == -1)
		{
			end += chunk;
			continue ;
		}
		while (pos-- > 0)
			ra(a);
		pb(a, b);
	}
}

static int	find_max_position(t_stack *b)
{
	t_node	*cur;//pointer to trans btween noods
	int		pos;//pleac of that nood we chek it
	int		max_pos;// alocetion of max index
	int		max;// a max of that elment

	cur = b->top;
	pos = 0;
	max_pos = 0;
	max = cur->index;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

void	medium(t_stak *a, t_stak *b)
{
	int	pos;

	if (!a || !b || a->size < 2)
		return ;
	push_chunks(a, b, get_chunk_size(a->size));
	while (b->size > 0)
	{
		pos = find_max_position(b);
		if (pos <= b->size /2)
			while (pos -- > 0)
				rb(b);
		else
			while (pos++ < b->size)
				rrb(b);
		pa(a, b);
	}
}
