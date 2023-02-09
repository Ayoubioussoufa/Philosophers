/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_philos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:58:10 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/09 13:03:36 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		if ((philo->lastmeal + philo->prog->timetodie) < get_time())
		{
			print_msg(philo, "died");
			philo->prog->finish++;
			exit (1);
		}
		usleep(1000);
	}
	return (NULL);
}

void	philosopher(t_philo *philo)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, check_death, philo);
	while (!philo->prog->finish)
	{
		grab_fork(philo);
		// if (philo->prog->numberofphilos == 1)
		// 	break ;
		grab_fork(philo);
		eating(philo);
		put_fork(philo);
		sleep_think(philo);
	}
	pthread_join(monitor, NULL);
}

void	init_philo(t_philo *philo, t_prog *prog, int i)
{
	philo[i].id = i;
	philo[i].prog = prog;
	philo[i].lastmeal = prog->creation_time;
	philo[i].should_die = 0;
	philo[i].ate = 0;
}

int	creation_philos(t_prog *prog)
{
	int			i;
	pid_t		pid;
	t_philo		*philo;

	i = 0;
	prog->creation_time = get_time();
	philo = malloc(sizeof(t_philo) * prog->numberofphilos);
	while (i < prog->numberofphilos)
	{
		init_philo(philo, prog, i);
		pid = fork();
		if (pid == 0)
			philosopher(&philo[i]);
		else
			prog->id_table[i] = pid;
		i++;
		usleep(100);
	}
	return (0);
}
