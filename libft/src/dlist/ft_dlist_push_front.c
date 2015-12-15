#include "ft_dlist.h"

t_dlist				*ft_dlist_push_front(t_dlist *lst, t_dlist_it *item)
{
	if (!lst)
		lst = ft_dlist_new();
	if (!lst->begin)
	{
		lst->begin = item;
		lst->end = item;
		lst->size = 1;
	}
	else
	{
		lst->begin->prev = item;
		lst->begin = item;
		++lst->size;
	}
	return (lst);
}