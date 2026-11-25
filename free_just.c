#include "push_swap.h"

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	sandwesh_duple(t_stack *s)
{
	t_node	*curr;
	t_node	*comp;

	curr = s->top;
	while (curr)
	{
		comp = curr->next;
		while (comp)
		{
			if (comp->data == curr->data)
				return (-1);
			comp = comp->next;
		}
		curr = curr->next;
	}
	return (0);
}

static int	fill_tokens(char **nums, t_stack *a)
{
	int		j;
	long	val;

	j = 0;
	while (nums[j])
	{
		val = ft_atoi(nums[j]);
		if (val == 2147483648L || !push_bottom(a, (int)val))
			return (0);
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a, int start_idx)
{
	char	**nums;

	while (start_idx < argc)
	{
		nums = ft_split(argv[start_idx]);
		if (!nums || !nums[0] || !fill_tokens(nums, a))
		{
			free_split(nums);
			return (0);
		}
		free_split(nums);
		start_idx++;
	}
	return (sandwesh_duple(a) == 0);
}
