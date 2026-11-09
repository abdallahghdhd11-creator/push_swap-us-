/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayyas <bmayyas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 15:36:53 by bmayyas           #+#    #+#             */
/*   Updated: 2026/11/09 14:58:07 by bmayyas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	total = (long)a->size * (a->size - 1) / 2;
	return ((double)mistakes / total);
}
