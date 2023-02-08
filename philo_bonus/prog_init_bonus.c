/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:54:45 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/08 13:36:52 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_prog	*prog_init(t_prog *prog, char **av, int ac)
{
	prog->numberofphilos = atoi(av[1]);
	prog->timetodie = atoi(av[2]);
	prog->timetoeat = atoi(av[3]);
	prog->timetosleep = atoi(av[4]);
	prog->all_ate = 0;
	prog->finish = 0;
	if (ac == 6)
		prog->numberofeat = atoi(av[5]);
	else
		prog->numberofeat = -1;
	prog->philo = malloc(sizeof(t_philo) * prog->numberofphilos);
	if (!prog->philo)
		return (NULL);
	return (prog);
}
