#include "push_swap.h"

t_stack *in_it_stack(void)
{
  t_stack *s;
  s = (t_stack *)malloc(sizeof(t_stack));
  
  if (!s)
    return (NULL);
  s->size = 0;
  s->bottom = NULL;
  s->top = NULL;
  return (s);
}


void free_stack(t_stack *s)
{
  t_node *current;
  t_node *temp;

  if (!s)
    return ;
  current = s->top;
  while (current)
  {
    temp = current-> next;
    free(current);
    current = temp;
  }
  free(s);
}

int push_bottom(t_stack *s , int data)
{
  t_node *n_node;

  if (!s)
    return (0);
  n_node = (t_node *)(malloc(sizeof(t_node)));
  if (!n_node)
    return (0);
  n_node->data = data;
  n_node->next = NULL;
  n_node->index = -1;
  if (s->size == 0)
  {
    s->bottom = n_node;
    s->top = n_node;
  }
  else
{
    s->bottom->next = n_node;
    s-> bottom = n_node; 
}
  s->size++;
  return (1);

}




