#include "push_swap.h"

static void			swap(t_clist *lst)
{
	t_clist_it		*it;
	t_clist_it		*it2;

	if (lst->size > 1)
	{
		it = lst->pop_front(lst);
		it2 = lst->pop_front(lst);
		lst->push_front(lst, it)->push_front(lst, it2);
	}
}

void				ft_ps_exec_swapa(void)
{
	static t_ps		*ps = 0;

	if (!ps)
		ps = ft_ps_get_instance();
	swap(ps->a);
}

void				ft_ps_exec_swapb(void)
{
	static t_ps		*ps = 0;

	if (!ps)
		ps = ft_ps_get_instance();
	swap(ps->b);
}

void				ft_ps_exec_swap_all(void)
{
	static t_ps		*ps = 0;

	if (!ps)
		ps = ft_ps_get_instance();
	swap(ps->a);
	swap(ps->b);
}