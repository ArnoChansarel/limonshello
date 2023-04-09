/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 17:57:19 by achansar         ###   ########.fr       */
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
	while (1)
	{
		data.line = readline("LimonShello $> ");
		if (!data.line)
			exit(g_exit_value); // to update avec la globale
		if (parser(data.line, &data.lst, &data.pipes, data.env))
			continue ;
		ft_printparse(data.lst);
		init_process(&data);
		executor(data.process, data.lst, data.pipes, envp);
		add_history(data.line);
		ft_free_all(&data);
	}
	return (0);
}
