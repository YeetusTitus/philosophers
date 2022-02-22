/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:56:25 by jforner           #+#    #+#             */
/*   Updated: 2022/02/21 16:00:07 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = -1;
	nbr = 0;
	while (++i < (int)ft_strlen(str))
	{
		nbr *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			nbr += (str[i] - '0');
	}
	return (nbr);
}

unsigned long	ft_uatol(char *str)
{
	long			i;
	unsigned long	nbr;

	i = -1;
	nbr = 0;
	while (++i < (long)ft_strlen(str))
	{
		nbr *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			nbr += (str[i] - '0');
	}
	return (nbr);
}

int	verif_int(char **argv, int argc, char *error)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (digitcount(argv[i]) > 10 || ft_uatol(argv[i]) > 2147483647)
		{
			*error = 'i';
			return (0);
		}
	}
	return (1);
}

int	verif_isdigit(int argc, char **argv, char *error)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ')
				|| ((argv[i][j] >= '0' || argv[i][j] <= '9')
				&& ((argv[i][j + 1] < '0' || argv[i][j + 1] > '9')
					&& argv[i][j + 1] != 0))
				|| (argv[i][j] == ' ' && argv[i][j] != 0))
			{
				*error = 'd';
				return (0);
			}
		}
	}
	return (1);
}

int	parse(int argc, char **argv, char *error)
{
	*error = '0';
	if (argc < 5 || argc > 6)
	{
		*error = 'n';
		return (0);
	}
	if (!verif_isdigit(argc, argv, error)
		|| !verif_int(argv, argc, error))
		return (0);
	if (!ft_atoi(argv[1]))
	{
		*error = 'p';
		return (0);
	}
	return (1);
}
