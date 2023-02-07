/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_philos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:58:10 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/07 11:00:48 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	creation_philos(t_prog *prog)
{
	int			i;
	pthread_t	monitor;
    pid_t       pid;

	i = 0;
	prog->creation_time = get_time();
	while (i < prog->numberofphilos)
	{
		pid = fork();
		if (pid == 0)
		{
			prog->philo[i].id = i;
			prog->philo[i].prog = prog;
			prog->philo[i].lastmeal = prog->creation_time;
			prog->philo[i].should_die = 0;
			prog->philo[i].ate = 0;
			pthread_create(&prog->philo[i].thread, NULL,
				/*philosophers*/, &prog->philo[i]);
			pthread_create(&monitor, NULL, /*check_death*/, &prog->philo[i]);
			pthread_detach(monitor);
		}
		else
		{
			i++;
			usleep(100);
		}
	}
	if (prog->numberofeat >= 0)
	{
		pthread_create(&monitor, NULL, /*check_hunger*/, prog);
		pthread_detach(monitor);
	}
	return (0);
}
