/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:02:59 by educastro         #+#    #+#             */
/*   Updated: 2024/06/22 14:17:26 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// macros
# define PHILO_MAX 300

// estruturas

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	size_t		last_meal;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			num_of_philos;
}				t_philo;


// actions
void	think(t_philo philo);
void	dream(t_philo philo);


#endif