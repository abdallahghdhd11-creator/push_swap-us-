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
}	t_stack;

void free_stack(t_stack *s);
t_stack *in_it_stack(void);
int push_bottom(t_stack *s , int data);
int	parse_args(int argc, char **argv, t_stack *a, int start_idx);
static void free_split(char **arr);
int sandwesh_duple(t_stack *s);

//Utils
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *str);
char	**ft_split(char const *s);
void	*free_array(char **array, size_t i);

//Algorithms
double	compute_disorder(t_stack *a);
void	simple(t_stack *a, t_stack *b);
void	medium(t_stack *a, t_stack *b);
void	complex(t_stack *a, t_stack *b);
void	rank_indexing(t_stack *a);

#endif
