#include "push_swap.h"
#include <stdio.h>

// static t_bool	do_swap(t_ps *ps)
// {
// 	ssize_t			b_value;
// 	const ssize_t	a_value = (ssize_t)ps->a->current->value;
// 	const ssize_t	a_prev_value = (ssize_t)ps->a->current->prev->value;
// 	// const ssize_t	a_min = ((t_lstinfo *)ps->a->data)->min;
// 	// const ssize_t	a_max = ((t_lstinfo *)ps->a->data)->max;

// 	if (!ps->b->size)
// 		return (false);
// 	b_value = (ssize_t)ps->b->current->value;
// 	if (b_value < a_value && b_value > a_prev_value)
// 		return (true);
// 	return (false);
// }

static void	ft_ps_resolve_begin(t_ps *ps, t_search *info, size_t *c)
{
	ssize_t	i;
	int		first;
	int		second;
	i = 0;
	while (i++ < info->pos)
	{
		++(*c);
		ft_ps_do_op("ra");
	}
	if (info->len == 1)
	{
		ft_ps_do_op("pb");
		++(*c);
	}
	else if (info->len == 2)
	{
		ft_ps_is_sort(ps->a);
		first = (ssize_t)info->start->prev->value < (ssize_t)info->start->value;
		if (!first)
			first = (ssize_t)info->start->prev->value == ((t_lstinfo *)ps->a->data)->max;
		second = (ssize_t)info->end->next->value > (ssize_t)info->end->value;
		if (!second)
			second = (ssize_t)info->end->next->value == ((t_lstinfo *)ps->a->data)->min;
		if (first && second)
		{
			ft_ps_do_op("sa");
			++(*c);
		}
		else
		{
			ft_ps_do_op("pb");
			ft_ps_do_op("rb");
			ft_ps_do_op("pb");
			ft_ps_do_op("rb");
		}
	}
	// else if (info->len == 3)
	// {
	// 	ft_ps_do_op("pb");
	// 	ft_ps_do_op("sa");
	// 	ft_ps_do_op("ra");
	// 	ft_ps_do_op("ra");
	// 	ft_ps_do_op("pa");
	// 	(*c) += 5;
	// }
	else
	{
		i = 0;
		while (i++ < info->len)
		{
			ft_ps_do_op("pb");
			ft_ps_do_op("rb");
			(*c) += 2;
		}
		// i = 0;
		// while (i++ < info->len)
		// {
		// 	ft_ps_is_sort(ps->a);
		// 	while (true)
		// 	{
		// 		first = (ssize_t)ps->a->current->value < (ssize_t)ps->b->current->value;
		// 		if (!first && (ssize_t)ps->a->current->value == ((t_lstinfo *)ps->a->data)->max)
		// 		{
		// 			if ((ssize_t)ps->b->current->value > ((t_lstinfo *)ps->a->data)->min)
		// 			{
		// 				ft_ps_do_op("ra");
		// 				++(*c);
		// 				break ;
		// 			}
		// 		}
		// 		else if (first)
		// 			break ;
		// 		else
		// 			ft_ps_do_op("ra");
		// 		++(*c);
		// 	}
		// 	ft_ps_do_op("ra");
		// 	ft_ps_do_op("pa");
		// 	(*c) += 2;
		// }

	}
	(void)ps;
}

// static void	ft_ps_resolve_end(t_ps *ps, t_search *info, size_t *c)
// {
// 	size_t	i;

// 	i = 0;
// 	if (i++ < info->pos)
// 	{
// 		ft_ps_do_op("rra");
// 		++(*c);
// 		// while (ps->b->size != 0 && 
// 		// 	(ssize_t)ps->b->current->value < (ssize_t)ps->a->current->value && 
// 		// 	(ssize_t)ps->b->current->value > (ssize_t)ps->a->current->prev->value)
// 		// {
// 		// 	ft_ps_do_op("pa");
// 		// 	++(*c);
// 		// }
// 		(void)ps;
// 	}
// 	if (info->len == 1)
// 	{
// 		ft_ps_do_op("rra");
// 		ft_ps_do_op("pb");
// 		(*c) += 2;
// 	}
// 	else if (info->len == 2)
// 	{
// 		ft_ps_do_op("rra");
// 		ft_ps_do_op("rra");
// 		ft_ps_do_op("sa");
// 		(*c) += 3;
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i++ < info->len)
// 		{
// 			ft_ps_do_op("rra");
// 			ft_ps_do_op("pb");
// 			(*c) += 2;
// 		}
// 	}
// }

void		ft_ps_resolve(void)
{
	static t_ps		*ps = 0;
	size_t			i;
	t_search		*begin;
	// t_search		*end;

	if (!ps)
		ps = ft_ps_get_instance();
	i = 0;
	// ft_ps_print_status();
	while (!ft_ps_is_sort(ps->a))
	{
		// // ft_ps_print_status();
		// if ((ssize_t)ps->a->current->value > (ssize_t)ps->a->current->next->value && \
		// 	(ssize_t)ps->a->current->value != ((t_lstinfo *)ps->a->data)->max)
		// {
		// 	ft_ps_do_op("sa");
		// 	ft_ps_do_op("ra");
		// 	i += 2;
		// }
		// else if ((ssize_t)ps->a->current->prev->value < (ssize_t)ps->a->current->prev->prev->value && \
		// 	(ssize_t)ps->a->current->prev->value != ((t_lstinfo *)ps->a->data)->min)
		// {
		// 	ft_ps_do_op("rra");
		// 	ft_ps_do_op("rra");
		// 	ft_ps_do_op("sa");
		// 	i += 3;
		// }
		// else
		// 	ft_ps_do_op("ra");
		// else
		// {
			begin = ft_ps_search_begin(ps->a);
			// ft_ps_print_l_search(ps->a, " A ", begin);
			// ft_ps_print_list(ps->b, " B ");
		// 	// printf("begin pos(%zu), len(%zu), cost(%zu), reverse(%d)\n", begin->pos, begin->len, begin->cost, begin->reverse);
		// 	end = ft_ps_search_end(ps->a);
		// 	// printf("end pos(%zu), len(%zu), cost(%zu), reverse(%d)\n", end->pos, end->len, end->cost, end->reverse);
		// 	if (end->cost < begin->cost)
		// 	{
		// 		if (!end->reverse)
		// 			ft_ps_resolve_end(ps, end, &i);
		// 		else
		// 			ft_ps_resolve_begin(ps, end, &i);
		// 	}
		// 	else
		// 	{
		// 		if (!begin->reverse)
					ft_ps_resolve_begin(ps, begin, &i);
		// 		else
		// 			ft_ps_resolve_end(ps, begin, &i);
		// // 	}
		// 	(void)do_swap;
		// 	(void)ft_ps_resolve_end;
		// 	(void)ft_ps_resolve_begin;
		// }
		// ft_ps_print_status();
		// break ;
	}
	// ft_ps_print_status();
	printf("op (%zu)\n", i);
}