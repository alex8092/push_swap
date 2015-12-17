#include "push_swap.h"
#include <stdio.h>

t_search	*ft_ps_length_begin(t_clist *lst, t_search *info)
{
	t_clist_it	*current;
	size_t		i;

	current = lst->current;
	i = 0;
	while (i++ < info->pos)
		current = current->next;
	info->current = current;
	info->len = 1;
	while (current && current->next != lst->current)
	{
		if ((ssize_t)current->next->value > (ssize_t)current->value)
			break ;
		++info->len;
		current = current->next;
	}
	// if (info->len == 1 && info->pos > 0)
	// {
	// 	info->len = 2;
	// 	--info->pos;
	// }
	// if (info->len == 1 && info->pos > 0)
	// {
	// 	++info->len;
	// 	--info->pos;
	// }
	// if (info->len == 3)
	// {
	// 	i = 0;
	// 	while (i++ < 8 && (ssize_t)current->next->value > (ssize_t)current->value)
	// 		current = current->next;
	// 	if (i > 2)
	// 	{
	// 		++info->pos;
	// 		return (ft_ps_length_begin(lst, info));
	// 	}
	// }
	return (ft_ps_cost_begin(lst, info));
}

t_search	*ft_ps_length_end(t_clist *lst, t_search *info)
{
	t_clist_it	*current;
	size_t		i;

	current = lst->current->prev;
	i = 0;
	while (i++ < info->pos)
		current = current->prev;
	info->current = current;
	info->len = 1;
	while (current && current->prev != lst->current)
	{
		// printf("check (%zd) with (%zd)\n", (ssize_t)current->prev->value, (ssize_t)current->value);
		if ((ssize_t)current->prev->value < (ssize_t)current->value)
			break ;
		++info->len;
		current = current->prev;
	}
	// if (info->pos + info->len < lst->size && info->len == 1)
	// 	++info->len;
	// if (info->len == 3)
	// {
	// 	i = 0;
	// 	while (i++ < 8 && (ssize_t)current->prev->value < (ssize_t)current->value)
	// 		current = current->prev;
	// 	if (i > 2)
	// 	{
	// 		++info->pos;
	// 		return (ft_ps_length_end(lst, info));
	// 	}
	// }
	return (ft_ps_cost_end(lst, info));
}

