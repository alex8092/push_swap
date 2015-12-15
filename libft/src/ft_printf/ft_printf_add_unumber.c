/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_unumber.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:24 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:24 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_add_unumber(unsigned long long i)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	inst->out->v_always_sign = false;
	inst->out->v_space_or_sign = false;
	if (inst->out->v_precision == 0 && inst->out->v_zero_precision)
		return ;
	inst->out->addull(inst->out, i);
}
