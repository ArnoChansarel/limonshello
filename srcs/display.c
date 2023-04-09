/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:02:58 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 17:55:23 by achansar         ###   ########.fr       */
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

void    ft_printparse(t_cmd *head)
{
	int j;
	int i = 0;
	t_cmd *current;

	current = head;
	printf("+------------------------+\n");
	printf("|          PARSER        |\n");
	printf("+------------------------+\n");
    while (current)
	{
		if (current)
		{
			j = 0;
			printf("         ELEMENT %d :\n##########################\nCommand     : ", i++);
			while (current->cmd[j])
				printf("%s ", current->cmd[j++]);
			if (current->builtin)
				printf("\nBuiltin       : %s\n", current->cmd[0]);
			else
				printf("\nBuiltin       : No\n");
			if (current->rd_in)
				printf("Redirection IN  : %s\n", current->rd_in);
			else
				printf("Redirection IN : No\n");
			if (current->rd_out)
				printf("Redirection OUT : %s\n##########################\n\n", current->rd_out);
			else
				printf("Redirection OUT : No\n##########################\n\n");
			current = current->next;
		}
	}
	printf("+------------------------+\n\n");
}

void	print_head(void)
{
	printf("\n========================================================================================================================\n");
	printf(" __         __     __    __     ______     __   __     ______     __  __     ______     __         __         ______    \n");
	printf("/\\ \\       /\\ \\   /\\ \"-./  \\   /\\  __ \\   /\\ \"-.\\ \\   /\\  ___\\   /\\ \\_\\ \\   /\\  ___\\   /\\ \\       /\\ \\       /\\  __ \\   \n");
	printf("\\ \\ \\____  \\ \\ \\  \\ \\ \\-./\\ \\  \\ \\ \\/\\ \\  \\ \\ \\-.  \\  \\ \\___  \\  \\ \\  __ \\  \\ \\  __\\   \\ \\ \\____  \\ \\ \\____  \\ \\ \\/\\ \\  \n");
	printf(" \\ \\_____\\  \\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\\\"\\_\\  \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\ \n");
	printf("  \\/_____/   \\/_/   \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/   \\/_/\\/_/   \\/_____/   \\/_____/   \\/_____/   \\/_____/\n");
	printf("                                                                                                                        \n");
	printf("========================================================================================================================\n\n");
}
