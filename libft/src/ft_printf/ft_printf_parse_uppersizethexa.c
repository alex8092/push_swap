/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_uppersizethexa.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:28 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:28 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_uppersizethexa(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (inst->out->v_precision == 0 && inst->out->v_zero_precision)
		return ;
	inst->out->v_upper = true;
	ft_printf_add_hexa(va_arg(inst->args, size_t), 2);
}
