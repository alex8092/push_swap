/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_typemodifiers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:25 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_common.h"

void	ft_printf_get_typemodifiers(void)
{
	static t_printf	*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (inst->str[inst->index] == 'l' && inst->str[inst->index + 1] == 'l')
		inst->type_modifier = 2;
	else if (inst->str[inst->index] == 'l')
		inst->type_modifier = 1;
	else if (inst->str[inst->index] == 'h'
			&& inst->str[inst->index + 1] == 'h')
		inst->type_modifier = TYPE_MODIF_HH;
	else if (inst->str[inst->index] == 'h')
		inst->type_modifier = TYPE_MODIF_H;
	else if (inst->str[inst->index] == 'j')
		inst->type_modifier = 5;
	else if (inst->str[inst->index] == 'z')
		inst->type_modifier = 6;
	else
		return ;
	if (inst->type_modifier == 2 || inst->type_modifier == 4)
		inst->index += 2;
	else
		++inst->index;
}
