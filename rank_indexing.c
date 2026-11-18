#include "push_swap.h"

void	rank_indexing(t_stack *a)
{
	t_node	*current;
	t_node	*comp;
	int		rank;

	if (!a)
		return ;
	current = a->top;
	while (current != NULL)
	{
		rank = 0;
		comp = a->top;
		while (comp != NULL)
		{
			if (current->data > comp->data)
				rank++;
			comp = comp->next;
		}
		current->index = rank;
		current = current->next;
	}
}
