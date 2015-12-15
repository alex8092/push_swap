/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_octal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:27 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:27 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_octal(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (inst->out->v_precision == 0 && inst->out->v_zero_precision && \
		!ft_printf_has_flag('#'))
		return ;
	if (inst->type_modifier == TYPE_MODIF_HH)
		inst->out->addo(inst->out, (unsigned char)va_arg(inst->args, int));
	else if (inst->type_modifier == TYPE_MODIF_H)
		inst->out->addo(inst->out, (unsigned short)va_arg(inst->args, int));
	else
		inst->out->addo(inst->out, (unsigned int)va_arg(inst->args, int));
}
