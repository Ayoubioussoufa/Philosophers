/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:00:39 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/09 10:00:39 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eating(t_philo *philo)
{
	philo->lastmeal = get_time();
	print_msg(philo, "is eating");
	usleep(philo->prog->timetoeat * 1000);
}
