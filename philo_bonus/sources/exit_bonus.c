/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:19 by educastro         #+#    #+#             */
/*   Updated: 2024/10/27 16:04:19 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	free_all(t_data *data)
{
	sem_close(data->sem_print);
	sem_close(data->sem_stop);
	sem_close(data->sem_eat);
	sem_close(data->sem_forks);
	sem_unlink("print");
	sem_unlink("stop");
	sem_unlink("eat");
	sem_unlink("forks");
	free(data->philos);
}