/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:51:47 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/26 11:51:47 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct timeval	t_time;
typedef struct s_prog	t_prog;

typedef struct s_philo
{
	int			id;
	int			ate;
	int			should_die;
	long long	lastmeal;
	t_prog		*prog;
	pthread_t	thread;
}	t_philo;

typedef struct s_prog
{
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				numberofphilos;
	int				numberofeat;
	int				finish;
	int				all_ate;
	long long		creation_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finished;
	pthread_mutex_t	finish_lock;
	pthread_mutex_t	all_aate;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	died;
	int				test;
}	t_prog;

//utils
void		ft_usleep(int nb);
void		ft_putstr_fd(char *str, int fd);
void		ft_putchar_fd(char c, int fd);

//prog init
t_prog		*prog_init(t_prog *prog, char **av, int ac);

//threads creation
int			creation_philos(t_prog *prog);

//mutex init and destroy
int			mutex_init(t_prog *prog);
int			mutex_destroy(t_prog *prog);

//get time
long long	get_time(void);
long long	current_time(t_philo *philo);
void		ft_usleep(int nb);

//forks
void		grab_fork(t_philo *philo, int f);
void		put_forks(t_philo *philo, int f1, int f2);

//eat sleep think
void		eating(t_philo *philo);
void		sleep_think(t_philo *philo);

//checks
void		*philosophers(void *arg);
void		*check_hunger(void *arg);
void		*check_death(void *arg);
void		join_free(t_prog *prog);
int			checks_scd(t_philo *philo);
int			checks(t_prog *prog);
int			checkings(t_philo *philo);

//msg
void		print_msg(t_philo *philo, char *msg);

#endif