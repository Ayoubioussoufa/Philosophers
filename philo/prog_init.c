/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:58:42 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/16 15:27:06 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_prog	*prog_init(t_prog *prog, char **av, int ac)
{
	prog->numberofphilos = atoi(av[1]);
	prog->timetodie = atoi(av[2]);
	prog->timetoeat = atoi(av[3]);
	prog->timetosleep = atoi(av[4]);
	prog->all_ate = 0;
	prog->finish = 0;
	prog->creation_time = 0;
	if (ac == 6)
		prog->numberofeat = atoi(av[5]);
	else
		prog->numberofeat = -1;
	prog->philo = malloc(sizeof(t_philo) * prog->numberofphilos);
	prog->forks = malloc(sizeof(pthread_mutex_t) * prog->numberofphilos);
	if (!prog->philo || !prog->forks)
		return (NULL);
	return (prog);
}
