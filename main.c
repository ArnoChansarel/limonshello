/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:46:45 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 16:47:07 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"


char	*cmdtrim(t_lexer *lexer)
{
	char	**str;
	str = ft_split(lexer->str, 32);
	printf("%s", str[1]);
	return (str[0]);
}

int	main(int argc, char ** argv, char **envp)
{
	argc = 0;
	argv = 0;
	t_cmd	cmd;
	t_lexer	lexer;
	char	*prompt = ">$";

	build_env_list(envp, &cmd);
	while (1)
	{
		cmd.tab = NULL;
		lexer.str = readline(prompt);
		cmd.tab = ft_split(lexer.str, ' ');
		if (strcmp(cmd.tab[0], "echo") == 0)
			ft_echo(&cmd);
		if (strcmp(cmd.tab[0], "pwd") == 0)
			ft_pwd(&cmd);
		if (strcmp(cmd.tab[0], "export") == 0)
			ft_export(&cmd);		
		if (strcmp(cmd.tab[0], "unset") == 0)
			ft_unset(&cmd);
		if (strcmp(cmd.tab[0],"cd") == 0)
			ft_cd(&cmd);
		if (strcmp(cmd.tab[0],"env") == 0)
			ft_env(&cmd);
		if (strcmp(cmd.tab[0], "exit") == 0)
			ft_exit(&cmd);
	}
	return (0);
}
