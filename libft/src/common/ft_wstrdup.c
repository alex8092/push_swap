/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 05:34:29 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:34:29 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"
#include <stdlib.h>
#include <stdint.h>
#include <wchar.h>

wchar_t	*ft_wstrdup(const wchar_t *s)
{
	wchar_t			*str;
	const size_t	len = ft_wstrlen(s);
	const size_t	size = (len + 1) * sizeof(wchar_t);

	str = malloc(size);
	return ((str) ? (wchar_t *)ft_memcpy(str, s, size) : NULL);
}
