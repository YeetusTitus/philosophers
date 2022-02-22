/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createphilo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:44:06 by jforner           #+#    #+#             */
/*   Updated: 2022/02/22 18:05:20 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	createphilos2(t_philo *philo, char **argv, t_table **table)
{
	int			i;

	i = -1;
	(*table)->isdead = 1;
	pthread_mutex_init(&(*table)->mutex, NULL);
	while (++i < ft_atoi(argv[1]))
	{
		philo[i].class = i + 1;
		philo[i].argv = argv;
		if (tablen(argv) == 6)
			philo[i].turn = ft_atoi(argv[6]);
		else
			philo[i].turn = -1;
		philo[i].fork = 0;
		(*table)->tabfork[i] = 1;
		if (i % 2 == 0)
			(*table)->caneat[i] = 1;
		else
			(*table)->caneat[i] = 0;
		philo[i].table = *table;
	}
	return (1);
}

int	createphilos(t_philo *philo, char *error, char **argv)
{
	t_table		*table;
	int			test;

	table = (t_table *)malloc(sizeof(t_table));
	if (!philo || !table)
		return (!(*error = 'm'));
	table->caneat = (int *)malloc((ft_atoi(argv[1])) * sizeof(int));
	table->tabfork = (int *)malloc((ft_atoi(argv[1])) * sizeof(int));
	if (!table->caneat || !table->tabfork)
		return (!(*error = 'm'));
	test = createphilos2(philo, argv, &table);
	return (test);

}
