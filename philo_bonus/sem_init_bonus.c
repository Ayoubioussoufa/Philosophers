/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:37:22 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/08 14:11:34 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sem_init(t_prog *prog)
{
	prog->sem = malloc(sizeof(sem_t));
	prog->sem = sem_open(/**/, O_CREAT | O_EXCL, 0644);
	if (prog->sem) //SEM_FAILED = 1
		return ;//error function !!
}