#include "push_swap.h"

void			ft_ps_exec_pusha(void)
{
	static t_ps		*ps = 0;
	t_clist_it		*it;

	if (!ps)
		ps = ft_ps_get_instance();
	it = ps->b->pop_front(ps->b);
	if (it)
		ps->a->push_front(ps->a, it);
}

void			ft_ps_exec_pushb(void)
{
	static t_ps		*ps = 0;
	t_clist_it		*it;

	if (!ps)
		ps = ft_ps_get_instance();
	it = ps->b->pop_front(ps->a);
	if (it)
		ps->a->push_front(ps->b, it);
}