/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:02:59 by educastro         #+#    #+#             */
/*   Updated: 2024/10/22 18:42:35 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_data;
typedef struct t_philo;

enum e_bool
{
	FALSE,
	TRUE
};

// structs
typedef struct s_data
{
	int				n_philo;
	int				n_philo_eat;
	int				n_eat;
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	long int		t_start;
	enum e_bool		stop;
	t_philo			philos[PTHREAD_THREAD_MAX];
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_dead;
}				t_data;

typedef struct s_philo
{
	int				n;
	int				eat_count;
	long int		t_last_eat;
	pthread_t		thread;
	t_data			*data;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	fork_left;
}				t_philo;

// init.c


// exit.c
void	free_all(t_data *data);


#endif