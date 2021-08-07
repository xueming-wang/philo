/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:22:40 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/07 16:50:39 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_died(t_each_philo *each_philo)  //check 吃饭间隔时间够不过
{
    pthread_mutex_lock(&each_philo->info_utils->mutex);
    if (each_philo->info_utils->check_died == 1)
    {
        pthread_mutex_unlock(&each_philo->info_utils->mutex);
        return (0);
    }
    pthread_mutex_unlock(&each_philo->info_utils->mutex);
    // pthread_mutex_lock(&each_philo->info_utils->mutex);
    if (each_philo->last_meal != 0 && (get_time() - each_philo->last_meal > each_philo->info_utils->time_to_die))
    {
        philo_state(each_philo, 4);
        each_philo->info_utils->check_died = 1;
        // pthread_mutex_unlock(&each_philo->info_utils->mutex);
        return (0);
    }
    // pthread_mutex_unlock(&each_philo->info_utils->mutex);
    return (1);
}

int check_enough_eat(t_each_philo *each_philo, t_philo *info)  //check 吃饭次数足够就停止运行
{
    if (info->nbr_philo_must_eat == 0)
        return (0);     
    if (each_philo->nbr_eat == info->nbr_philo_must_eat)
        info->nbr_phile_are_eat++;    
    if (info->nbr_phile_are_eat == info->nbr_philo)
    {
        each_philo->info_utils->check_died = 1;
        return (1);
    }
    return (0);
}