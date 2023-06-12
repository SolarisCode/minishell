/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:12:23 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/09 21:12:24 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(void)
{
	char	cwd[1000];

	getcwd(cwd, 1000);
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
}