#include "ft_flagger.h"

static t_bool	search_flag(t_flagger *f, char c, const char *flag)
{
	t_dlist_it	*current;
	t_flag		*oflag;

	current = f->flags->begin;
	while (current)
	{
		oflag = (t_flag *)current->value;
		if (oflag->c && c && oflag->c == c)
			return (oflag->active);
		else if (flag && oflag->lname && !ft_strcmp(oflag->lname, flag))
			return (oflag->active);
		current = current->next;
	}
	return (false);
}

t_bool			ft_flagger_has_flag(char c, const char *lname)
{
	return (search_flag(ft_flagger_get_instance(), c, lname));
}