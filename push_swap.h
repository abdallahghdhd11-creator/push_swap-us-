#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typdef struct s_node
{
  int           index;
  int           data;
  struct s_node *next;
} t_node;

//msh kamil 
typdef struct stack
{
  int         size;
  node *Bottom;
  node *top;
  int index;
} t_stack;

#else
