#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dlist.h"

/*
** List info
*/
typedef struct		s_lstinfo
{
	ssize_t			min;
	ssize_t			max;
}					t_lstinfo;

/*
** Push swap structure
*/
typedef struct		s_ps
{
	const char		*err;
	t_dlist			*a;
	t_dlist			*b;
}					t_ps;


typedef struct		s_op
{
	const char		*name;
	void			(*exec)(void);
}					t_op;

/*
** reader.c
*/
void				ft_ps_reader_parse_arg(char **av, int ac);

/*
** print.c
*/
void				ft_ps_print_status(void);
void				ft_ps_print_list(t_dlist *lst, const char *before);

/*
** search.c
*/
size_t				ft_ps_find_begin_anomaly(t_dlist *lst);
size_t				ft_ps_find_end_anomaly(t_dlist *lst);
size_t				ft_ps_find_length_begin(t_dlist *lst, size_t n);
size_t				ft_ps_find_length_end(t_dlist *lst, size_t n);

/*
** op.c
*/
t_bool				ft_ps_do_op(const char *op);

/*
** resolve.c
*/
void				ft_ps_resolve(void);

/*
** check.c
*/
t_bool				ft_ps_is_sort(t_dlist *l);

/*
** rotate.c
*/
void				ft_ps_exec_rotatea(void);
void				ft_ps_exec_rotatea_reverse(void);
void				ft_ps_exec_rotateb(void);
void				ft_ps_exec_rotateb_reverse(void);

/*
** cost.c
*/
size_t				ft_ps_cost_begin(size_t n, size_t length);
size_t				ft_ps_cost_end(size_t n, size_t length);

/*
** rotate_double.c
*/
void				ft_ps_exec_rotate_all(void);
void				ft_ps_exec_rotate_reverse_all(void);

/*
** push.c
*/
void				ft_ps_exec_pusha(void);
void				ft_ps_exec_pushb(void);

/*
** swap.c
*/
void				ft_ps_exec_swapa(void);
void				ft_ps_exec_swapb(void);
void				ft_ps_exec_swap_all(void);

/*
** shell.c
*/
void				ft_ps_start_shell(void);

/*
** push_swap.c
*/
t_ps				*ft_ps_get_instance(void);

#endif