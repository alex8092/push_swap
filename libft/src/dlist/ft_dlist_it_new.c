#include "ft_dlist.h"

t_dlist_it		*ft_dlist_it_new(void *value)
{
	t_dlist_it	*it;

	it = (t_dlist_it *)ft_memalloc(sizeof(t_dlist_it));
	if (it)
		it->value = value;
	return (it);
}