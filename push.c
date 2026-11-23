#include "push_swap.h"

static int push_s(t_stack *src ,t_stack *des)
{
  t_node *node;
  
  if(!src || !des || src->size == 0)
    return (0);
  node = src->top;
  src->top = node->next;
  if (src->size == 1)
    src->bottom = NULL;
  src->size--;
  if (des->size == 0)
  {
    des->top = node;
    node->next = NULL;
    des->bottom = node;
  }
  else
  {
    node->next = des->top;
    des->top = node;
  }
  des->size++;
  return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push_s(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (push_s(a, b))
		write(1, "pb\n", 3);
}
