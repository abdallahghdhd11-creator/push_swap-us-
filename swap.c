#include "push_swap.h"

static int swap_s(t_stack *s)
{
  t_node *first;
  t_node *second;

  if (!s || s->size < 2)
    return (0);
  first = s->top;
  second = first->next;
  first->next = second->next;
  second->next = first;
  s->top = second;
  if (s->size == 2)
  {
    s->bottom = first;
  }
  return (1);
}

void sa(t_stack *s)
{
  if (swap_s(s))
	{
		write(1, "sa\n", 3);
		if (s && s->ops)
			s->ops[0]++;
	}
}

void sb(t_stack *b)
{
  if (swap_s(b))
	{
		write(1, "sb\n", 3);
		if (b && b->ops)
			b->ops[1]++;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	int	moved;

	moved = swap_s(a);
	moved += swap_s(b);
	if (moved > 0)
	{
		write(1, "ss\n", 3);
		if (a && a->ops)
			a->ops[2]++;
	}
}  
