/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:38:28 by achansar          #+#    #+#             */
/*   Updated: 2023/04/28 16:43:05 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structs.h"

// PARSER FUNCTION
t_lexlst	*parser(t_data *data, int *pipes);

// PARSER UTILS
int			count_pipes(t_lexlst *lex);
void		goto_next(t_lexlst **lex);
int			is_builtin(char *str);
int			elem_parser_init(t_cmd **ele, int c, int index);
int			count_word_lex(t_lexlst **lex);
int			add_rdrctn(t_cmd *p, t_lexlst *lex);
char		**check_env(char **envp);

//LST PARSER FUNCTIONS
int			parserlst_size(t_cmd *lst);
t_cmd		*parserlst_last(t_cmd *lst, int stop);
void		parserlst_addback(t_cmd **lst, t_cmd *new);
t_cmd		*parser_new(char **cmd, int (*builtin)(struct s_cmd *),
				t_lexlst *rdrctn);

#endif
