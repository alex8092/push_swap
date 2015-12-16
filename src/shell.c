#include "push_swap.h"
#include "ft_printer.h"
#include <stdio.h>

void	ft_ps_start_shell(void)
{
	char	cmd[51];
	size_t	len;
	int		count = 0;

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