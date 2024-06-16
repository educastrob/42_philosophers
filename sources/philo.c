/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:03:04 by educastro         #+#    #+#             */
/*   Updated: 2024/06/16 05:04:39 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// macros
#define THREADS 5

pthread_t			thread[THREADS];
pthread_mutex_t		mutex;

void *func(void *arg)
{
	int i = 0;
	while (i < 3)
	{
		pthread_mutex_lock(&mutex);
		printf("%i\n", i);
		i++;
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
}

int	main(int ac, char **av)
{	
	pthread_create(&(thread[1]), NULL, func, NULL);
	pthread_create(&(thread[2]), NULL, func, NULL);
	pthread_create(&(thread[3]), NULL, func, NULL);
	pthread_create(&(thread[4]), NULL, func, NULL);
	pthread_create(&(thread[5]), NULL, func, NULL);

	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
	pthread_join(thread[4], NULL);
	pthread_join(thread[5], NULL);
}