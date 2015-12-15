/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_wstring.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:28 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:28 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_common.h"

void	ft_printf_parse_wstring(void)
{
	static t_printf		*inst = 0;
	wchar_t				*str;
	size_t				size;

	if (!inst)
		inst = ft_printf_instance();
	str = va_arg(inst->args, wchar_t *);
	if (str)
	{
		size = ft_wstrlen(str);
		if (inst->out->v_precision && size > inst->out->v_precision)
			size = inst->out->v_precision * sizeof(wchar_t);
		inst->out->addw(inst->out, str);
	}
	else
		inst->out->add(inst->out, "(null)");
}
