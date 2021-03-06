/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:07:36 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/07 00:55:17 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function checks for a digit (0 through 9).
**
** Функция проверяет, является ли символ цифрой (от нуля до 9-и).
*/

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}
