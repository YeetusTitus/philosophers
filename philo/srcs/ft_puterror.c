/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:00:17 by jforner           #+#    #+#             */
/*   Updated: 2022/02/22 17:58:12 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	allocerror(t_philo *philo, pthread_t *th, char *error)
{
	freedom(th, &philo);
	*error = 'm';
	return (ft_puterror(error));
}

int	ft_puterror(char *error)
{
	if (*error != '0')
		printf("Error\n");
	if (*error == 'n')
		printf("The number of argumments is not valid !\n");
	if (*error == 'd')
		printf("The syntax of argumment(s) is not correct !\n");
	if (*error == 'i')
		printf("The argumment(s) is(are) not integer(s)\n");
	if (*error == 'm')
		printf("Couldn't allocated memory\n");
	if (*error == 'p')
		printf("The number of philosophers is not correct\n");
	// system("leaks philo");
	return (0);
}
