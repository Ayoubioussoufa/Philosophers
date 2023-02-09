/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_philos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:58:10 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/09 10:40:48 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		if ((philo->last_meal + philo->prog->time_to_die) < ft_get_time())
		{
			print_msg(philo, "died");
			exit (FT_FAILURE);
		}
		usleep(1000);
	}
	return (NULL);
}

void	philosopher(t_philo *philo)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, check_death, philo);
	while (!philo->should_die && !philo->prog->finish)
	{
		if (philo->prog->numberofphilos == 1)
			break ;
		grab_fork(philo);
		grab_fork(philo);
		eating(philo);
		put_forks(philo);
		sleep_think(philo);
	}
	pthread_join(monitor, NULL);
}

void	init_philo(t_prog *prog, int i)
{
	prog->philo[i].id = i;
	prog->philo[i].prog = prog;
	prog->philo[i].lastmeal = prog->creation_time;
	prog->philo[i].should_die = 0;
	prog->philo[i].ate = 0;
}

int	creation_philos(t_prog *prog)
{
	int			i;
	pid_t		pid;

	i = 0;
	prog->creation_time = get_time();
	while (i < prog->numberofphilos)
	{
		pid = fork();
		if (pid == 0)
		{
			init_philo(prog, i);
			prog->philo[i].id = i;
			philosopher(prog->philo); 
		}
		else
			prog->id_table[i] = pid;
		i++;
		usleep(100);
	}
	return (0);
}
