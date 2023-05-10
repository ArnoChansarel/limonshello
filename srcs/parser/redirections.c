/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:41:02 by achansar          #+#    #+#             */
/*   Updated: 2023/05/10 19:31:49 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	try_open_rd(char *rd)
{
	int	fd;
	int	i;

	i = 0;
	fd = 0;
	while (rd[i] == '<' || rd[i] == '>' || rd[i] == ' ')
		i++;
	if (rd[i - 2] == '<' && i == 2)
		fd = open(&rd[i], O_RDONLY);
	else
		fd = open(&rd[i], O_CREAT, 0644);
	return (fd);
}

static int	add_rdin(t_cmd *p, t_lexlst *lex)
{
	int		fd;
	char	*temp;

	temp = NULL;
	if (p->rd_in)
	{
		fd = try_open_rd(p->rd_in);
		if (fd >= 0)
		{
			free(p->rd_in);
			temp = ft_strjoin(lex->word, " ");
			p->rd_in = ft_strjoin(temp, lex->next->word);
			free(temp);
			close(fd);
		}
		else
			return (1);
	}
	else
	{
		temp = ft_strjoin(lex->word, " ");
		p->rd_in = ft_strjoin(temp, lex->next->word);
		free(temp);
	}
	return (0);
}

static int	add_rdout(t_cmd *p, t_lexlst *lex)
{
	int		fd;
	char	*temp;

	temp = NULL;
	if (p->rd_out)
	{
		fd = try_open_rd(p->rd_out);
		if (fd >= 0)
		{
			free(p->rd_out);
			temp = ft_strjoin(lex->word, " ");
			p->rd_out = ft_strjoin(temp, lex->next->word);
			free(temp);
			close(fd);
		}
		else
			return (1);
	}
	else
	{
		temp = ft_strjoin(lex->word, " ");
		p->rd_out = ft_strjoin(temp, lex->next->word);
		free(temp);
	}
	return (0);
}

int	add_rdrctn(t_cmd *p, t_lexlst *lex)
{
	if (lex->word[0] == '<')
	{
		if (add_rdin(p, lex))
			return (1);
	}
	else
	{
		if (add_rdout(p, lex))
			return (1);
	}
	return (0);
}
