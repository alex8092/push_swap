#include "ft_dlist.h"

t_dlist		*ft_dlist_pop_back(t_dlist *lst, t_dlist_it **item)
{
	(*item) = 0;
	if (lst->end)
	{
		if (lst->end->prev)
			lst->end->prev->next = 0;
		*item = lst->end;
		lst->end = lst->end->prev;
		if (!lst->end)
			lst->begin = lst->end;
		(*item)->prev = 0;
		--lst->size;
	}
	return (lst);
}