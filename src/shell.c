#include "push_swap.h"
#include "ft_printer.h"
#include <stdio.h>

void	ft_ps_start_shell(void)
{
	char		cmd[51];
	size_t		len;
	int			count = 0;
	t_search	*search;

	ft_printer_init(1)->add("$> ");
	while (fgets(cmd, 50, stdin))
	{
		len = ft_strlen(cmd);
		if (cmd[len - 1] == '\n')
		{
			cmd[len - 1] = 0;
			--len;
		}
		if (!ft_strcmp(cmd, "exit"))
		{
			printf("ops-> %d\n", count);
			return ;
		}
		else if (!ft_strcmp(cmd, "print"))
			ft_ps_print_status();
		else if (!ft_strcmp(cmd, "search_begin"))
		{
			ft_ps_is_sort(ft_ps_get_instance()->a);
			search = ft_ps_search_begin(ft_ps_get_instance()->a);
			printf("begin pos(%zu), len(%zu), cost(%zu), reverse(%d)\n", search->pos, search->len, search->cost, search->reverse);
			ft_ps_print_l_search(ft_ps_get_instance()->a, " A ", search);
		}
		else if (!ft_strcmp(cmd, "search_end"))
		{
			ft_ps_is_sort(ft_ps_get_instance()->a);
			search = ft_ps_search_end(ft_ps_get_instance()->a);
			printf("end pos(%zu), len(%zu), cost(%zu), reverse(%d)\n", search->pos, search->len, search->cost, search->reverse);
			search->pos = ft_ps_get_instance()->a->size - search->pos - search->len + 1;
			ft_ps_print_l_search(ft_ps_get_instance()->a, " A ", search);
		}
		else if (!ft_ps_do_op(cmd))
			ft_printer_init(2)->add("Invalid command: [")->add(cmd)->add("]");
		else
		{
			++count;
			ft_ps_print_status();
		}
		ft_printer_init(1)->add("\n$> ");
	}
}