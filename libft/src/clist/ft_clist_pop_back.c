#include "ft_clist.h"

t_clist_it				*ft_clist_pop_back(t_clist *l)
{
	t_clist_it			*it;

	it = ft_clist_pop_front(l);
	if (l->current)
		l->current = l->current->prev;
	return (it);
}