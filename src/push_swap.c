#include "push_swap.h"
#include "ft_common.h"
m
t_ps	*ft_ps_get_instance(void)
{
	static t_ps		instance;
	static int		init = 0;

	if (!init)
	{
		ft_bzero((void *)&instance, sizeof(instance));
		init = 1;
	}
	return (&instance);
}