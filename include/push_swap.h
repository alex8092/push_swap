#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dlist.h"
# include "ft_clist.h"

/*
** List info
*/
typedef struct		s_lstinfo
{
	ssize_t			min;
	ssize_t			max;
}					t_lstinfo;

/*
** search helper
*/
typedef struct		s_search
{
	size_t			pos;
	size_t			len;
	size_t			cost;
	t_bool			reverse;
	t_clist_it		*current;
}					t_search;

/*
** Push swap structure
*/
typedef struct		s_ps
{
	const char		*err;
	t_clist			*a;
	t_clist			*b;
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
void				ft_ps_print_list(t_clist *lst, const char *before);

/*
** search.c
*/
t_search			*ft_ps_search_begin(t_clist *lst);
t_search			*ft_ps_search_end(t_clist *lst);

/*
** length.c
*/
t_search			*ft_ps_length_begin(t_clist *lst, t_search *info);
t_search			*ft_ps_length_end(t_clist *lst, t_search *info);

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
t_bool				ft_ps_is_sort(t_clist *l);

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
t_search			*ft_ps_cost_begin(t_clist *lst, t_search *info);
t_search			*ft_ps_cost_end(t_clist *lst, t_search *info);
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