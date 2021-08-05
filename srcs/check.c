/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:22:40 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/05 19:17:08 by xuwang           ###   ########.fr       */
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
        if (each_philo[i].last_meal != 0 && (get_time() - each_philo[i].last_meal > each_philo->info_utils->time_to_die))
        {
            philo_state(each_philo, 4);
            pthread_mutex_unlock(&each_philo->info_utils->mutex);
            return (0);
            break ;
            
            
        }
        pthread_mutex_unlock(&each_philo->info_utils->mutex);
        i++;
    }
    return (1); //表示间隔时间是够的
}

int check_enough_eat(t_each_philo *each_philo, t_philo *info)  //check 吃饭次数足够就停止运行
{
    if (info->nbr_philo_must_eat == 0)
        return (0);     
    if (each_philo->nbr_eat == info->nbr_philo_must_eat)
    {
        info->nbr_phile_are_eat++;    
    }
    // int i;
    // int count;
    
    // if (info->nbr_philo_must_eat == 0)
    //     return (0);        
    // i = 0;
    // count = 0;
    
    // printf("\n");
    // while (i < info->nbr_philo)
    // {
    //     printf("[%d] : n [%d]\n", each_philo->id, each_philo->nbr_eat);
    //      pthread_mutex_lock(&info->mutex);
    //     //  if (each_philo[i].nbr_eat >= info->nbr_philo_must_eat)
    //     if ((each_philo + i)->nbr_eat >= info->nbr_philo_must_eat)
    //      {
    //         pthread_mutex_unlock(&info->mutex);
    //         count++;
    //      }
    //     else
    //     {
    //         pthread_mutex_unlock(&info->mutex);
    //     }
    //      i++;
    // }
    // printf("\n");
//    return (0);
    return (info->nbr_phile_are_eat == info->nbr_philo);  //返回1 表示吃够次数了  停止   //返回0 表示没有吃够
}