#include "push_swap.h"
#include <stdio.h>

static t_search		*cost_begin_reverse(t_clist *lst, t_search *info)
{
	const ssize_t	pos = lst->size - info->pos - info->len;
	size_t			cost;

	if (pos < 0)
		return (info);
	cost = pos;
	if (info->len == 1)
		++cost;
	else if (info->len == 2)
		cost += 3;
	else
		cost += info->len;
	if (cost < info->cost)
	{
		// printf("[prev] -> begin pos(%zu), len(%zu), cost(%zu), reverse(%d)\n", info->pos, info->len, info->cost, info->reverse);
		// info->reverse = true;
		// info->cost = cost;
		// info->pos = pos;
	}
	return (info);
}

t_search			*ft_ps_cost_begin(t_clist *lst, t_search *info)
{
	info->cost = info->pos;
	if (info->len == 2 || info->len == 1)
		++info->cost;
	else
		info->cost += info->len * 2;
	(void)lst;
	return (cost_begin_reverse(lst, info));
}

static t_search		*cost_end_reverse(t_clist *lst, t_search *info)
{
	const ssize_t	pos = lst->size - (info->pos + info->len);
	size_t			cost;

	if (pos < 0)
		return (info);
	cost = pos;
	if (info->len <= 2)
		++cost;
	else
		cost += info->len;
	if (cost < info->cost)
	{
		// printf("[prev] -> end pos(%zu), len(%zu), cost(%zu), reverse(%d)\n", info->pos, info->len, info->cost, info->reverse);
		// info->reverse = true;
		// info->cost = cost;
		// info->pos = pos;
	}
	return (info);
}

t_search			*ft_ps_cost_end(t_clist *lst, t_search *info)
{
	info->cost = info->pos;
	if (info->len == 1)
		++info->cost;
	else if (info->len == 2)
		info->cost += 3;
	else
		info->cost += info->len * 2;
	return (cost_end_reverse(lst, info));
}