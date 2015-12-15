/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:25 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_char(void)
{
	static t_printf		*inst = 0;
	int					value;

	if (!inst)
		inst = ft_printf_instance();
	value = va_arg(inst->args, int);
	if (ft_printf_has_flag('0') && inst->out->v_min_field_width > 0)
	{
		if (value < 0 || ft_printf_has_flag('+'))
			inst->out->v_precision = inst->out->v_min_field_width - 1;
	}
	inst->out->addc(inst->out, (unsigned char)value);
}
