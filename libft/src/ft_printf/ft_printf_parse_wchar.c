/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_wchar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:28 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:28 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_wchar(void)
{
	static t_printf		*inst = 0;
	wint_t				c;
	wchar_t				c2[2];

	if (!inst)
		inst = ft_printf_instance();
	c = va_arg(inst->args, wint_t);
	c2[0] = (wchar_t)c;
	c2[1] = 0;
	if (!c2[0])
		inst->out->addc(inst->out, '\0');
	else
		inst->out->addwn(inst->out, c2, 1);
}
