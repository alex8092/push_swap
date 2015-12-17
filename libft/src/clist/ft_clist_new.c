#include "ft_clist.h"
#include "ft_common.h"

t_clist 	*ft_clist_new(void)
{
	t_clist	*l;

	l = (t_clist *)ft_memalloc(sizeof(t_clist));
	if (l)
	{
		l->push_front = &ft_clist_push_front;
		l->push_back = &ft_clist_push_back;
		l->rotate = &ft_clist_rotate;
		l->pop_front = &ft_clist_pop_front;
		l->pop_back = &ft_clist_pop_back;
	}
	return (l);
}