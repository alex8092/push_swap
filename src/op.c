#include "push_swap.h"

static t_op		ops[] =
{
	{
		"ra",
		&ft_ps_exec_rotatea
	},
	{
		"rb",
		&ft_ps_exec_rotateb
	},
	{
		"rra",
		&ft_ps_exec_rotatea_reverse
	},
	{
		"rrb",
		&ft_ps_exec_rotateb_reverse
	},
	{
		"pa",
		&ft_ps_exec_pusha
	},
	{
		"pb",
		&ft_ps_exec_pushb
	},
	{
		"sa",
		&ft_ps_exec_swapa
	},
	{
		"sb",
		&ft_ps_exec_swapb
	},
	{
		"ss",
		&ft_ps_exec_swap_all
	},
	{
		"rr",
		&ft_ps_exec_rotate_all
	},
	{
		"rrr",
		&ft_ps_exec_rotate_reverse_all
	}
};

t_bool				ft_ps_do_op(const char *op)
{
	const size_t	len = sizeof(ops) / sizeof(t_op);
	size_t			i;

	i = 0;
	while (i < len)
	{
		if (!ft_strcmp(ops[i].name, op))
		{
			ops[i].exec();
			printf("op [%s]\n", ops[i].name);
			return (true);
		}
		++i;
	}
	return (false);
}