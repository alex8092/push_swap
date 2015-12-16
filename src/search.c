#include "push_swap.h"

size_t			ft_ps_find_begin_anomaly(t_dlist *lst)
{
	t_dlist_it	*current;
	size_t		op;

	op = 0;
	current = lst->begin;
	while (current)
	{
		if (current->next)
		{
			if (((ssize_t)current->next->value) < ((ssize_t)current->value) && \
				((ssize_t)current->value) != ((t_lstinfo *)lst->data)->max)
				break ;
			++op;
		}
		current = current->next;

	}
	return (op);
}

size_t			ft_ps_find_length_begin(t_dlist *lst, size_t n)
{
	t_dlist_it	*current;
	size_t		i;

	i = 0;
	current = lst->begin;
	while (i++ < n)
		current = current->next;
	i = 1;
	while (current && current->next)
	{
		if (((ssize_t)current->next->value) > ((ssize_t)current->value))
			break ;
		++i;
		current = current->next;
	}
	return (i);
}

size_t			ft_ps_find_length_end(t_dlist *lst, size_t n)
{
	t_dlist_it	*current;
	size_t		i;

	i = 0;
	current = lst->end;
	while (i++ < n)
		current = current->prev;
	i = 1;
	while (current && current->prev)
	{
		if (((ssize_t)current->prev->value) < ((ssize_t)current->value))
			break ;
		++i;
		current = current->prev;
	}
	return (i);
}

size_t			ft_ps_find_end_anomaly(t_dlist *lst)
{
	t_dlist_it	*current;
	size_t		op;

	op = 0;
	current = lst->end;
	while (current)
	{
		if (current->prev)
		{
			if (((ssize_t)current->prev->value) > ((ssize_t)current->value) && \
				((ssize_t)current->value) != ((t_lstinfo *)lst->data)->min)
				break ;
			++op;
		}
		current = current->prev;
	}
	return (op);
}