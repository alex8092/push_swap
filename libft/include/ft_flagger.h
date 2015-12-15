#ifndef FT_FLAGGER_H
# define FT_FLAGGER_H

# include "ft_dlist.h"
# include "ft_common.h"

typedef struct s_flagger	t_flagger;

typedef struct		s_flag
{
	char			c;
	char			*lname;
	const char		*av;
	t_bool			active;
}					t_flag;

struct				s_flagger
{
	t_dlist			*flags;
	int				next_arg;
	t_flagger		*(*add_flag)(char, char *, int);
	t_flagger		*(*parse)(char **, int);
};

t_flagger			*ft_flagger_get_instance(void);
t_flagger			*ft_flagger_add_flag(char c, char *lname, int av);
t_flagger			*ft_flagger_parse(char **av, int ac);
t_bool				ft_flagger_has_flag(char c, const char *lname);

#endif