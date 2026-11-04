#include "push_swap.h"

void printError()
{
  write(2,"Error\n",6);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t				i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (n > i)
	{
		if (ss1[i] != ss2[i] || ss1[i] == '\0' || ss2[i] == '\0')
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

int flagsError(int argc, char **argv)
{
  if (argc < 2)
    return 0;
  if (ft_strncmp("--simple",argv[1], 9) == 0)
    return 1;
  else if (ft_strncmp("--medium",argv[1], 9) == 0)
    return 1;
  else if (ft_strncmp("--complex", argv[1], 10) == 0)
    return 1;
  else if (ft_strncmp("--adaptive" , argv[1], 11) == 0)
    return 1;
  else if (ft_strncmp("--bench", argv[1], 8) == 0)
    return 1;
  
  if (ft_strncmp("--", argv[1], 2) == 0)
		return (-1);

  return 0;
}

int main(int argc, char **argv)
{
  t_stack *a;
  t_stack *b;
  
  if (flagsError(argc, *argv[]) == -1)
  {
    printError();
    return -1;
  }
}
