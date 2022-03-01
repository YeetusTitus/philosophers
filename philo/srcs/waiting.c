/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:27:03 by jforner           #+#    #+#             */
/*   Updated: 2022/03/01 12:16:07 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	philodying(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dying);
	if (!philo->table->isdead)
		return (0);
	printf("%d %d died\n", gett(philo->table->t), philo->class);
	philo->table->isdead = 0;
	return (0);
}

int	gotoeat(int *caneat, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (caneat[i])
			return (1);
	return (0);
}

void	ordereating(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&philo->table->mutex);
	if (philo->table->peer
		&& !gotoeat(philo->table->caneat, ft_atoi(philo->argv[1])))
	{
		philo->table->peer = 0;
		while (++i < ft_atoi(philo->argv[1]))
			if (i % 2 == 1)
				philo->table->caneat[i] = 1;
	}
	if (!philo->table->peer
		&& !gotoeat(philo->table->caneat, ft_atoi(philo->argv[1])))
	{
		philo->table->peer = 1;
		while (++i < ft_atoi(philo->argv[1]))
			if (i % 2 == 0)
				philo->table->caneat[i] = 1;
	}
	pthread_mutex_unlock(&philo->table->mutex);
}

int	takeforks(t_philo *p, int rightfork)
{
	pthread_mutex_lock(&p->table->mutex);
	if (((!p->table->peer && !(p->class % 2))
			|| (p->table->peer && (p->class % 2)))
		&& p->table->caneat[p->class - 1])
	{
		choosefork(p, rightfork - 1);
		choosefork(p, p->class - 1);
		if (p->fork == 2)
		{
			p->table->caneat[p->class - 1] = 0;
			return (1);
		}
	}
	pthread_mutex_unlock(&p->table->mutex);
	return (0);
}

int	waiting(t_philo *p, int rightfork, int tstart)
{
	while (gett(tstart) < ft_atoi(p->argv[2]))
	{
		if (!p->table->isdead
			|| gett(p->tdeath) >= ft_atoi(p->argv[2]))
			return (philodying(p));
		if (takeforks(p, rightfork))
			return (1);
		ordereating(p);
		usleep(100);
	}
	return (philodying(p));
}
