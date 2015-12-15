/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:27 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:27 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void	ft_printf_parse_pointer_2(t_printf *inst)
{
	int	width;

	if (inst->out->v_precision > 0)
	{
		width = inst->out->v_precision;
		inst->out->v_min_field_width = 0;
		inst->out->add(inst->out, "0x");
		inst->out->v_min_field_width = width;
		inst->out->v_char_fill = '0';
		inst->out->add(inst->out, "0");
	}
	else if (inst->out->v_zero_precision)
	{
		inst->out->v_zero_precision = false;
		inst->out->add(inst->out, "0x");
	}
	else
		inst->out->add(inst->out, "0x0");
}

void		ft_printf_parse_pointer(void)
{
	static t_printf		*inst = 0;
	void				*ptr;
	int					width;

	if (!inst)
		inst = ft_printf_instance();
	ptr = va_arg(inst->args, void *);
	if (ptr)
	{
		inst->out->v_alternate_form = true;
		inst->out->addlx(inst->out, (unsigned long)ptr);
	}
	else if (inst->out->v_min_field_width > 0 && ft_printf_has_flag('0'))
	{
		width = inst->out->v_min_field_width;
		inst->out->v_min_field_width = 0;
		inst->out->add(inst->out, "0x");
		inst->out->v_min_field_width = width - 2;
		inst->out->v_char_fill = '0';
		inst->out->add(inst->out, "0");
	}
	else
		ft_printf_parse_pointer_2(inst);
}
