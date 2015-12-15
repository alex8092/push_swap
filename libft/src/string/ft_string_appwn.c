/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_appwn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:09:47 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:09:47 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_common.h"
#include <stdlib.h>

t_string	*ft_string_appwn(t_string *s, const wchar_t *str, size_t size)
{
	char	*buffer;

	if (s->size + size * sizeof(wchar_t) > s->reserve)
		ft_string_reserve(s, s->size + size * sizeof(wchar_t));
	buffer = (char *)ft_memalloc(sizeof(char) * 4 * size + 1);
	size = wcstombs(buffer, str, size * sizeof(char) * 4);
	ft_string_appn(s, (const char *)buffer, size);
	free(buffer);
	return (s);
}
