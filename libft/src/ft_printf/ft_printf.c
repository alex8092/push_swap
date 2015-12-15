/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:24 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:24 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_common.h"
#include "ft_printer.h"

int		ft_printf(const char *format, ...)
{
	static t_printf		*inst = 0;
	int					nprint;

	if (!inst)
		inst = ft_printf_instance();
	ft_bzero((void *)inst, sizeof(*inst));
	va_start(inst->args, format);
	inst->str = format;
	inst->size = ft_strlen(inst->str);
	inst->out = ft_sstream_new();
	ft_printf_next();
	ft_printer_init(1)->addss(inst->out)->flush();
	nprint = inst->out->str->size;
	ft_sstream_del(inst->out);
	va_end(inst->args);
	ft_printf_reset_flags();
	return (nprint - inst->minus_ret_size);
}
