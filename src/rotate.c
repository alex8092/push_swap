#include "push_swap.h"

static void	rotate_list(t_dlist *lst, t_bool left)
{
	ft_dlist_rotate(lst, left);
}

void	ft_ps_exec_rotatea(void)
{
	rotate_list(ft_ps_get_instance()->a, true);
}

void	ft_ps_exec_rotatea_reverse(void)
{
	rotate_list(ft_ps_get_instance()->a, false);
}

void	ft_ps_exec_rotateb(void)
{
	rotate_list(ft_ps_get_instance()->b, true);
}

void	ft_ps_exec_rotateb_reverse(void)
{
	rotate_list(ft_ps_get_instance()->b, false);
}