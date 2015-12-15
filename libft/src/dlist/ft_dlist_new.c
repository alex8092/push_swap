#include "ft_dlist.h"

t_dlist			*ft_dlist_new(void)
{
	t_dlist		*it;

	it = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	return (it);
}