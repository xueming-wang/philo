/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:22:40 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/08 16:47:31 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_enough_eat(t_each_philo *each_philo, t_philo **info_utils)  //check 吃饭次数足够就停止运行
{
    if ((*info_utils)->nbr_philo_must_eat == 0)
        return (0);     
    if (each_philo->nbr_eat ==(*info_utils)->nbr_philo_must_eat)
       (*info_utils)->nbr_phile_are_eat++;    
    if ((*info_utils)->nbr_phile_are_eat ==(*info_utils)->nbr_philo)
    {
        each_philo->info_utils->check_died = 1;
        return (1);
    }
    return (0);
}


int check_died(t_each_philo *each_philo, t_philo **info_utils)  //check 吃饭间隔时间够不过
{
    int i;
    i = 0;
    
    // pthread_mutex_lock(&(*info_utils)->mutex);
    // if (each_philo->info_utils->check_died == 1)
    // {
    //     pthread_mutex_unlock(&(*info_utils)->mutex);
    //     return (0);
    // }
    // pthread_mutex_unlock(&(*info_utils)->mutex);
    
    // pthread_mutex_lock(&(*info_utils)->mutex);
    // if  (each_philo->last_meal != 0 && (get_time() - each_philo->last_meal > (*info_utils)->time_to_die))
    // {
    //     philo_state(each_philo, 4);
    //     (*info_utils)->check_died = 1;
    //     pthread_mutex_unlock(&(*info_utils)->mutex);
    //     return (0);
    // }
    // pthread_mutex_unlock(&(*info_utils)->mutex);
    // return (1);
    
    while (i < (*info_utils)->nbr_philo)
    {
       
        pthread_mutex_lock(&(*info_utils)->mutex);
        if  ((each_philo->last_meal != 0) && ((get_time() - each_philo->last_meal) > (*info_utils)->time_to_die))
        {
            philo_state(each_philo, 4);
            (*info_utils)->check_died = 1;
            pthread_mutex_unlock(&(*info_utils)->mutex);
            return (0);
        }
        i++;
        pthread_mutex_unlock(&(*info_utils)->mutex);
    }
    return (1);
}

