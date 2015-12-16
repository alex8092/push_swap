#include "push_swap.h"
#include "ft_dlist.h"

static t_dlist_it		*ft_ps_get_info_and_min(t_dlist *l)
{
	t_dlist_it	*min;
	ssize_t		max;
	t_dlist_it	*current;

	current = l->begin;
	min = current;
	max = ((ssize_t)current->value);
	((t_lstinfo *)l->data)->min = ((ssize_t)min->value);
	while (current)
	{
		if (((ssize_t)min->value) > ((ssize_t)current->value))
		{
			((t_lstinfo *)l->data)->min = ((ssize_t)min->value);
			min = current;
		}
		if (max < ((ssize_t)current->value))
		{
			max = ((ssize_t)current->value);
			((t_lstinfo *)l->data)->max = max;
		}
		current = current->next;
	}
	return (min);
}

t_bool					ft_ps_is_sort(t_dlist *l)
{
	int			count;
	t_dlist_it	*start;
	t_dlist_it	*current;

	count = 0;
	start = ft_ps_get_info_and_min(l);
	// printf("min (%ld)\n", ((ssize_t)start->value));
	current = start;
	while (true)
	{
		if (!current->next)
		{
			if (l->begin == start)
				break ;
			if (((ssize_t)current->value) > ((ssize_t)l->begin->value))
				return (false);
			current = l->begin;
		}
		else
		{
			if (current->next == start)
				break ;
			if (((ssize_t)current->value) > ((ssize_t)current->next->value))
				return (false);
			current = current->next;
		}
		++count;
	}
	printf("count (%d)\n", count);
	return (true);
}