/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_instance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:25 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_common.h"

t_printf	*ft_printf_instance(void)
{
	static t_printf		inst;
	static t_bool		init = false;

	if (!init)
	{
		ft_bzero((void *)&inst, sizeof(t_printf));
		init = true;
	}
	return (&inst);
}
