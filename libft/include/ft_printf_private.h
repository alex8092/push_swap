/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:23:40 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:23:41 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>
# include <stdint.h>
# include "ft_printf.h"
# include "ft_string.h"
# include "ft_sstream.h"

# define TYPE_MODIF_HH			4
# define TYPE_MODIF_H			3

typedef struct s_printf			t_printf;
typedef struct s_printf_opt		t_printf_opt;
typedef struct s_printf_flag	t_printf_flag;

struct			s_printf_opt
{
	char		*ident;
	size_t		size;
	void		(*parse[7])(void);
};

struct			s_printf_flag
{
	char		ident;
	t_bool		active;
};

struct			s_printf
{
	va_list		args;
	const char	*str;
	size_t		last_index;
	size_t		index;
	size_t		size;
	size_t		minus_ret_size;
	size_t		type_modifier;
	t_sstream	*out;
};

t_printf		*ft_printf_instance(void);
void			ft_printf_get_size(void);
void			ft_printf_get_precision(void);
void			ft_printf_get_typemodifiers(void);
void			ft_printf_dispatch_arg(void);
void			ft_printf_next(void);
void			ft_printf_get_flags(void);
t_bool			ft_printf_has_flag(char c);
void			ft_printf_disable_flag(char c);
void			ft_printf_reset_flags(void);
void			ft_printf_parse_char_nova(char c);
void			ft_printf_add_number(long long number);
void			ft_printf_add_unumber(unsigned long long number);
void			ft_printf_add_hexa(long long i, int func);
void			ft_printf_parse_string(void);
void			ft_printf_parse_wstring(void);
void			ft_printf_parse_sizet(void);
void			ft_printf_parse_pointer(void);
void			ft_printf_parse_intmax(void);
void			ft_printf_parse_short(void);
void			ft_printf_parse_percent(void);
void			ft_printf_parse_int(void);
void			ft_printf_parse_longint(void);
void			ft_printf_parse_longlong(void);
void			ft_printf_parse_octal(void);
void			ft_printf_parse_longoctal(void);
void			ft_printf_parse_longlongoctal(void);
void			ft_printf_parse_longlonghexa(void);
void			ft_printf_parse_intmaxoctal(void);
void			ft_printf_parse_sizetoctal(void);
void			ft_printf_parse_uintmax(void);
void			ft_printf_parse_usizet(void);
void			ft_printf_parse_unsigned(void);
void			ft_printf_parse_longunsigned(void);
void			ft_printf_parse_ulonglong(void);
void			ft_printf_parse_uintmaxhexa(void);
void			ft_printf_parse_sizethexa(void);
void			ft_printf_parse_hexa(void);
void			ft_printf_parse_longhexa(void);
void			ft_printf_parse_upperhexa(void);
void			ft_printf_parse_upperlhexa(void);
void			ft_printf_parse_upperllhexa(void);
void			ft_printf_parse_upperintmaxhexa(void);
void			ft_printf_parse_uppersizethexa(void);
void			ft_printf_parse_sizethexa(void);
void			ft_printf_parse_char(void);
void			ft_printf_parse_wchar(void);

#endif
