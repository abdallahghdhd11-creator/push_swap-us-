#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

static void	print_percent_fd(double disorder, int fd)
{
	int	scaled;
	int	whole;
	int	frac;

	scaled = (int)(disorder * 10000.0 + 0.5);
	whole = scaled / 100;
	frac = scaled % 100;
	ft_putnbr_fd(whole, fd);
	write(fd, ".", 1);
	if (frac < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(frac, fd);
	write(fd, "%", 1);
}

static void	print_ops_lines(int *ops)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops[0], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops[1], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops[2], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops[3], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops[4], 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(ops[5], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops[6], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops[7], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops[8], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops[9], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops[10], 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(int *ops, double disorder, int strategy, int actual)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < 11)
	{
		total += ops[i];
		i++;
	}
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent_fd(disorder, 2);
	print_strategy_line(strategy, actual);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_ops_lines(ops);
}
