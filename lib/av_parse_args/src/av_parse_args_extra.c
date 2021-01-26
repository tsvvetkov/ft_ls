/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_parse_args_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:39:17 by yshawn            #+#    #+#             */
/*   Updated: 2020/12/03 20:41:39 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "av_parse_args.h"

uint8_t		av_error(int8_t n)
{
	static uint8_t err = 0;

	if (n >= 0)
		err = n;
	return (err);
}

void		av_print(char **av)
{
	int32_t i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		ft_printf("%s\n", av[i]);
		i++;
	}
}

void		av_free(char ***av)
{
	ft_arrdel((void ***)av);
}
