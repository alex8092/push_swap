/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstream_addwn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:12:34 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:12:34 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream_private.h"
#include <wchar.h>
#include <stdlib.h>

t_sstream	*ft_sstream_addwn(t_sstream *ss, const wchar_t *str,\
								size_t size)
{
	char	*buffer;

	if (ss->v_precision != 0 && size > ss->v_precision)
		size = ss->v_precision;
	buffer = (char *)ft_memalloc(sizeof(char) * size * 4 + 1);
	size = wcstombs(buffer, str, size * sizeof(char) * 4);
	if (ss->v_precision != 0 && size > ss->v_precision)
	{
		size = ss->v_precision;
		buffer[size] = 0;
		while (ft_isutf8((unsigned char *)buffer))
			buffer[--size] = 0;
	}
	if (ss->v_zero_precision)
		size = 0;
	ft_sstream_get_alignement(ss, size, false);
	ft_string_appn(ss->str, buffer, size);
	ft_sstream_get_alignement(ss, size, true);
	return (ft_sstream_reset_modifiers(ss));
}
