/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:40:19 by jforner           #+#    #+#             */
/*   Updated: 2022/02/22 17:58:07 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher.h"

int	main(int argc, char **argv)
{
	char		error;
	t_philo		*philo;
	pthread_t	*th;
	int			i;

	if (!parse(argc, argv, &error))
		return (ft_puterror(&error));
	philo = (t_philo *)malloc((ft_atoi(argv[1])) * sizeof(t_philo));
	th = (pthread_t *)malloc((ft_atoi(argv[1])) * sizeof(pthread_t));
	if (!th || !philo || !createphilos(philo, &error, argv))
		return (allocerror(philo, th, &error));
	i = -1;
	while (++i < ft_atoi(argv[1]))
		pthread_create(&th[i], NULL, &core, &philo[i]);
	i = -1;
	while (++i < ft_atoi(argv[1]))
		pthread_join(th[i], NULL);
	freedom(th, &philo);
	// system("leaks philo");
	return (0);
}
