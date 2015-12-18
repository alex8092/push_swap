#include "push_swap.h"
#include "ft_sstream.h"
#include "ft_printer.h"

void			ft_ps_print_list(t_clist *lst, const char *before)
{
	t_clist_it		*current;
	t_sstream		*ss;
	const size_t	size = (lst) ? lst->size : 0;
	size_t			i;

	ss = ft_sstream_new();
	if (before)
		ss->add(ss, "[")->add(ss, before)->add(ss, "]");
	ss->add(ss, "-> ");
	current = (lst) ? lst->current : 0;
	i = 0;
	while (i < size)
	{
		ss->v_min_field_width = 4;
		ss->addc(ss, ' ')->addl(ss, (int)(size_t)current->value);
		current = current->next;
		++i;
	}
	ft_printer_init(1)->addss(ss)->addc('\n');
	ft_sstream_del(ss);
}

void			ft_ps_print_l_search(t_clist *lst, const char *bef, t_search *s)
{
	t_clist_it		*current;
	t_sstream		*ss;
	const size_t	size = (lst) ? lst->size : 0;
	ssize_t			i;
	t_bool			color;

	ss = ft_sstream_new();
	if (bef)
		ss->add(ss, "[")->add(ss, bef)->add(ss, "]");
	ss->add(ss, "-> ");
	current = (lst) ? lst->current : 0;
	i = 0;
	while (i < (ssize_t)size)
	{
		color = i >= s->pos && (i - s->pos) < s->len;
		ss->addc(ss, ' ');
		if (color)
			ss->add(ss, "\e[32m");
		ss->v_min_field_width = 4;
		ss->addl(ss, (int)(size_t)current->value);
		if (color)
			ss->add(ss, "\e[0m");
		current = current->next;
		++i;
	}
	ft_printer_init(1)->addss(ss)->addc('\n');
	ft_sstream_del(ss);
}

void			ft_ps_print_status(void)
{
	t_ps			*ps;

	ps = ft_ps_get_instance();
	ft_printer_init(1)->add("## STATUS ##\n");
	ft_ps_print_list(ps->a, " A ");
	ft_ps_print_list(ps->b, " B ");
	ft_printer_init(1)->addc('\n');
}