#include "push_swap.h"
#include "ft_printer.h"
#include "ft_flagger.h"

int	main(int ac, char **av)
{
	int		i;

	ft_printer()->autoflush(true);
	ft_flagger_get_instance()->add_flag('d', "debug", 0);
	ft_flagger_get_instance()->add_flag('i', "interactive", 0);
	ft_flagger_get_instance()->parse(av + 1, ac - 1);
	i = ft_flagger_get_instance()->next_arg + 1;
	if (!av[i])
		return (0);
	ft_ps_reader_parse_arg(av + i, ac - i);
	if (ft_ps_get_instance()->err)
	{
		ft_printer_init(2)->add(ft_ps_get_instance()->err);
		return (1);
	}
	if (ft_flagger_has_flag('i', "interactive"))
		ft_ps_start_shell();
	else
		ft_ps_resolve();
	return (0);
}