#include "ft_dlist.h"

t_dlist				*ft_dlist_push_back(t_dlist *lst, t_dlist_it *item)
{
	if (!lst)
		lst = ft_dlist_new();
	if (!lst->end)
	{
		lst->begin = item;
		lst->end = item;
		lst->size = 1;
	}
	else
	{
		lst->end->next = item;
		item->prev = lst->end;
		lst->end = item;
		++lst->size;
	}
	return (lst);
}