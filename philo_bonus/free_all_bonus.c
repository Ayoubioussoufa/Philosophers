/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:35:16 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/09 10:35:16 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free_all(t_prog *prog)
{
	int	ret;
	int	i;

	i = -1;
	while (++i < prog->numberofphilos)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = 0;
			while (i < prog->numberofphilos)
				kill(prog->id_table[i++], 15);
			break ;
		}
	}
	sem_close(prog->forks);
	free(prog->id_table);
	free(prog);
}
