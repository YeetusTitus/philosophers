/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:13:56 by jforner           #+#    #+#             */
/*   Updated: 2022/02/26 17:13:10 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	*core(void *arg)
{
	t_philo			*philo;
	int				rightfork;
	struct timeval	start;

	philo = (t_philo *)arg;
	if (philo->class == 1)
		rightfork = ft_atoi(philo->argv[1]);
	else
		rightfork = philo->class - 1;
	gettimeofday(&start, NULL);
	philo->tstart = start.tv_sec * 1000 + start.tv_usec / 1000;
	while (philo->turn == -1 || philo->turn-- > 0)
	{
		if (!waiting(philo, rightfork, philo->tstart)
			|| !eating(philo) || !sleepthink(philo, rightfork))
		{
			pthread_mutex_unlock(&philo->table->dying);
			break ;
		}
	}
	return (NULL);
}
