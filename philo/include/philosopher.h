/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:18:26 by jforner           #+#    #+#             */
/*   Updated: 2022/02/22 18:03:38 by jforner          ###   ########.fr       */
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

typedef struct s_table
{
	int				*tabfork;
	int				*caneat;
	int				isdead;
	pthread_mutex_t	mutex;
}	t_table;

typedef struct s_philo
{
	int		class;
	int		turn;
	int		fork;
	char	**argv;
	t_table	*table;
}	t_philo;

//parse
int				parse(int argc, char **argv, char *error);
int				verif_isdigit(int argc, char **argv, char *error);
int				verif_int(char **argv, int argc, char *error);
unsigned long	ft_uatol(char *str);
int				ft_atoi(char *str);

//utils
size_t			ft_strlen(char *str);
int				digitcount(char *str);
int				tablen(char **tab);
int				freedom(pthread_t *th, t_philo **philo);

//puterror
int				ft_puterror(char *error);
int				allocerror(t_philo *philo, pthread_t *th, char *error);

//core
void			*core(void *philo);
int				createphilos2(t_philo *philo, char **argv, t_table **table);
int				createphilos(t_philo *philo, char *error, char **argv);

#endif
