#include "push_swap.h"

static int  rotate_s(t_stack *s)
{
  t_node *temp;

  if (!s)
    return (0);
  if (s->size < 2)
    return (0);
  else 
  {
  temp = s->top;
  s->top = temp->next;
  s->bottom->next = temp;
  s->bottom = temp;
  temp->next = NULL;
  }
  return (1);
}

void	ra(t_stack *a)
{
	if (rotate_s(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (rotate_s(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	r1;
	int	r2;

	r1 = rotate_s(a);
	r2 = rotate_s(b);
	if (r1 == 1 || r2 == 1)
		write(1, "rr\n", 3);
}


