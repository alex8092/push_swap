/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:25 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_common.h"

void	ft_printf_get_size(void)
{
	static t_printf	*inst = 0;
	long int		size;

	if (!inst)
		inst = ft_printf_instance();
	size = ft_atoi((const char *)(inst->str + inst->index));
	if (size)
	{
		if (size < 0)
			++inst->index;
		while (inst->str[inst->index] >= '0' && inst->str[inst->index] <= '9')
			++inst->index;
		if (size < 0)
			return ;
		inst->out->v_min_field_width = size;
	}
	else if (inst->str[inst->index] == '*')
	{
		inst->out->v_min_field_width = va_arg(inst->args, int);
		++inst->index;
	}
}
