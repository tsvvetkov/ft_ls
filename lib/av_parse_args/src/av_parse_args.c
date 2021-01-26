/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:39:17 by yshawn            #+#    #+#             */
/*   Updated: 2020/12/03 20:41:26 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "av_parse_args.h"

static void		av_free_splited(char ***splited_av)
{
	int32_t	i;

	if (!splited_av)
		return ;
	i = 0;
	while (splited_av[i])
	{
		ft_arrdel((void ***)&splited_av[i]);
		i++;
	}
	free(splited_av);
}

static char		**av_convert_copy(char **converted_av, const char ***splited_av)
{
	int32_t	i;
	int32_t	j;
	int32_t	n;

	i = 0;
	n = 0;
	while (splited_av[i])
	{
		j = 0;
		while (splited_av[i][j])
		{
			if (!(converted_av[n] = ft_strdup(splited_av[i][j])))
			{
				ft_arrdel((void ***)&converted_av);
				return (NULL);
			}
			n++;
			j++;
		}
		i++;
	}
	converted_av[n] = NULL;
	return (converted_av);
}

static char		**av_convert(const char ***splited_av)
{
	char	**converted_av;
	int32_t	i;
	int32_t	j;
	int32_t	count;

	i = 0;
	count = 0;
	while (splited_av[i])
	{
		j = 0;
		while (splited_av[i][j++])
			count++;
		i++;
	}
	if (!(converted_av = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (!(av_convert_copy(converted_av, splited_av)))
	{
		free(converted_av);
		converted_av = NULL;
	}
	return (converted_av);
}

uint8_t			av_check_empty_args(char ***splited_av, int ac, \
									int is_empty_args)
{
	if (is_empty_args == 1 && ac > 0)
	{
		av_error(1);
		AV_FIN(splited_av, 1);
	}
	return (0);
}

char			**av_split(int ac, const char *argv[])
{
	int32_t	i;
	int32_t is_empty_args;
	char	***splited_av;
	char	**av;

	ac--;
	argv++;
	i = 0;
	is_empty_args = 1;
	if (!(splited_av = (char ***)malloc(sizeof(char **) * (ac + 1))))
		return (NULL);
	splited_av[ac] = NULL;
	while (i < ac)
	{
		splited_av[i] = ft_strsplit(argv[i], ' ');
		if (!splited_av[i])
			AV_FIN(splited_av, NULL);
		if (splited_av[i][0])
			is_empty_args = 0;
		i++;
	}
	if (av_check_empty_args(splited_av, ac, is_empty_args))
		return (NULL);
	av = av_convert((const char ***)splited_av);
	AV_FIN(splited_av, av);
}
