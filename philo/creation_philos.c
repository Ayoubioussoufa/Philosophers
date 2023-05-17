/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:31:26 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/30 14:31:26 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_hunger(void *arg)
{
	t_prog	*prog;

	prog = (t_prog *)arg;
	while (!prog->finish)
	{
		pthread_mutex_lock(&prog->all_aate);
		if (prog->all_ate > 0)
		{
			pthread_mutex_lock(&prog->finished);
			prog->finish = 1;
			pthread_mutex_unlock(&prog->finished);
		}
		pthread_mutex_unlock(&prog->all_aate);
	}
	return (NULL);
}

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->prog->finish)
			break ;
		pthread_mutex_lock(&philo->prog->eat_lock);
		if ((philo->lastmeal + philo->prog->timetodie) < get_time())
		{
			print_msg(philo, "died");
			pthread_mutex_lock(&philo->prog->died);
			philo->should_die = 1;
			pthread_mutex_unlock(&philo->prog->died);
			pthread_mutex_lock(&philo->prog->finished);
			philo->prog->finish = 1;
			pthread_mutex_unlock(&philo->prog->finished);
		}
		pthread_mutex_unlock(&philo->prog->eat_lock);
	}
	pthread_mutex_unlock(&philo->prog->finished);
	return (NULL);
}

void	ft_usleep(int nb)
{
	long long time;

	time = get_time();
	while (get_time() - time < nb)
		usleep(50);
}

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	while (1)
	{
		right_fork = philo->id;
		left_fork = (philo->id + 1) % philo->prog->numberofphilos;
		if (philo->prog->numberofphilos == 1)
			break ;
		grab_fork(philo, right_fork);
		grab_fork(philo, left_fork);
		eating(philo);
		put_forks(philo, right_fork, left_fork);
		sleep_think(philo);
		pthread_mutex_lock(&philo->prog->died);
		pthread_mutex_lock(&philo->prog->finished);
		pthread_mutex_lock(&philo->prog->all_aate);
		if ((philo->should_die && philo->prog->finish) || philo->prog->all_ate)
			break ;
		pthread_mutex_unlock(&philo->prog->died);
		pthread_mutex_unlock(&philo->prog->finished);
		pthread_mutex_unlock(&philo->prog->all_aate);
	}
	pthread_mutex_unlock(&philo->prog->died);
	pthread_mutex_unlock(&philo->prog->finished);
	pthread_mutex_unlock(&philo->prog->all_aate);
	return (NULL);
}

int	creation_philos(t_prog *prog)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	prog->creation_time = get_time();
	while (i < prog->numberofphilos)
	{
		prog->philo[i].id = i;
		prog->philo[i].prog = prog;
		prog->philo[i].lastmeal = prog->creation_time;
		prog->philo[i].should_die = 0;
		prog->philo[i].ate = 0;
		pthread_create(&prog->philo[i].thread, NULL,
			philosophers, &prog->philo[i]);
		pthread_create(&monitor, NULL, check_death, &prog->philo[i]);
		pthread_detach(monitor);
		usleep(100);
		i++;
	}
	if (prog->numberofeat >= 0)
	{
		pthread_create(&monitor, NULL, check_hunger, prog);
		pthread_detach(monitor);
	}
	return (0);
}
