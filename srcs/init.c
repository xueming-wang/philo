/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:51:15 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/30 19:09:37 by xuwang           ###   ########.fr       */
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
        philo->time_philo_must_eat = ft_atoi(av[4]);
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

long long get_time(t_philo *philo)
{
    struct timeval tv;

    long long		ms;
    if (gettimeofday(&tv, NULL) == -1)
		__exit__("Time error", philo, FAILURE);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

// pthread_mutex_init(); 创建锁头  
// pthread_create();  创建线程
// pthread_create();  
//  pthread_mutex_lock();  拿走叉子锁上锁头
//    
//     pthread_mutex_unlock();  放下叉子就是解锁
//     pthread_join(ptid1,NULL);  //阻挡线程结束 挂起进程
//     pthread_join(ptid2,NULL);  
//     pthread_mutex_destroy(&(cnt.lock)); 