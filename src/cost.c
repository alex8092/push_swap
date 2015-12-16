#include "push_swap.h"

size_t		ft_ps_cost_begin(size_t n, size_t length)
{
	size_t	cost;

	cost = n;
	if (length == 2 || length == 1)
		++cost;
	else
		cost += length * 2;
	return (cost);
}

size_t		ft_ps_cost_end(size_t n, size_t length)
{
	size_t	cost;

	cost = n;
	if (length == 1)
		cost += 2;
	else if (length == 2)
		cost += 3;
	else
		cost += length * 2;
	return (cost);
}