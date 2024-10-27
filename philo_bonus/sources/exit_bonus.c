/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:19 by educastro         #+#    #+#             */
/*   Updated: 2024/10/27 18:13:41 by edcastro         ###   ########.fr       */
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
