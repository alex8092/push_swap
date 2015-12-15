#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dlist.h"

/*
** Push swap structure
*/
typedef struct		s_ps
{
	int				err;
	t_dlist			*a;
	t_dlist			*b;
}					t_ps;


/*
** reader.c
*/
void				ft_ps_reader_parse_arg(char **av, int ac);

/*
** push_swap.c
*/
t_ps				*ft_ps_get_instance(void);

#endif