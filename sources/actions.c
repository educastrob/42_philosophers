/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:43:59 by educastro         #+#    #+#             */
/*   Updated: 2024/06/22 14:48:10 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philo *philo)
{
	printf("is thinking");
}

void	dream(t_philo *philo)
{
	printf("is sleeping");
	usleep(philo->time_to_sleep);
}

