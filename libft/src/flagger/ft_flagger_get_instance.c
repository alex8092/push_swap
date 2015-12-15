#include "ft_flagger.h"

t_flagger				*ft_flagger_get_instance(void)
{
	static t_flagger	instance;
	static int			init = 0;

	if (!init)
	{
		ft_bzero((void *)&instance, sizeof(instance));
		instance.flags = ft_dlist_new();
		instance.add_flag = &ft_flagger_add_flag;
		instance.parse = &ft_flagger_parse;
		init = 1;
	}
	return (&instance);
}