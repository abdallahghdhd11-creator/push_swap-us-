#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_strategy_line(int strategy, int actual)
{
	ft_putstr_fd("\n[bench] strategy: ", 2);
	if (strategy == 0)
		ft_putstr_fd("Adaptive / ", 2);
	else if (strategy == 1)
		ft_putstr_fd("Simple / ", 2);
	else if (strategy == 2)
		ft_putstr_fd("Medium / ", 2);
	else
		ft_putstr_fd("Complex / ", 2);
	if (actual == 1)
		ft_putstr_fd("O(n^2)\n", 2);
	else if (actual == 2)
		ft_putstr_fd("O(n√n)\n", 2);
	else
		ft_putstr_fd("O(n log n)\n", 2);
}

void	run_sort(t_stack *a, t_stack *b, int strategy, int bench)
{
	double	disorder;
	int		actual;

	disorder = compute_disorder(a);
	actual = strategy;
	if (strategy == 0)
	{
		if (disorder < 0.2)
			actual = 1;
		else if (disorder < 0.5)
			actual = 2;
		else
			actual = 3;
	}
	if (!is_sorted(a) && actual == 1)
		simple(a, b);
	else if (!is_sorted(a) && actual == 2)
		medium(a, b);
	else if (!is_sorted(a) && actual == 3)
		complex(a, b);
	if (bench)
		print_bench(a->ops, disorder, strategy, actual);
}
