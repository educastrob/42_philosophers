/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:38:05 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/25 16:02:36 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->philos[i].m_eat);
		pthread_mutex_destroy(&data->philos[i].fork_left);
		i++;
	}
	pthread_mutex_destroy(&data->m_print);
	pthread_mutex_destroy(&data->m_dead);
	free(data->philos);
}
