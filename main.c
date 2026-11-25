#include "push_swap.h"

static int	set_strategy(char *arg, int *strategy)
{
	if (*strategy != -1)
		return (0);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		*strategy = 0;
	else if (ft_strncmp(arg, "--simple", 9) == 0)
		*strategy = 1;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		*strategy = 2;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		*strategy = 3;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, int *strategy, int *bench)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
		{
			if (*bench)
				return (-1);
			*bench = 1;
		}
		else if (!set_strategy(argv[i], strategy))
			return (-1);
		i++;
	}
	return (i);
}

static void	init_ops(int *ops, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		ops[i] = 0;
		i++;
	}
	a->ops = ops;
	b->ops = ops;
}

static int	exit_error(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		ops[11];
	int		cfg[3];

	if (argc == 1)
		return (0);
	cfg[0] = -1;
	cfg[1] = 0;
	cfg[2] = parse_flags(argc, argv, &cfg[0], &cfg[1]);
	if (cfg[2] == -1 || cfg[2] >= argc)
		return (exit_error(NULL, NULL));
	if (cfg[0] == -1)
		cfg[0] = 0;
	a = in_it_stack();
	b = in_it_stack();
	if (!a || !b || !parse_args(argc, argv, a, cfg[2]))
		return (exit_error(a, b));
	init_ops(ops, a, b);
	run_sort(a, b, cfg[0], cfg[1]);
	free_stack(a);
	free_stack(b);
	return (0);
}
