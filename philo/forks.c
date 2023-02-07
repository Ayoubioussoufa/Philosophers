/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:57:15 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/30 14:57:15 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork(t_philo *philo, int f)
{
	pthread_mutex_lock(&philo->prog->forks[f]);
	print_msg(philo, "has taken a fork");
}

void	put_forks(t_philo *philo, int f1, int f2)
{
	pthread_mutex_unlock(&philo->prog->forks[f1]);
	pthread_mutex_unlock(&philo->prog->forks[f2]);
}
