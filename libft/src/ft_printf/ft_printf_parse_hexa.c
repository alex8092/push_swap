/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:25 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_hexa(void)
{
	static t_printf		*inst = 0;
	int					value;

	if (!inst)
		inst = ft_printf_instance();
	if (inst->out->v_precision == 0 && inst->out->v_zero_precision)
		return ;
	if (inst->type_modifier == TYPE_MODIF_HH)
		value = (unsigned char)va_arg(inst->args, int);
	else if (inst->type_modifier == TYPE_MODIF_H)
		value = (unsigned short)va_arg(inst->args, int);
	else
		value = va_arg(inst->args, int);
	ft_printf_add_hexa(value, 0);
}
