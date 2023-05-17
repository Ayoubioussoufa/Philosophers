/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:58:48 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/30 14:58:48 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	print_msg(philo, "is eating");
	pthread_mutex_lock(&philo->prog->eat_lock);
	philo->lastmeal = get_time();
	pthread_mutex_unlock(&philo->prog->eat_lock);
	pthread_mutex_lock(&philo->prog->all_aate);
	philo->ate++;
	if (philo->ate == philo->prog->numberofeat)
		philo->prog->all_ate++;
	ft_usleep(philo->prog->timetoeat);
	pthread_mutex_unlock(&philo->prog->all_aate);
}

void	sleep_think(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	ft_usleep(philo->prog->timetosleep);
	print_msg(philo, "is thinking");
}
