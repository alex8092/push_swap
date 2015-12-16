#include "push_swap.h"

static void			swap(t_dlist *lst)
{
	t_dlist_it		*it;
	t_dlist_it		*it2;

	if (lst->size > 1)
	{
		ft_dlist_pop_front(lst, &it);
		ft_dlist_pop_front(lst, &it2);
		ft_dlist_push_front(lst, it);
		ft_dlist_push_front(lst, it2);
	}
}

void				ft_ps_exec_swapa(void)
{
	swap(ft_ps_get_instance()->a);
}

void				ft_ps_exec_swapb(void)
{
	swap(ft_ps_get_instance()->b);
}

void				ft_ps_exec_swap_all(void)
{
	swap(ft_ps_get_instance()->a);
	swap(ft_ps_get_instance()->b);
}