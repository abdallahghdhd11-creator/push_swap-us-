/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayyas <bmayyas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:10:53 by bmayyas           #+#    #+#             */
/*   Updated: 2026/11/09 14:44:36 by bmayyas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_stak *a, t_stak *b)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		simple(a, b);
	else if (disorder >= 0.2 && disorder <= 0.5)
		medium(a, b);
	else
		complex(a, b);
}
