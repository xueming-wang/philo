/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:08:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/04 19:26:47 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void  philo_eat(t_philo *philo,  t_each_philo *each_philo)
{
    if (each_philo->id % 2 == 0)
    {
        if (philo->nbr_philo != 1)
        {
            pthread_mutex_lock(&philo->fork[each_philo->right]); //拿起左手筷子  
            philo_state(philo, each_philo, 1);  //打印拿起筷子
        }
        pthread_mutex_lock(&philo->fork[each_philo->left]); //拿起右手筷子
        philo_state(philo, each_philo, 1);  //打印拿起筷子
    }
        
    else
    {
        pthread_mutex_lock(&philo->fork[each_philo->left]); //拿起右手筷子
        philo_state(philo, each_philo, 1);  //打印拿起筷子
        pthread_mutex_lock(&philo->fork[each_philo->right]); //拿起左手筷子  
        philo_state(philo, each_philo, 1);  //打印拿起筷子
    }
    
    
}

static void sleeping(t_philo* philo, t_each_philo *each_philo)
{
    philo_state(philo, each_philo, 2);//打印睡觉状态
    ft_usleep(philo->time_to_sleep);// 睡觉
}

void ft_philo(t_each_philo *each_philo)
{
    
        philo_eat(philo, each_philo);  //拿起筷子
        philo_state(philo, each_philo, 0); //打印状态
        each_philo->last_meal = get_time();  //取得最后一顿饭的时间
        ft_usleep(philo->time_to_eat);  //usleep吃饭时间
        each_philo->nbr_eat++;   //吃饭的顿数增加
        if (each_philo->id % 2 == 0)
        {
            pthread_mutex_unlock(&philo->fork[each_philo->left]); //放下筷子
            pthread_mutex_unlock(&philo->fork[each_philo->right]);//放下筷子
        }
        else
        {
            pthread_mutex_unlock(&philo->fork[each_philo->right]);//放下筷子
            pthread_mutex_unlock(&philo->fork[each_philo->left]); //放下筷子
        }
        

}


void  *do_philo(void *each_philo)
{
    
    // t_philo     *info_utils; //创建需要的通用的信息
    // t_each_philo *each_philo2;  //创建一个新的哲学家数组

    // each_philo2 = (t_each_philo*)each_philo; //把每个哲学家的信息放进新的哲学家数组
    // info_utils = each_philo2->info_utils;   // 把需要的信息 放进这个新的数组里

    while (!check_died(each_philo) && !check_enough_eat(each_philo))
    {
        ft_philo(info_utils, each_philo2);  //当前这个人用的所有信息
        philo_state(info_utils, each_philo2, 3);   //打印思考时间
        sleeping(info_utils, each_philo2);
   }
    return (0);
}