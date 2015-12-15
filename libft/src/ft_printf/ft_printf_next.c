/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:25 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_printer.h"

static void	ft_printf_next_is_arg(t_printf *inst, char *ptr)
{
	const char	*tmp;
	int			i;

	tmp = inst->str + inst->index;
	inst->out->addn(inst->out, tmp, ptr - inst->str - inst->index);
	i = 1;
	while (*(ptr + i) == ' ')
		++i;
	if (*(ptr + i) == '%')
	{
		inst->out->addc(inst->out, '%');
		inst->index = ptr - inst->str + i + 1;
	}
	else
	{
		inst->index = (ptr - inst->str) + 1;
		ft_printf_dispatch_arg();
	}
}

void		ft_printf_next(void)
{
	static t_printf		*inst = 0;
	char				*ptr;

	if (!inst)
		inst = ft_printf_instance();
	while (inst->index < inst->size)
	{
		if ((ptr = ft_strchr(inst->str + inst->index, '%')))
			ft_printf_next_is_arg(inst, ptr);
		else
		{
			ptr = (char *)(inst->str + inst->last_index);
			inst->out->addn(inst->out, ptr, inst->size - inst->last_index);
			inst->index = inst->size;
		}
		inst->last_index = inst->index;
	}
}
