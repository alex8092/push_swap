#include "push_swap.h"

static void	rotate_list(t_clist *lst, t_bool left)
{
	lst->rotate(lst, 1, left);
}

void	ft_ps_exec_rotatea(void)
{
	static t_ps		*ps = 0;

	if (!ps)
		ps = ft_ps_get_instance();
	rotate_list(ps->a, true);
}

void	ft_ps_exec_rotatea_reverse(void)
{
	static t_ps		*ps = 0;

	if (!ps)
		ps = ft_ps_get_instance();
	rotate_list(ps->a, false);
}

void	ft_ps_exec_rotateb(void)
{
	static t_ps		*ps = 0;

	if (!ps)
		ps = ft_ps_get_instance();
	rotate_list(ps->b, true);
}

void	ft_ps_exec_rotateb_reverse(void)
{
	static t_ps		*ps = 0;

	if (!ps)
		ps = ft_ps_get_instance();
	rotate_list(ps->b, false);
}