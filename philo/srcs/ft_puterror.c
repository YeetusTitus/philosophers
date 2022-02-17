/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:00:17 by jforner           #+#    #+#             */
/*   Updated: 2022/02/17 17:54:16 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

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
	return (0);
}
