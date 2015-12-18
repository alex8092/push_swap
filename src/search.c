#include "push_swap.h"
#include <stdio.h>

t_search		*ft_ps_search_begin(t_clist *lst)
{
	static t_search	data;
	ssize_t			next;
	ssize_t			cur;
	ssize_t			bornes[2];
	t_clist_it		*current;

	current = lst->current;
	ft_bzero((void *)&data, sizeof(t_search));
	bornes[0] = ((t_lstinfo *)lst->data)->min;
	bornes[1] = ((t_lstinfo *)lst->data)->max;
	while (current->next != lst->current)
	{
		next = (ssize_t)current->next->value;
		cur = (ssize_t)current->value;
		if (next < cur)
		{
			if (!(next == bornes[0] && cur == bornes[1]))
				break ;
		}
		++data.pos;
		current = current->next;
	}
	data.start = current;
	return (ft_ps_length_begin(lst, &data));
	// return (&data);
}

t_search		*ft_ps_search_end(t_clist *lst)
{
	static t_search	data;
	ssize_t			prev;
	ssize_t			cur;
	ssize_t			bornes[2];
	t_clist_it		*current;

	current = lst->current;
	ft_bzero((void *)&data, sizeof(t_search));
	bornes[0] = ((t_lstinfo *)lst->data)->min;
	bornes[1] = ((t_lstinfo *)lst->data)->max;
	while (current->prev != lst->current)
	{
		prev = ((ssize_t)current->prev->value);
		cur = ((ssize_t)current->value);
		if (prev > cur)
		{
			if (!(prev == bornes[1] && cur == bornes[0]))
				break ;
		}
		++data.pos;
		current = current->prev;
	}
	data.start = current;
	return (ft_ps_length_end(lst, &data));
	// return (&data);
}