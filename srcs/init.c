/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:51:15 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/01 19:46:49 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int init_value(t_philo *philo,char **av)
{
    int i;
    
    philo->start_time = 0;
    philo->nbr_philo = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_sleep = ft_atoi(av[3]);
    if (av[4])
        philo->nbr_philo_must_eat = ft_atoi(av[4]);
    i = 1;
    while (i < philo->nbr_philo)
    {
        philo->each_philo[i].id = i;
        ++i;
    }
    philo->each_philo = ft_calloc(sizeof(t_each_philo), philo->nbr_philo);
    if (!philo->each_philo)
        return (FAILURE);
    philo->fork = ft_calloc(sizeof(pthread_mutex_t), philo->nbr_philo);  //互斥锁的数量
    if (!philo->fork)
        return (FAILURE);
    return(SUCCESS);
}

long long get_time()
{
    struct timeval tv;

    long long		ms;
    if (gettimeofday(&tv, NULL) == -1)
		return (FAILURE);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

void  philo_state(t_philo *philo, int i, int state)
{   
    const char *states[] = {"is eating", "has taken a fork", 
                            "is sleeping", "is thinking", "died"};
    printf("[%lld] philosopher[%d] %s\n", get_time()-(philo->start_time), philo->each_philo[i].id, states[state]);
    
}

