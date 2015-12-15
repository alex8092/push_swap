/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dispatch_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:24 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:24 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_sstream_private.h"
#include "ft_common.h"

static t_printf_opt		g_opts[] =
{
	{
		"c", 1,
		{
			&ft_printf_parse_char,
			&ft_printf_parse_wchar, 0, 0, 0, 0, 0
		},
	},
	{
		"%", 1,
		{
			&ft_printf_parse_percent, 0, 0, 0, 0, 0, 0
		}
	},
	{
		"C", 1,
		{
			&ft_printf_parse_wchar, 0, 0, 0, 0, 0, 0
		}
	},
	{
		"s", 1,
		{
			&ft_printf_parse_string,
			&ft_printf_parse_wstring, 0, 0, 0, 0, 0
		}
	},
	{
		"S", 1,
		{
			&ft_printf_parse_wstring, 0, 0, 0, 0, 0, 0
		}
	},
	{
		"p", 1,
		{
			&ft_printf_parse_pointer, 0, 0, 0, 0, 0, 0
		}
	},
	{
		"d", 1,
		{
			&ft_printf_parse_int,
			&ft_printf_parse_longint,
			&ft_printf_parse_longlong,
			&ft_printf_parse_int,
			&ft_printf_parse_int,
			&ft_printf_parse_intmax,
			&ft_printf_parse_sizet
		}
	},
	{
		"i", 1,
		{
			&ft_printf_parse_int,
			&ft_printf_parse_longint,
			&ft_printf_parse_longlong,
			&ft_printf_parse_int,
			&ft_printf_parse_int,
			&ft_printf_parse_intmax,
			&ft_printf_parse_sizet
		}
	},
	{
		"D", 1,
		{
			&ft_printf_parse_longint, 0, 0, 0, 0, 0, 0
		}
	},
	{
		"o", 1,
		{
			&ft_printf_parse_octal,
			&ft_printf_parse_longoctal,
			&ft_printf_parse_longlongoctal,
			&ft_printf_parse_octal,
			&ft_printf_parse_octal,
			&ft_printf_parse_intmaxoctal,
			&ft_printf_parse_sizetoctal
		}
	},
	{
		"O", 1,
		{
			&ft_printf_parse_longoctal, 0, 0, 0, 0, 0, 0
		}
	},
	{
		"u", 1,
		{
			&ft_printf_parse_unsigned,
			&ft_printf_parse_longunsigned,
			&ft_printf_parse_ulonglong,
			&ft_printf_parse_unsigned,
			&ft_printf_parse_unsigned,
			&ft_printf_parse_uintmax,
			&ft_printf_parse_usizet
		}
	},
	{
		"U", 1,
		{
			&ft_printf_parse_longunsigned, 0, 0, 0, 0, 0, 0
		}
	},
	{
		"x", 1,
		{
			&ft_printf_parse_hexa,
			&ft_printf_parse_longhexa,
			&ft_printf_parse_longlonghexa,
			&ft_printf_parse_hexa,
			&ft_printf_parse_hexa,
			&ft_printf_parse_uintmaxhexa,
			&ft_printf_parse_sizethexa
		}
	},
	{
		"X", 1,
		{
			&ft_printf_parse_upperhexa,
			&ft_printf_parse_upperlhexa,
			&ft_printf_parse_upperllhexa,
			&ft_printf_parse_upperhexa,
			&ft_printf_parse_upperhexa,
			&ft_printf_parse_upperintmaxhexa,
			&ft_printf_parse_uppersizethexa
		}
	}
};

static t_bool	f_check_ident(t_printf *inst, size_t i)
{
	size_t	cur;

	cur = 0;
	while (cur < g_opts[i].size)
	{
		if (inst->str[inst->index + cur] != g_opts[i].ident[cur])
			return (false);
		++cur;
	}
	return (true);
}

static void		f_do(t_printf *inst)
{
	ft_printf_get_flags();
	if (ft_printf_has_flag('+'))
		inst->out->v_always_sign = true;
	if (ft_printf_has_flag('#'))
		inst->out->v_alternate_form = true;
	if (ft_printf_has_flag('-'))
		inst->out->v_left_align = true;
	if (ft_printf_has_flag(' '))
		inst->out->v_space_or_sign = true;
	if (ft_printf_has_flag('0') && ft_printf_has_flag('-'))
		ft_printf_disable_flag('0');
	ft_printf_get_size();
	ft_printf_get_precision();
	ft_printf_get_typemodifiers();
	if (ft_printf_has_flag('0'))
		inst->out->v_char_fill = '0';
}

static void		f_do2(t_printf *inst)
{
	const size_t	nopts = sizeof(g_opts) / sizeof(g_opts[0]);
	size_t			i;

	i = 0;
	while (i < nopts)
	{
		if (f_check_ident(inst, i))
		{
			inst->index += g_opts[i].size;
			if (g_opts[i].parse[inst->type_modifier])
				g_opts[i].parse[inst->type_modifier]();
			else
				g_opts[i].parse[0]();
			ft_sstream_reset_modifiers(inst->out);
			return ;
		}
		++i;
	}
	ft_printf_parse_char_nova(inst->str[inst->index]);
	++inst->index;
}

void			ft_printf_dispatch_arg(void)
{
	static t_printf		*inst = 0;
	size_t				last_index;

	if (!inst)
		inst = ft_printf_instance();
	ft_printf_reset_flags();
	inst->type_modifier = 0;
	while (1 && inst->str[inst->index])
	{
		last_index = inst->index;
		f_do(inst);
		f_do2(inst);
		break ;
	}
}
