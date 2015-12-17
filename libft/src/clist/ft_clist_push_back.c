#include "ft_clist.h"

t_clist			*ft_clist_push_back(t_clist *l, t_clist_it *it)
{
	ft_clist_push_front(l, it);
	l->current = l->current->next;
	return (l);
}