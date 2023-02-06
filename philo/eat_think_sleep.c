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
	usleep(philo->prog->timetoeat * 1000);
	philo->lastmeal = get_time();
	philo->ate++;
	if (philo->ate == philo->prog->numberofeat)
		philo->prog->all_ate++;
}

void	sleep_think(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->prog->timetosleep * 1000);
	print_msg(philo, "is thinking");
}
