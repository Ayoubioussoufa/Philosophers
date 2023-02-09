/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:37:22 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/09 10:37:51 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_sem_init(t_prog *prog)
{
	prog->fork = sem_open("semaphore", O_CREAT | O_EXCL, 0644, prog->numberofphilos);
	if (prog->fork == SEM_FAILED)
		puterr("Error initializing semaphore\n");
	return (0);
}