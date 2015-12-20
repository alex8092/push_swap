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

static void	ft_push_to_b(t_ps *ps, size_t *c)
{
	if (ps->b->size >= 2)
	{
		ft_ps_is_sort(ps->b);
		if ((ssize_t)ps->a->current->value > ((t_lstinfo *)ps->b->data)->max)
		{
			while ((ssize_t)ps->b->current->value != ((t_lstinfo *)ps->b->data)->max)
			{
				ft_ps_do_op("rrb");
				++(*c);
			}
		}
		else if ((ssize_t)ps->a->current->value < ((t_lstinfo *)ps->b->data)->min)
		{
			while ((ssize_t)ps->b->current->value != ((t_lstinfo *)ps->b->data)->min)
			{
				ft_ps_do_op("rb");
				++(*c);
			}
			ft_ps_do_op("rrb");
			++(*c);
		}
		else
		{
			while (true)
			{
				if ((ssize_t)ps->b->current->prev->value > (ssize_t)ps->a->current->value)
				{
					if ((ssize_t)ps->b->current->value < (ssize_t)ps->a->current->value)
						break ;
					else
						ft_ps_do_op("rb");
				}
				else
					ft_ps_do_op("rrb");
				++(*c);
			}
		}
	}
	ft_ps_do_op("pb");
	++(*c);
}

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
		ft_push_to_b(ps, c);
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
			ft_push_to_b(ps, c);
			ft_push_to_b(ps, c);
		}
	}
	else
	{
		// ft_ps_is_sort(ps->a);
		// first = (ssize_t)info->start->prev->value < (ssize_t)info->start->value;
		// if (!first)
		// 	first = (ssize_t)info->start->prev->value == ((t_lstinfo *)ps->a->data)->max;
		// second = (ssize_t)info->end->next->value > (ssize_t)info->end->value;
		// if (!second)
		// 	second = (ssize_t)info->end->next->value == ((t_lstinfo *)ps->a->data)->min;
		i = 0;
		while (i++ < info->len)
		{
			ft_push_to_b(ps, c);
		}
		// if (first && second)
		// {
		// 	i = 0;
		// 	while (i++ < info->len)
		// 	{
		// 		ft_ps_do_op("pa");
		// 		++(*c);
		// 	}
		// }
	}
	(void)ps;
}

static void	ft_ps_resolve_end(t_ps *ps, t_search *info, size_t *c)
{
	ssize_t	i;

	i = 0;
	if (i++ < info->pos)
	{
		ft_ps_do_op("rra");
		++(*c);
		// while (ps->b->size != 0 && 
		// 	(ssize_t)ps->b->current->value < (ssize_t)ps->a->current->value && 
		// 	(ssize_t)ps->b->current->value > (ssize_t)ps->a->current->prev->value)
		// {
		// 	ft_ps_do_op("pa");
		// 	++(*c);
		// }
		(void)ps;
	}
	if (info->len == 1)
	{
		ft_ps_do_op("rra");
		ft_ps_do_op("pb");
		(*c) += 2;
	}
	else if (info->len == 2)
	{
		ft_ps_do_op("rra");
		ft_ps_do_op("rra");
		ft_ps_do_op("sa");
		(*c) += 3;
	}
	else
	{
		i = 0;
		while (i++ < info->len)
		{
			ft_ps_do_op("rra");
			ft_ps_do_op("pb");
			(*c) += 2;
		}
	}
}

// static size_t	find_next_item(t_ps *ps, size_t& index, size_t& len)
// {
// 	t_clist_it	*current;

// 	current = ps->a->current;
// 	index = 0;
// 	while ((ssize_t)current->value < (ssize_t)current->next->value)
// 		current = current->next;
// }

void			ft_ps_resolve(void)
{
	static t_ps		*ps = 0;
	// ssize_t			current;
	// ssize_t			next;
	// ssize_t			prev;
	// ssize_t			max;
	// ssize_t			min;
	size_t			i;
	t_search		*begin;

	if (!ps)
		ps = ft_ps_get_instance();
	i = 0;
	// ft_ps_print_status();
	// while (!ft_ps_is_sort(ps->a))
	// {

	// }
	// ft_ps_print_status();
	while (!ft_ps_is_sort(ps->a))
	{
		// min = ((t_lstinfo *)ps->a->data)->min;
		// max = ((t_lstinfo *)ps->a->data)->max;
		// current = ((ssize_t)ps->a->current->value);
		// next = ((ssize_t)ps->a->current->next->value);
		// prev = ((ssize_t)ps->a->current->prev->value);
		// if (current > next)
		// {
		// 	if (current < prev)
		// 	{
		// 		if (prev - current < current - next)
		// 		{
		// 			ft_ps_do_op("rra");
		// 			// ft_ps_print_status();
		// 			++i;
		// 			continue ;
		// 		}
		// 	}
		// 	if (next != min || current != max)
		// 	{
		// 		ft_ps_do_op("sa");
		// 		// ft_ps_print_status();
		// 		++i;
		// 		continue ;
		// 	}
		// }
		// (void)max;
		// ft_ps_do_op("rra");
		// // ft_ps_print_status();
		// ++i;
		// continue ;
		// (void)min;
		// else if (prev != min && cu)
		// // ft_ps_print_status();
		// if ((ssize_t)ps->a->current->value > (ssize_t)ps->a->current->next->value &&
		// 	(ssize_t)ps->a->current->value != ((t_lstinfo *)ps->a->data)->max)
		// {
		// 	ft_ps_do_op("sa");
		// 	ft_ps_do_op("ra");
		// 	i += 2;
		// }
		// else if ((ssize_t)ps->a->current->prev->value < (ssize_t)ps->a->current->prev->prev->value && 
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
			// printf("begin pos(%zu), len(%zu), cost(%zu), reverse(%d)\n", begin->pos, begin->len, begin->cost, begin->reverse);
			// begin = ft_ps_search_
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
					// ft_ps_resolve_begin(ps, begin, &i);
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
	(void)ft_ps_resolve_begin;
	(void)ft_ps_resolve_end;
	ft_ps_print_status();
	printf("op (%zu)\n", i);
}