/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:04:13 by melkholy          #+#    #+#             */
/*   Updated: 2023/05/19 16:41:35 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Used to ignore the Control + C signal
 and istead just displayed a new prompt on a new line */
void	ft_quit_ignore(int sig)
{
	write (1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	return ((void)sig);
}

/* Used to save the original terminal attributes,
 so I can modify them to disable ^C from appreaing on the screen */
int	ft_set_terminal(void)
{
	struct termios	attr_new;
	int				error;

	error = 0;
	error = tcgetattr(STDIN_FILENO, &g_term_attr.save_attr);
	attr_new = g_term_attr.save_attr;
	attr_new.c_lflag &= ~ECHOCTL;
	error = tcsetattr(STDIN_FILENO, TCSANOW, &attr_new);
	return (error);
}
