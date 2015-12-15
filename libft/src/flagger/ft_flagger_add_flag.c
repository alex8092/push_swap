#include "ft_flagger.h"
#include "ft_common.h"

t_flagger				*ft_flagger_add_flag(char c, char *lname, int av)
{
	t_flagger			*f;
	t_flag				*flag;

	f = ft_flagger_get_instance();
	flag = (t_flag *)ft_memalloc(sizeof(t_flag));
	flag->c = c;
	flag->lname = lname;
	ft_dlist_push_back(f->flags, ft_dlist_it_new((void *)flag));
	(void)av;
	return (f);
}