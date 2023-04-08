/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/04/08 18:21:14 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
probleme 1  : here_doc
probleme 2	: SHLVL +999 + letters = 1
probleme 3  : si builtin, checker arguments suivant (unset vide, pwd + arg doit renvoyer erreur...)
              a checker juste apres la lexlist
probleme 4  : expander : si $? comment on fait
probleme 5  : AWK
probleme 6  : encore probleme d'espace.. (echo hello' '> outfile)
*/

/*
FT_EXIT_FAILURE(char *str_for_perror);
*/

int main(int argc, char **argv, char **envp)
{
    t_data data;

	(void) argv;
	if (argc != 1)
        return (1);
	sig_handler(0);
    init_data(&data, envp);
    // print_head();
    while (1)
    {
        data.line = readline("LimonShello $> ");
		if (!data.line)
			exit(g_exit_value); // to update avec la globale
        if (parser(data.line, &data.lst, &data.pipes, data.env))
            continue ;
        // ft_printparse(lst);
        init_process(&data);
        executor(data.process, data.lst, data.pipes, envp);
		add_history(data.line);
        ft_free_all(&data);
    }
    return (0);
}
