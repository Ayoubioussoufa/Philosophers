/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:25:11 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/30 14:25:11 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_prog *prog)
{
	int	i;
	
	i = 0;
    if (pthread_mutex_init(&prog->finish_lock, NULL) != 0)
	{
		ft_putstr_fd("Mutex init failed\n", 2);
		return (1);
	}
	while (i < prog->numberofphilos)
	{
		if (pthread_mutex_init(&prog->forks[i], NULL) != 0)
		{
			ft_putstr_fd("Mutex init failed\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
