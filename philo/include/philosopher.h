/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:18:26 by jforner           #+#    #+#             */
/*   Updated: 2022/02/17 18:05:24 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

//parse
int				parse(int argc, char **argv, char *error);
int				verif_isdigit(int argc, char **argv, char *error);
int				verif_int(char **argv, int argc, char *error);
unsigned long	ft_uatol(char *str);

//utils
size_t			ft_strlen(char *str);
int				digitcount(char *str);

//puterror
int				ft_puterror(char *error);

#endif
