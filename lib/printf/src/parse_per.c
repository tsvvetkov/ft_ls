/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:31:23 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:56:32 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_per(t_format *spec, va_list vl)
{
	int		str_len;
	char	*str;

	if (!vl)
		return (0);
	str = NULL;
	str_len = spec->width;
	if (str_len > 1)
		str = record_per(spec, str_len);
	else
	{
		write(spec->fd, "%", 1);
		return (1);
	}
	write(spec->fd, str, str_len);
	free(str);
	return (str_len);
}
