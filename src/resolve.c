#include "push_swap.h"

static void	ft_ps_resolve_begin(size_t n, size_t length)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		ft_ps_do_op("ra");
	if (length == 1)
		ft_ps_do_op("pb");
	else if (length == 2)
		ft_ps_do_op("sa");
	else
	{
		i = 0;
		while (i++ < length)
		{
			ft_ps_do_op("pb");
			ft_ps_do_op("rb");
		}
	}
}

static void	ft_ps_resolve_end(size_t n, size_t length)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		ft_ps_do_op("rra");
	if (length == 1)
	{
		ft_ps_do_op("rra");
		ft_ps_do_op("pb");
	}
	else if (length == 2)
	{
		ft_ps_do_op("rra");
		ft_ps_do_op("rra");
		ft_ps_do_op("sa");
	}
	else
	{
		i = 0;
		while (i++ < length)
		{
			ft_ps_do_op("rra");
			ft_ps_do_op("pb");
		}
	}
}

void		ft_ps_resolve(void)
{
	t_dlist		*a;
	size_t		i;
	size_t		databegin[3];
	size_t		dataend[3];

	i = 0;
	a = ft_ps_get_instance()->a;
	ft_ps_print_status();
	while (!ft_ps_is_sort(a))
	{
		// find_next_swap(a);
		ft_ps_print_status();
		databegin[0] = ft_ps_find_begin_anomaly(a);
		databegin[1] = ft_ps_find_length_begin(a, databegin[0]);
		databegin[2] = ft_ps_cost_begin(databegin[0], databegin[1]);
		printf("begin pos(%ld), length(%ld), cost(%ld)\n", databegin[0], databegin[1], databegin[2]);
		dataend[0] = ft_ps_find_end_anomaly(a);
		dataend[1] = ft_ps_find_length_end(a, dataend[0]);
		dataend[2] = ft_ps_cost_end(dataend[0], dataend[1]);
		printf("end pos(%ld), length(%ld), cost(%ld)\n", dataend[0], dataend[1], dataend[2]);
		// if (databegin[2] < dataend[2])
		// 	ft_ps_resolve_begin(databegin[0], databegin[1]);
		// else
		// 	ft_ps_resolve_end(dataend[0], dataend[1]);
		++i;
		break ;
	}
	(void)ft_ps_resolve_begin;
	(void)ft_ps_resolve_end;
	ft_ps_print_status();
	printf("op (%ld)\n", i);
}