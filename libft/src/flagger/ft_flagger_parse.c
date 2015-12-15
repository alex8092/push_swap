#include "ft_flagger.h"

static void		parse_long_flag(t_flagger *f, const char *flag)
{
	t_dlist_it	*current;
	t_flag		*oflag;

	current = f->flags->begin;
	while (current)
	{
		oflag = (t_flag *)current->value;
		if (oflag->lname && !ft_strcmp(oflag->lname, flag))
		{
			oflag->active = true;
			return ;
		}
		current = current->next;
	}
}

static void		active_flag(t_flagger *f, const char c)
{
	t_dlist_it	*current;
	t_flag		*oflag;

	current = f->flags->begin;
	while (current)
	{
		oflag = (t_flag *)current->value;
		if (oflag->c && oflag->c == c)
		{
			oflag->active = true;
			return ;
		}
		current = current->next;
	}
}

static void		parse_short_flag(t_flagger *f, const char *flag)
{
	int			i;

	i = 0;
	while (flag[i])
	{
		active_flag(f, flag[i]);
		++i;
	}
}

t_flagger		*ft_flagger_parse(char **av, int ac)
{
	t_flagger	*f;

	f = ft_flagger_get_instance();
	f->next_arg = 0;
	while (f->next_arg < ac && av[f->next_arg][0] == '-')
	{
		if (av[f->next_arg][1] == '-' && !av[f->next_arg][2])
		{
			++f->next_arg;
			break ;
		}
		else if (av[f->next_arg][1] == '-')
			parse_long_flag(f, av[f->next_arg] + 2);
		else
			parse_short_flag(f, av[f->next_arg] + 1);
		++f->next_arg;
	}
	return (f);
}