/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_addn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 06:38:45 by amerle            #+#    #+#             */
/*   Updated: 2015/01/22 06:54:13 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"
#include "ft_common.h"

t_printer	*ft_printer_addn(const char *str, size_t size)
{
	static t_printer	*inst = 0;
	size_t				max;
	char				*tmp;

	if (!inst)
		inst = ft_printer();
	while (size > 0)
	{
		if (inst->size + size >= PRINTER_BUFFER_SIZE - 1)
			ft_printer_flush();
		max = (size > PRINTER_BUFFER_SIZE) ? PRINTER_BUFFER_SIZE - 1 : size;
		ft_memcpy((void *)inst->buffer + inst->size, (const void *)str, max);
		inst->size += max;
		inst->buffer[inst->size] = 0;
		str += max;
		size -= max;
		if (inst->v_autoflush)
		{
			while ((tmp = ft_strchr(inst->buffer, '\n')))
				ft_printer_flushn(tmp - inst->buffer + 1);
		}
	}
	return (inst);
}
