/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:27 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:27 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_string(void)
{
	static t_printf		*inst = 0;
	char				*str;

	if (!inst)
		inst = ft_printf_instance();
	str = va_arg(inst->args, char *);
	if (str)
		inst->out->add(inst->out, str);
	else
		inst->out->add(inst->out, "(null)");
}
