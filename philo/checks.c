/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:55:24 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/18 12:56:41 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkings(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->finished);
	if (philo->prog->finish)
	{
		pthread_mutex_unlock(&philo->prog->eat_lock);
		pthread_mutex_unlock(&philo->prog->finished);
		return (1);
	}
	pthread_mutex_unlock(&philo->prog->finished);
	return (0);
}

int	checks(t_prog *prog)
{
	int	i;

	i = 0;
	check_hunger(prog);
	while (i < prog->numberofphilos)
	{
		if (pthread_detach(prog->philo[i++].thread) != 0)
		{
			ft_putstr_fd("Error Couldn't detach threads\n", 2);
			return (0);
		}
	}
	return (0);
}

int	checks_scd(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->finished);
	pthread_mutex_lock(&philo->prog->all_aate);
	pthread_mutex_lock(&philo->prog->died);
	if ((philo->should_die && philo->prog->finish) || philo->prog->all_ate)
		return (1);
	pthread_mutex_unlock(&philo->prog->died);
	pthread_mutex_unlock(&philo->prog->finished);
	pthread_mutex_unlock(&philo->prog->all_aate);
	return (0);
}

void	ft_usleep(int nb)
{
	long long	time;

	time = get_time();
	while (get_time() - time < nb)
		usleep(100);
}
