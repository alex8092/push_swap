#include "push_swap.h"
#include "ft_common.h"
#include "ft_printf.h"

static int			is_out_of_bound(const char *arg, int neg)
{
	const char	*ref = "2147483647";
	int			i;

	i = 0;
	while (ref[i] && (arg[i + neg] - '0') == (ref[i] - '0'))
		++i;
	if (!ref[i])
		return (1);
	if (!ref[i + 1] && neg)
		return (((arg[i + neg] - '0') > (ref[i] - '0' + 1)) ? 0 : 1);
	return (((arg[i + neg] - '0') > (ref[i] - '0')) ? 0 : 1);
}

static int			is_valid_digit(const char *arg)
{
	int				i;

	if (!arg)
		return (0);
	i = 0;
	if (arg[0] == '-')
		++i;
	while (arg[i] && ft_isnum(arg[i]))
		++i;
	if (arg[i])
		return (0);
	if (arg[0] == '-')
		--i;
	if (i > 10)
		return (0);
	else if (i == 10)
		return (is_out_of_bound(arg, arg[0] == '-'));
	return (1);
}

static int			is_unique(t_dlist *lst, ssize_t n)
{
	t_dlist_it		*current;

	current = lst->begin;
	while (current)
	{
		if (((ssize_t)current->value) == n)
			return (0);
		current = current->next;
	}
	return (1);
}

static char			*prepare(char *av)
{
	int		neg;
	int		i;

	if (av[0] == '+')
		return prepare(av + 1);
	neg = (av[0] == '-') ? 1 : 0;
	i = 0;
	while (av[neg + i] == '0')
		++i;
	if (i != 0)
	{
		if (av[i + neg] == '-')
			return (0);
		else if (neg)
		{
			av[i + neg - 1] = '-';
			av[0] = '0';
			neg = 0;
		}
		return (av + i - neg);
	}
	return (av);
}

void				ft_ps_reader_parse_arg(char **av, int ac)
{
	t_ps			*ps;
	int				i;
	ssize_t			n;

	ps = ft_ps_get_instance();
	ps->b = ft_dlist_new();
	ps->a = ft_dlist_new();
	i = 0;
	while (i < ac && is_valid_digit(prepare(av[i])))
	{
		n = (ssize_t)ft_atoi(prepare(av[i]));
		if (!is_unique(ps->a, n))
			break ;
		ps->a = ft_dlist_push_back(ps->a, ft_dlist_it_new((void *)n));
		++i;
	}
	if (i != ac)
		ps->err = "Error\n";
}