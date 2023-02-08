/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:55:49 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/08 15:57:59 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	grab_fork(t_philo *philo)
{
	sem_wait(philo->prog->sem);
	print_msg(philo, "has taken a fork");
}

void	put_fork(t_philo *philo)
{
	sem_post(philo->prog->sem);
	sem_post(philo->prog->sem);
}