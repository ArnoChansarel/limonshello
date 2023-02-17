/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:02:58 by achansar          #+#    #+#             */
/*   Updated: 2023/02/17 15:42:51 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_printlist(t_lexlst *head_a)
{
	t_lexlst *current_a;

	current_a = head_a;
	printf("+-------+\n");
	printf("| LEXER |\n");
	printf("+-------+\n");
	while (current_a)
	{
		if (current_a)
		{
			printf("%s", current_a->word);
			current_a = current_a->next;
		}
		printf("\n");
	}
	printf("+-------+\n\n");
}

void    ft_printparse(t_parser *head)
{
	int j;
	int i = 0;
	t_parser *current;

	current = head;
	printf("+--------+\n");
	printf("| PARSER |\n");
	printf("+--------+\n");
    while (current)
	{
		if (current)
		{
			j = 0;
			printf("ELEMENT %d :\n###########\ncommand :\n", i++);
			while (current->cmd[j])
				printf("%s\n", current->cmd[j++]);
			if (current->builtin)
				printf("#####\nBuiltin : %s\n", current->cmd[0]);
			else
				printf("\nBuiltin : No\n##########\n");
			current = current->next;
		}
	}
	printf("+--------+\n\n");
}