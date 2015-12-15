/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 05:34:27 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:34:27 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

static int		check_1(unsigned char *s)
{
	if ((s[1] & 0xc0) != 0x80 || \
			(s[2] & 0xc0) != 0x80 || \
			(s[0] == 0xe0 && (s[1] & 0xe0) == 0x80) || \
			(s[0] == 0xed && (s[1] & 0xe0) == 0xa0) || \
			(s[0] == 0xef && s[1] == 0xbf && \
			(s[2] & 0xfe) == 0xbe))
		return (1);
	return (0);
}

static int		check_2(unsigned char *s)
{
	if ((s[1] & 0xc0) != 0x80 || \
		(s[2] & 0xc0) != 0x80 || \
		(s[3] & 0xc0) != 0x80 || \
		(s[0] == 0xf0 && (s[1] & 0xf0) == 0x80) || \
		(s[0] == 0xf4 && s[1] > 0x8f) || s[0] > 0xf4)
		return (1);
	return (0);
}

static int		do_1(unsigned char **ss)
{
	unsigned char	*s;

	s = *ss;
	if (*s < 0x80)
		s++;
	else if ((s[0] & 0xe0) == 0xc0)
	{
		if ((s[1] & 0xc0) != 0x80 || (s[0] & 0xfe) == 0xc0)
			return (2);
		else
			s += 2;
	}
	else
		return (0);
	*ss = s;
	return (1);
}

unsigned char	*ft_isutf8(unsigned char *s)
{
	int		ret;

	while (*s)
	{
		if ((ret = do_1(&s)))
		{
			if (ret == 2)
				return (s);
		}
		else if ((s[0] & 0xf0) == 0xe0)
		{
			if (check_1(s))
				return (s);
			s += 3;
		}
		else if ((s[0] & 0xf8) == 0xf0)
		{
			if (check_2(s))
				return (s);
			s += 4;
		}
		else
			return (s);
	}
	return (NULL);
}
