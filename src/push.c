#include "push_swap.h"

void			ft_ps_exec_pusha(void)
{
	t_dlist_it	*it;

	ft_dlist_pop_front(ft_ps_get_instance()->b, &it);
	if (it)
		ft_dlist_push_front(ft_ps_get_instance()->a, it);
}

void			ft_ps_exec_pushb(void)
{
	t_dlist_it	*it;

	ft_dlist_pop_front(ft_ps_get_instance()->a, &it);
	if (it)
		ft_dlist_push_front(ft_ps_get_instance()->b, it);
}