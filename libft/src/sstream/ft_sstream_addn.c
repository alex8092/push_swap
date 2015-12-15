/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstream_addn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 06:41:30 by amerle            #+#    #+#             */
/*   Updated: 2015/01/22 06:41:30 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream_private.h"

t_sstream	*ft_sstream_addn(t_sstream *ss, const char *str, size_t n)
{
	if (ss->v_precision != 0 && n > ss->v_precision)
		n = ss->v_precision;
	else if (ss->v_zero_precision)
		n = (!str[0] && ss->v_min_field_width) ? 1 : 0;
	ft_sstream_get_alignement(ss, n, false);
	if (!ss->v_zero_precision)
		ft_string_appn(ss->str, str, n);
	else if (str[0] == 0 && ss->v_zero_precision)
		ft_string_appn(ss->str, str, 1);
	ft_sstream_get_alignement(ss, n, true);
	return (ft_sstream_reset_modifiers(ss));
}
