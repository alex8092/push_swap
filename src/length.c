#include "push_swap.h"
#include <stdio.h>

t_search	*ft_ps_length_begin(t_clist *lst, t_search *info)
{
	t_clist_it	*current;

	current = info->start;
	info->len = 1;
	while (current->next != lst->current)
	{
		// printf("compare (%ld) - (%ld)\n", (ssize_t)current->next->value, (ssize_t)current->value);
		if ((ssize_t)current->next->value > (ssize_t)current->value ||
			(ssize_t)current->next->value == ((t_lstinfo *)lst->data)->min)
			break ;
		++info->len;
		current = current->next;
	}
	current = info->start;
	while (info->len < (ssize_t)lst->size - 1)
	{
		// printf("compare reverse (%ld) - (%ld)\n", (ssize_t)current->prev->value, (ssize_t)current->value);
		if ((ssize_t)current->prev->value < (ssize_t)current->value ||
			(ssize_t)current->prev->value == ((t_lstinfo *)lst->data)->max)
			break ;
		++info->len;
		--info->pos;
		current = current->prev;
	}
	info->end = current;
	if (info->len == 1)
	{
		if ((ssize_t)info->end->value < (ssize_t)info->end->next->next->value)
			++info->len;
		else if ((ssize_t)info->end->value < (ssize_t)info->end->prev->value && \
				(ssize_t)info->end->value > (ssize_t)info->end->prev->prev->value)
		{
			--info->pos;
			++info->len;
		}
	}
	if (info->pos < 0)
		info->pos += lst->size;
	return (ft_ps_cost_begin(lst, info));
}

t_search	*ft_ps_length_end(t_clist *lst, t_search *info)
{
	t_clist_it	*current;

	current = info->start;
	while (current->prev != lst->current)
	{
		if ((ssize_t)current->prev->value < (ssize_t)current->value)
			break ;
		++info->len;
		current = current->prev;
	}
	info->end = current;
	return (ft_ps_cost_end(lst, info));
}

