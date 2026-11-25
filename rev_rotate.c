#include "push_swap.h"

static int	rev_rotate(t_stack *s)
{
	t_node	*new_last;
	t_node	*new_top;

	if (!s || s->size < 2)
		return (0);
	new_last = s->top;
	while (new_last->next != s->bottom)
		new_last = new_last->next;
	new_top = s->bottom;
	s->bottom->next = s->top;
	s->bottom = new_last;
	s->top = new_top;
	new_last->next = NULL;
	return (1);
}

void	rra(t_stack *a)
{
	if (rev_rotate(a))
	{
		write(1, "rra\n", 4);
		if (a && a->ops)
			a->ops[8]++;
	}
}

void	rrb(t_stack *b)
{
	if (rev_rotate(b))
	{
		write(1, "rrb\n", 4);
		if (b && b->ops)
			b->ops[9]++;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	int	moved;

	moved = rev_rotate(a);
	moved += rev_rotate(b);
	if (moved > 0)
	{
		write(1, "rrr\n", 4);
		if (a && a->ops)
			a->ops[10]++;
	}
}
