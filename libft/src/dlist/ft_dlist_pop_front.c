#include "ft_dlist.h"

t_dlist		*ft_dlist_pop_front(t_dlist *lst, t_dlist_it **item)
{
	(*item) = 0;
	if (lst->begin)
	{
		if (lst->begin->next)
			lst->begin->next->prev = 0;
		*item = lst->begin;
		lst->begin = lst->begin->next;
		if (!lst->begin)
			lst->end = lst->begin;
		(*item)->next = 0;
		--lst->size;
	}
	return (lst);
}