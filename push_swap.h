#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				index;
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*bottom;
	t_node	*top;
	int		*ops;
}	t_stack;

/* Stack & Parsing */
void	free_stack(t_stack *s);
t_stack	*in_it_stack(void);
int		push_bottom(t_stack *s, int data);
int		parse_args(int argc, char **argv, t_stack *a, int start_idx);
int		sandwesh_duple(t_stack *s);
int		is_sorted(t_stack *a);

/* Utils & Flags */
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *str);
char	**ft_split(char const *s);
void	*free_array(char **array, size_t i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		parse_flags(int argc, char **argv, int *strategy, int *bench);

/* Algorithms & Benchmark */
void	ft_putstr_fd(char *s, int fd);
void	print_strategy_line(int strategy, int actual);
double	compute_disorder(t_stack *a);
void	simple(t_stack *a, t_stack *b);
void	medium(t_stack *a, t_stack *b);
void	complex(t_stack *a, t_stack *b);
void	adaptive(t_stack *a, t_stack *b);
void	rank_indexing(t_stack *a);
void	run_sort(t_stack *a, t_stack *b, int strategy, int bench);
void	print_bench(int *ops, double disorder, int strategy, int actual);

/* Operations */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
