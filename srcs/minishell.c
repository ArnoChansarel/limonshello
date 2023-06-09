/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/06/13 10:34:57 by arnalove         ###   ########.fr       */
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
		data.lexer_lst = parser(&data, &data.pipes);
		if (ft_strlen(data.line))
			add_history(data.line);
		free(data.line);
		if (!data.lexer_lst)
			continue ;
		init_process(&data);
		executor(data.process, data.lst, data.pipes, envp);
		ft_free_all(&data);
	}
	return (0);
}
