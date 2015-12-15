/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:24 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:24 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_add_number(long long i)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (ft_printf_has_flag('0') && inst->out->v_min_field_width > 0)
	{
		if (i < 0 || ft_printf_has_flag('+') || ft_printf_has_flag(' '))
		{
			if (i == 0)
				inst->out->v_left_align = true;
			else
				inst->out->v_precision = inst->out->v_min_field_width - 1;
		}
	}
	if (inst->out->v_precision == 0 && inst->out->v_zero_precision)
		return ;
	inst->out->addll(inst->out, i);
}
