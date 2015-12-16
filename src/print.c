#include "push_swap.h"
#include "ft_sstream.h"
#include "ft_printer.h"

void				ft_ps_print_list(t_dlist *lst, const char *before)
{
	t_dlist_it		*current;
	t_sstream		*ss;

	ss = ft_sstream_new();
	if (before)
		ss->add(ss, "[")->add(ss, before)->add(ss, "]");
	ss->add(ss, "-> ");
	current = (lst) ? lst->end : 0;
	while (current)
	{
		ss->v_min_field_width = 4;
		ss->addc(ss, ' ')->addl(ss, (int)(size_t)current->value);
		current = current->prev;
	}
	ft_printer_init(1)->addss(ss)->addc('\n');
	ft_sstream_del(ss);
}

void				ft_ps_print_status(void)
{
	t_ps			*ps;

	ps = ft_ps_get_instance();
	ft_printer_init(1)->add("## STATUS ##\n");
	ft_ps_print_list(ps->a, " A ");
	ft_ps_print_list(ps->b, " B ");
	ft_printer_init(1)->addc('\n');
}