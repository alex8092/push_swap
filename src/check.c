#include "push_swap.h"
#include "ft_dlist.h"
#include <stdio.h>

static t_clist_it		*ft_ps_get_info_and_min(t_clist *l)
{
	t_clist_it	*min;
	ssize_t		max;
	t_clist_it	*current;

	current = l->current;
	min = current;
	max = ((ssize_t)current->value);
	((t_lstinfo *)l->data)->min = max;
	((t_lstinfo *)l->data)->max = max;
	while (current)
	{
		if (((ssize_t)min->value) > ((ssize_t)current->value))
		{
			((t_lstinfo *)l->data)->min = ((ssize_t)current->value);
			min = current;
		}
		if (max < ((ssize_t)current->value))
		{
			max = ((ssize_t)current->value);
			((t_lstinfo *)l->data)->max = max;
		}
		current = current->next;
		if (current == l->current)
			break ;
	}
	return (min);
}

t_bool					ft_ps_is_sort(t_clist *l)
{
	t_clist_it	*start;
	t_clist_it	*current;

	if (l->size == 0)
		return (true);
	start = ft_ps_get_info_and_min(l);
	current = start;
	while (current && current->next != start)
	{
		if ((ssize_t)current->next->value < ((ssize_t)current->value))
			return (false);
		current = current->next;
	}
	return (true);
}