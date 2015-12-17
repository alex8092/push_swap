#include "ft_clist.h"

t_clist			*ft_clist_push_front(t_clist *l, t_clist_it *it)
{
	t_clist_it	*next;
	t_clist_it	*prev;
	if (!l->current)
	{
		l->current = it;
		it->next = it;
		it->prev = it;
		++l->size;
		return (l);
	}
	next = l->current;
	prev = l->current->prev;
	next->prev = it;
	prev->next = it;
	it->next = next;
	it->prev = prev;
	l->current = it;
	++l->size;
	return (l);
}