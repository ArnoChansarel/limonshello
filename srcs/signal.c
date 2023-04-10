/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:50:28 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/10 18:09:00 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	restore_prompt(int sig)
{
	(void) sig;
	g_exit_value = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
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
