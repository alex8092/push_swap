#include "ft_clist.h"

t_clist_it		*ft_clist_pop_front(t_clist *l)
{
	t_clist_it	*it;
	t_clist_it	*next;
	t_clist_it	*prev;

	if (!l->current)
		return (0);
	it = l->current;
	next = it->next;
	prev = it->prev;
	if (next != it && prev != it)
	{
		next->prev = prev;
		prev->next = next;
	}
	it->next = 0;
	it->prev = 0;
	--l->size;
	l->current = next;
	if (!l->size)
		l->current = 0;
	return (it);
}