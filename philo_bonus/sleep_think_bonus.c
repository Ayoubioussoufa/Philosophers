/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:59:11 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/09 09:59:11 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleep_think(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->info->time_to_sleep * 1000);
	print_msg(philo, "is thinking");
}
