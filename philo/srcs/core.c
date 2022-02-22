/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:13:56 by jforner           #+#    #+#             */
/*   Updated: 2022/02/22 19:04:12 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	gotoeat(int *caneat, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (caneat[i])
			return (1);
	return (0);
}

void	ordereating(t_philo *philo, int	*peer)
{
	if (*peer && !gotoeat(philo->table->caneat, ft_atoi(philo->argv[1])))
		peer[0]--;
	if (!*peer && !gotoeat(philo->table->caneat, ft_atoi(philo->argv[1])))
		peer[0]++;
}

void	*core(void *arg)
{
	t_philo	*philo;
	int		i;
	int		peer;
	int		rightfork;

	i = -1;
	peer = 1;
	philo = (t_philo *)arg;
	if (philo->class == 1)
		rightfork = ft_atoi(philo->argv[1]);
	else
		rightfork = philo->class - 1;
	while (i < ft_atoi(philo->argv[3]))
	{
		if ((peer && philo->class % 2) || (!peer && !(philo->class % 2)))
		{
			pthread_mutex_lock(&philo->table->mutex);
			if (philo->table->tabfork[rightfork - 1]
				&& philo->table->tabfork[philo->class - 1])
			{
				printf("Timestamp %d has taken a fork\n", philo->class);
				printf("Timestamp %d has taken a fork\n", philo->class);
				philo->table->tabfork[rightfork - 1]--;
				philo->table->tabfork[philo->class - 1]--;
				philo->table->caneat[philo->class - 1]--;
			}
			pthread_mutex_unlock(&philo->table->mutex);
		}
		usleep(1);
		i++;
	}
	return (NULL);
}
