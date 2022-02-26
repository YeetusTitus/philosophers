/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:02:08 by jforner           #+#    #+#             */
/*   Updated: 2022/02/26 17:13:22 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	choosefork(t_philo *p, int forkplace)
{
	pthread_mutex_lock(&p->table->mutexfork[forkplace]);
	if (p->table->tabfork[forkplace] && ft_atoi(p->argv[1]) > 1)
	{
		p->table->tabfork[forkplace] = 0;
		printf("%d %d has taken a fork\n", gett(p->table->t), p->class);
		p->fork++;
	}
	pthread_mutex_unlock(&p->table->mutexfork[forkplace]);
}

int	gett(int start)
{
	int				tn;
	struct timeval	now;

	gettimeofday(&now, NULL);
	tn = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (tn - start);
}

int	eating(t_philo *philo)
{
	struct timeval	start;

	pthread_mutex_unlock(&philo->table->mutex);
	if (!philo->table->isdead)
		return (philodying(philo));
	printf("%d %d is eating\n", gett(philo->table->t), philo->class);
	gettimeofday(&start, NULL);
	philo->tstart = start.tv_sec * 1000 + start.tv_usec / 1000;
	while (gett(philo->tstart) < ft_atoi(philo->argv[3]))
	{
		if (!philo->table->isdead)
			return (philodying(philo));
		usleep(100);
	}
	return (1);
}

int	sleepthink(t_philo *philo, int rightfork)
{
	struct timeval	start;

	if (!philo->table->isdead)
		return (philodying(philo));
	philo->table->tabfork[rightfork - 1] = 1;
	philo->table->tabfork[philo->class - 1] = 1;
	philo->fork = 0;
	printf("%d %d is sleeping\n", gett(philo->table->t), philo->class);
	gettimeofday(&start, NULL);
	philo->tstart = start.tv_sec * 1000 + start.tv_usec / 1000;
	while (gett(philo->tstart) < ft_atoi(philo->argv[4]))
	{
		if (!philo->table->isdead)
			return (philodying(philo));
		// ordereating(philo);
		usleep(100);
	}
	if (!philo->table->isdead)
		return (philodying(philo));
	// philo->table->caneat[philo->class - 1] = 1;
	printf("%d %d is thinking\n", gett(philo->table->t), philo->class);
	return (1);
}

/*
1 800 200 200 mourir
5 800 200 200 pas mourir
5 800 200 200 7 pas mourir
4 410 200 200 pas mourir
4 310 200 100 mourir
2 -> aleatoire pas mourir/mourir
*/
