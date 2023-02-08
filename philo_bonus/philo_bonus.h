/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:55:10 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/08 15:56:31 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/signal.h>
# include <unistd.h>
#include <semaphore.h>

typedef struct timeval	t_time;
typedef struct s_prog	t_prog;

typedef struct s_philo
{
	int			id;
	int			ate;
	int			should_die;
	long long	lastmeal;
	t_prog		*prog;
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
	sem_t			*sem;
}	t_prog;

//init
t_prog	*prog_init(t_prog *prog, char **av, int ac);
void	init_philo(t_prog *prog, int i);
void    ft_sem_init(t_prog *prog);

//get time
long long	get_time(void);
long long	current_time(t_philo *philo);

//philos
int		creation_philos(t_prog *prog);
void	philosopher(t_philo *philo);

//print msg
void    ft_print_msg(t_philo *philo, char *msg);

#endif