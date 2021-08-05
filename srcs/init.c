/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:51:15 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/05 18:41:29 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *init_value(char **av)
{
    t_philo *philo;

    philo = ft_calloc (sizeof(t_philo), 1);
    if (!philo)
        return (NULL);
    philo->start_time = get_time();
    philo->nbr_philo = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (av[5] && ft_atoi(av[5]) > 0)
        philo->nbr_philo_must_eat = ft_atoi(av[5]);
    philo->fork = ft_calloc(sizeof(pthread_mutex_t), philo->nbr_philo);  //互斥锁的数量
    if (!philo->fork)
        return (NULL);
    return(philo);
}

t_each_philo *init_each_philo(int philo_nbr)
{
    t_each_philo *each_philo;
    int i;
   
    i = 0;
    each_philo = ft_calloc(sizeof(t_philo), philo_nbr);
    if (!each_philo)
        return (NULL);
    while (i < philo_nbr)
    {
        each_philo[i].id = i + 1;
        each_philo[i].left = i + 1;
        each_philo[i].right = (i + 1 + 1) % philo_nbr;
        each_philo[i].nbr_eat = 0;
        each_philo[i].last_meal = 0;
        
        i++;
    }
    return (each_philo);
}

long long get_time(void)
{
    struct timeval tv;

    long long		ms;
    if (gettimeofday(&tv, NULL) == -1)
		return (FAILURE);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

void  philo_state(t_each_philo *each_philo, int state)
{   
    const char *states[] = {"is eating", "has taken a fork", 
                            "is sleeping", "is thinking", "died"};
    printf("[%lld] philosopher[%d] %s\n", get_time() - (each_philo->info_utils->start_time), each_philo->id, states[state]);
}
void ft_usleep(long long ms)
{
	const long long start = get_time();
	while (get_time() - start < ms)
		usleep(MICRO_SECOND);
}

