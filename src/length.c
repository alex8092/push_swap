#include "push_swap.h"
#include <stdio.h>

t_search	*ft_ps_length_begin(t_clist *lst, t_search *info)
{
	t_clist_it	*current;

	current = info->start;
	while ((ssize_t)current->prev->value > (ssize_t)current->value)
	{
		current = current->prev;
		--info->pos;
	}
	info->start = current;
	info->len = 1;
	while (current->next != info->start)
	{
		if ((ssize_t)current->next->value > (ssize_t)current->value)
			break ;
		++info->len;
		current = current->next;
	}
	if (info->len == 3)
	{
		if ((ssize_t)current->value == ((t_lstinfo *)lst->data)->min &&
			(ssize_t)info->start->value == ((t_lstinfo *)lst->data)->max)
		{
			if ((ssize_t)info->start->prev->value < (ssize_t)info->start->next->value)
			{
				--info->len;
				current = current->prev;
			}
			else
			{
				++info->pos;
				--info->len;
				info->start = info->start->next;
			}
		}
	}
	info->end = current;
	return (ft_ps_cost_begin(lst, info));
}

t_search	*ft_ps_length_end(t_clist *lst, t_search *info)
{
	t_clist_it	*current;

	current = info->start;
	while ((ssize_t)current->next->value < (ssize_t)current->value)
	{
		current = current->next;
		--info->pos;
	}
	info->start = current;
	info->len = 1;
	while (current->prev != info->start)
	{
		if ((ssize_t)current->prev->value < (ssize_t)current->value)
			break ;
		++info->len;
		current = current->prev;
	}
	if (info->len == 3)
	{
		if ((ssize_t)current->value == ((t_lstinfo *)lst->data)->max &&
			(ssize_t)info->start->value == ((t_lstinfo *)lst->data)->min)
		{
			if ((ssize_t)info->start->next->value > (ssize_t)info->start->prev->value)
			{
				--info->len;
				current = current->next;
			}
			else
			{
				++info->pos;
				--info->len;
				info->start = info->start->prev;
			}
		}
	}
	info->end = current;
	return (ft_ps_cost_end(lst, info));
}

