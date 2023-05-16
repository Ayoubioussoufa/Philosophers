/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:15:12 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/16 16:51:15 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->prog->finish_lock);
	if (!philo->prog->finish)
		printf("%lli ms| Philo %i %s\n", current_time(philo),
			philo->id + 1, msg);
	pthread_mutex_unlock(&philo->prog->finish_lock);
}
