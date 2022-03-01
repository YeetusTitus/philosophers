/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:18:26 by jforner           #+#    #+#             */
/*   Updated: 2022/03/01 12:22:55 by jforner          ###   ########.fr       */
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
	int				peer;
	int				t;
	pthread_mutex_t	*mutexfork;
	pthread_mutex_t	mutex;
	pthread_mutex_t	dying;
}	t_table;

typedef struct s_philo
{
	int				class;
	int				turn;
	int				fork;
	char			**argv;
	int				tstart;
	int				tdeath;
	t_table			*table;
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

//waiting
int				waiting(t_philo *philo, int rightfork, int tstart);
int				gotoeat(int *caneat, int len);
void			ordereating(t_philo *philo);
int				philodying(t_philo *philo);
int				takeforks(t_philo *p, int rightfork);

//action
int				gett(int start);
int				eating(t_philo *philo);
int				sleepthink(t_philo *philo, int rightfork);
void			choosefork(t_philo *p, int forkplace);
#endif
