/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:02:10 by jforner           #+#    #+#             */
/*   Updated: 2022/02/26 17:11:44 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

int	digitcount(char *str)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] >= '0' && str[i] <= '9')
			count++;
	return (count);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	freedom(pthread_t *th, t_philo **philo)
{
	t_table	*table;
	int		i;

	if (th)
		free(th);
	if (*philo)
	{
		if (philo[0]->table)
		{	
			table = philo[0]->table;
			if (table->caneat)
				free(table->caneat);
			if (table->tabfork)
				free(table->tabfork);
			pthread_mutex_destroy(&table->mutex);
			pthread_mutex_destroy(&table->dying);
			// pthread_mutex_destroy(&table->order);
			i = -1;
			while (++i < ft_atoi(philo[0]->argv[1]))
				pthread_mutex_destroy(&table->mutexfork[i]);
			free(table->mutexfork);
			free(table);
		}
		free(*philo);
	}
	return (0);
}
