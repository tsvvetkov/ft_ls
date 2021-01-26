/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 06:46:56 by yshawn            #+#    #+#             */
/*   Updated: 2020/05/17 06:47:49 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function checks for a number in a string
** (may contain one sign at the start and digits).
**
** Функция проверяет, является ли строка числом
** (может содержать один знак вначале и цифры).
*/

int				ft_isnumber(const char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+'))
		{
			if (i == 0)
			{
				i++;
				if (str[i])
					continue;
				else
					return (0);
			}
			else
				return (0);
		}
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
