/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:24 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:24 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_add_hexa(long long i, int func)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (ft_printf_has_flag('#'))
		inst->out->v_alternate_form = true;
	if (ft_printf_has_flag('0') && inst->out->v_min_field_width > 0)
	{
		if (i < 0 || ft_printf_has_flag('+'))
			inst->out->v_precision = inst->out->v_min_field_width - 2;
	}
	if (func == 0)
		inst->out->addx(inst->out, i);
	else if (func == 1)
		inst->out->addlx(inst->out, i);
	else if (func == 2)
		inst->out->addllx(inst->out, i);
}
