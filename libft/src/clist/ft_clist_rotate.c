#include "ft_clist.h"

t_clist		*ft_clist_rotate(t_clist *l, size_t n, t_bool right)
{
	size_t	i;

	if (!l->current)
		return (l);
	i = 0;
	while (i < n)
	{
		if (right)
			l->current = l->current->next;
		else
			l->current = l->current->prev;
		++i;
	}
	return (l);
}