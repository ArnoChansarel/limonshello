/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:50:28 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/03 14:11:59 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	restore_prompt(int sig)
{
	(void) sig;
	g_exit_value = 130; // only way to update exit number as prototype cant be modified
	write(1, "\n", 1);
	rl_on_new_line(); // Tell the update routines that we have moved onto a new (empty) line, usually after ouputting a newline.
	rl_replace_line("", 0);
	rl_redisplay(); // Change what's displayed on the screen to reflect the current contents of rl_line_buffer.
}

static void	readline_new_line(int sig)
{
	(void) sig;
	write(1, "\n", 1);
	rl_on_new_line();
}

static void	user_input_ctrl_c(int sig)
{
	(void) sig;
	exit(130);
}

static void	user_input_backslash(int sig)
{
	(void) sig;
	exit(131);
}

void	sig_handler(int input)
{
	signal(SIGQUIT, SIG_IGN);
	if (input == 0)
		signal(SIGINT, &restore_prompt);
	else if (input == 1)
	{
		signal(SIGINT, &readline_new_line);
		signal(SIGQUIT, &readline_new_line);
	}
	else if (input == 2)
	{
		signal(SIGINT, &user_input_ctrl_c);
		signal(SIGQUIT, &user_input_backslash);
	}
	else if (input == 3)
		signal(SIGINT, &user_input_ctrl_c);
	else
		signal(SIGINT, &readline_new_line);
}
