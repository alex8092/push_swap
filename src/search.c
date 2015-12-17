#include "push_swap.h"
#include <stdio.h>

t_search		*ft_ps_search_begin(t_clist *lst)
{
	static t_search	data;
	t_clist_it		*current;

	current = lst->current;
	ft_bzero((void *)&data, sizeof(t_search));
	// if ((ssize_t)current->value == ((t_lstinfo *)lst->data)->max)
	// {
	// 	++data.pos;
	// 	current = current->next;
	// }
	while (current && current->next != lst->current)
	{
		if ((ssize_t)current->next->value < (ssize_t)current->value && \
			(ssize_t)current->value != ((t_lstinfo *)lst->data)->max)
			break ;
		++data.pos;
		current = current->next;
	}
	return (ft_ps_length_begin(lst, &data));
}

t_search		*ft_ps_search_end(t_clist *lst)
{
	static t_search	data;
	t_clist_it		*current;

	current = lst->current->prev;
	ft_bzero((void *)&data, sizeof(t_search));
	while (current && current->prev != lst->current)
	{
		if ((ssize_t)current->prev->value > (ssize_t)current->value)
			break ;
		++data.pos;
		current = current->prev;
	}
	return (ft_ps_length_end(lst, &data));
}