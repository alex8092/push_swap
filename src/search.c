#include "push_swap.h"
#include <stdio.h>

t_search		*ft_ps_search_begin(t_clist *lst)
{
	static t_search	data;
	ssize_t			next;
	ssize_t			cur;
	t_clist_it		*current;

	current = lst->current;
	ft_bzero((void *)&data, sizeof(t_search));
	while (current->next != lst->current)
	{
		next = (ssize_t)current->next->value;
		cur = (ssize_t)current->value;
		if (next < cur)
			break ;
		++data.pos;
		current = current->next;
	}
	data.start = current;
	return (ft_ps_length_begin(lst, &data));
}

t_search		*ft_ps_search_end(t_clist *lst)
{
	static t_search	data;
	ssize_t			prev;
	ssize_t			cur;
	t_clist_it		*current;

	current = lst->current;
	ft_bzero((void *)&data, sizeof(t_search));
	while (current->prev != lst->current)
	{
		prev = ((ssize_t)current->prev->value);
		cur = ((ssize_t)current->value);
		if (prev > cur)
			break ;
		++data.pos;
		current = current->prev;
	}
	data.start = current;
	return (ft_ps_length_end(lst, &data));
}