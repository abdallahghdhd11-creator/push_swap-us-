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
    write(1, "sa\n", 3);
}

void sb(t_stack *s)
{
  if (swap_s(s))
    write(1, "sb\n", 3);
}

void ss(t_stack *s2 , t_stack *s1)
{
  int i1;
  int i2;

  i1 = swap_s(s1);
  i2 = swap_s(s2);
  if (i1 == 1  || i2 == 1)
    write(1,"ss\n", 3);
}
  
