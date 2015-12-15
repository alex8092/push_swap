#ifndef FT_DLIST_H
# define FT_DLIST_H

# include <unistd.h>

typedef struct			s_dlist
{
	t_dlist_it			*begin;
	t_dlist_it			*end;
	size_t				size;
}						t_dlist;

typedef struct			s_dlist_it
{
	void				*value;
	struct s_dlist_it	*next;
	struct s_dlist_it	*prev;
}						t_dlist_it;

t_dlist					*ft_dlist_new(void);
t_dlist_it				*ft_dlist_it_new(void *value);
t_dlist					*ft_dlist_push_back(t_dlist *lst, t_dlist_it *item);
t_dlist					*ft_dlist_push_front(t_dlist *lst, t_dlist_it *item);

#endif