#ifndef CLIST_H
# define CLIST_H

# include "ft_common.h"

typedef struct			s_clist_it
{
	void				*value;
	struct s_clist_it	*next;
	struct s_clist_it	*prev;
}						t_clist_it;

typedef struct s_clist	t_clist;

struct					s_clist
{
	t_clist_it			*current;
	size_t				size;
	void				*data;
	t_clist				*(*push_front)(t_clist *, t_clist_it *);
	t_clist				*(*push_back)(t_clist *, t_clist_it *);
	t_clist				*(*rotate)(t_clist *, size_t, t_bool);
	t_clist_it			*(*pop_front)(t_clist *);
	t_clist_it			*(*pop_back)(t_clist *);
};

t_clist_it				*ft_clist_it_new(void *value);
t_clist					*ft_clist_new(void);
t_clist					*ft_clist_push_front(t_clist *l, t_clist_it *it);	
t_clist					*ft_clist_push_back(t_clist *l, t_clist_it *it);
t_clist					*ft_clist_rotate(t_clist *l, size_t n, t_bool right);
t_clist_it				*ft_clist_pop_front(t_clist *l);
t_clist_it				*ft_clist_pop_back(t_clist *l);

#endif