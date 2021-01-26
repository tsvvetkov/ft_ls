/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_parse_args.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:49:03 by yshawn            #+#    #+#             */
/*   Updated: 2020/12/03 20:40:21 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AV_PARSE_ARGS_H
# define AV_PARSE_ARGS_H

# include "libft.h"
# include "ft_printf.h"
# include <inttypes.h>

/*
** simple parser for arguments
** consider any cases:
** ./program -l -r ... args
** ./program "-lxyz -r ...args"
** ./program "-asd" ... "-r" ... "args_1"
*/

/*
** case of bad malloc, etc returns NULL
** case of 'bad, empty' args AV_EMPTY_ARGS returns 1:
** ./program "" "" ""
** ./program "" '' ""
*/

# define AV_EMPTY_ARGS ({av_error(-1);})
# define AV_FIN(splited_av, err)({av_free_splited(splited_av); return (err);})

char		**av_split(int ac, const char *argv[]);
void		av_print(char **av);
void		av_free(char ***av);
uint8_t		av_error(int8_t n);

#endif
