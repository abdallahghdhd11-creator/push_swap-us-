#include "push_swap"

static void free_split(char **arr)
{
  int i;

  i = 0;
  while (arr[i])
  {
    free(arr[i]);
    i++;
  }
 free(arr);
}
int sandwesh_duple(t_stack *s)
{
  t_node *curr;
  t_node *comp;

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

int	parse_args(int argc, char **argv, t_stack *a, int start_idx)
{
	char	**nums;
	int		j;
	long	val;

	while (start_idx < argc)
	{
		nums = ft_split(argv[start_idx]);
		if (!nums || !nums[0])
			return (free_split_all(nums), 0);
		j = 0;
		while (nums[j])
		{
			val = ft_atoi(nums[j]);
			if (val == 2147483648L || !push_bottom(a, (int)val))
				return (free_split_all(nums), 0);
			j++;
		}
		free_split_all(nums);
		start_idx++;
	}
	return (!has_duplicates(a));
}
