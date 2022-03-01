/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createphilo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:44:06 by jforner           #+#    #+#             */
/*   Updated: 2022/02/26 17:24:02 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	tableset(t_table **table, int len)
{
	struct timeval	start;
	int				i;

	(*table)->isdead = 1;
	(*table)->peer = 1;
	pthread_mutex_init(&(*table)->mutex, NULL);
	pthread_mutex_init(&(*table)->dying, NULL);
	(*table)->mutexfork = malloc(len * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < len)
		pthread_mutex_init(&(*table)->mutexfork[i], NULL);
	gettimeofday(&start, NULL);
	(*table)->t = start.tv_sec * 1000 + start.tv_usec / 1000;
}

int	createphilos2(t_philo *philo, char **argv, t_table **table)
{
	int				i;

	i = -1;
	tableset(table, ft_atoi(argv[1]));
	while (++i < ft_atoi(argv[1]))
	{
		philo[i].class = i + 1;
		philo[i].argv = argv;
		if (tablen(argv) == 6)
			philo[i].turn = ft_atoi(argv[5]);
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
