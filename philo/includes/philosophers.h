/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:02:59 by educastro         #+#    #+#             */
/*   Updated: 2024/10/25 16:00:19 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

// enums
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
	t_philo			*philos;
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

// philosophers.c
enum e_bool	philo_handler(t_data *data);

// init.c
enum e_bool	init_data(t_data *data, char **argv);

// exit.c
void		free_all(t_data *data);

// utils.c
enum e_bool	is_dead(t_philo *philo, enum e_bool set_dead);
long int	timestamp(void);
void		msleep(int ms);
void		print(t_philo *philo, char *str);
enum e_bool	philo_init(t_data *data, int i);

// lib
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);

#endif