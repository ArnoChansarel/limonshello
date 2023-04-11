/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 14:50:25 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void) argv;
	if (argc != 1)
		return (1);
	sig_handler(0);
	init_data(&data, envp);
	print_head();
	g_exit_value = 0;
	while (1)
	{
		data.line = readline("LimonShello $> ");
		if (!data.line)
			exit(g_exit_value);
		if (parser(data.line, &data.lst, &data.pipes, data.env))
			continue ;
		init_process(&data);
		executor(data.process, data.lst, data.pipes, envp);
		if (ft_strlen(data.line))
			add_history(data.line);
		ft_free_all(&data);
	}
	return (0);
}
