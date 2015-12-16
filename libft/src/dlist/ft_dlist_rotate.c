#include "ft_dlist.h"

static void		rotate_left(t_dlist *lst)
{
	t_dlist_it	*tmp;

	if (lst->begin && lst->end != lst->begin)
	{
		ft_dlist_pop_front(lst, &tmp);
		ft_dlist_push_back(lst, tmp);
	}
}

static void		rotate_right(t_dlist *lst)
{
	t_dlist_it	*tmp;

	if (lst->begin && lst->end != lst->begin)
	{
		ft_dlist_pop_back(lst, &tmp);
		ft_dlist_push_front(lst, tmp);
	}
}

t_dlist			*ft_dlist_rotate(t_dlist *lst, t_bool left)
{
	if (left)
		rotate_left(lst);
	else
		rotate_right(lst);
	return (lst);
}