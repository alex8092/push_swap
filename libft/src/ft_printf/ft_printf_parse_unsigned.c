/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:28 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:28 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_unsigned(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (inst->type_modifier == TYPE_MODIF_HH)
		ft_printf_add_unumber((unsigned char)va_arg(inst->args, unsigned int));
	else if (inst->type_modifier == TYPE_MODIF_H)
		ft_printf_add_unumber((unsigned short)va_arg(inst->args, unsigned int));
	else
		ft_printf_add_unumber(va_arg(inst->args, unsigned int));
}
