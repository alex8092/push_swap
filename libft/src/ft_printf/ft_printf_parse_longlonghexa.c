/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_longlonghexa.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:26 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:26 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_longlonghexa(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (inst->out->v_precision == 0 && inst->out->v_zero_precision)
		return ;
	ft_printf_add_hexa(va_arg(inst->args, long long), 2);
}
