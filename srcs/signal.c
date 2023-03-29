/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:50:28 by ade-bast          #+#    #+#             */
/*   Updated: 2023/03/29 11:36:35 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	restore_prompt(int sig)
{
	(void) sig;
	write(1, "\n", 1);
	rl_on_new_line(); //  Tell the update routines that we have moved onto a new (empty) line, usually after ouputting a newline. 
	rl_replace_line("", 0);
	rl_redisplay(); // Change what's displayed on the screen to reflect the current contents of rl_line_buffer. 
}

static void	prompt_nl(int sig)
{
	(void) sig;
	write(1, "\n", 1);
	rl_on_new_line();
}

static void	ctrl_c(int sig)
{
	(void) sig;
	exit(130);
}

static void	backslash(int sig)
{
	(void) sig;
	exit(131);
}

void	sig_handler(int status)
{
	signal(SIGQUIT, SIG_IGN);
	if (status == 0)
	{
		signal(SIGINT, &restore_prompt);
		signal(SIGINT, SIG_IGN);
	}
	else if (status == 1)
	{
		signal(SIGINT, &prompt_nl);
		signal(SIGQUIT, &prompt_nl);
	}
	else if (status == 2)
	{
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, &backslash);
	}
	else if (status == 3)
		signal(SIGINT, &ctrl_c);
	else
		signal(SIGINT, &prompt_nl);
}
