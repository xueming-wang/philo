/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:22:40 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/04 19:26:35 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_died(t_each_philo *each_philo)  //check 吃饭间隔时间够不过
{
    int i;
    
    i = 0;
    while (i < each_philo->info_utils->nbr_philo)
    {
        pthread_mutex_lock(&each_philo->info_utils->mutex);
        if (each_philo[i].last_meal != 0 && get_time() - each_philo[i].last_meal > philo->time_to_die)
        {
            printf("timac %lld\n", get_time());
            printf("lm %lld\n", each_philo[i].last_meal);
            printf("timac-lm %lld\n", get_time() - each_philo[i].last_meal);
            printf("die %d\n", philo->time_to_die);
            philo_state(philo, each_philo, 4);
            pthread_mutex_unlock(&philo->mutex);
            return (1);
        }
        else
            pthread_mutex_unlock(&philo->mutex);
        i++;
    }
    return (0);  //表示间隔时间是够的
}

int check_enough_eat(t_each_philo *each_philo)  //check 吃饭次数足够就停止运行
{
    int i;
    int count;
    
    if (philo->nbr_philo_must_eat == 0)
        return (0);        
    i = 0;
    count = 0;
    while (i < philo->nbr_philo && each_philo[i].nbr_eat >= philo->nbr_philo_must_eat)
    {
            pthread_mutex_unlock(&philo->mutex);
            i++;
    }
    pthread_mutex_unlock(&philo->mutex);
    return (count == philo->nbr_philo);
     
    
}