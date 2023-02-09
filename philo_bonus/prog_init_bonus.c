/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:54:45 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/09 12:46:47 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	prog_init(t_prog *prog, char **av, int ac)
{
	prog->numberofphilos = atoi(av[1]);
	// printf("%d\n", prog->numberofphilos);
	prog->timetodie = atoi(av[2]);
	prog->timetoeat = atoi(av[3]);
	prog->timetosleep = atoi(av[4]);
	prog->all_ate = 0;
	prog->finish = 0;
	if (ac == 6)
		prog->numberofeat = atoi(av[5]);
	else
		prog->numberofeat = -1;
	prog->id_table = malloc(sizeof(int) * prog->numberofphilos);
	if (!prog->id_table)
		puterr("Allocation Error!\n");
}
