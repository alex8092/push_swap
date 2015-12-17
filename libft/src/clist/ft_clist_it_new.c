#include "ft_clist.h"
#include "ft_common.h"

t_clist_it		*ft_clist_it_new(void *value)
{
	t_clist_it	*it;

	it = (t_clist_it *)ft_memalloc(sizeof(t_clist_it));
	if (it)
		it->value = value;
	return (it);
}