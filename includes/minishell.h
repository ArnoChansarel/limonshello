/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:28:41 by achansar          #+#    #+#             */
/*   Updated: 2023/02/20 17:04:28 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

typedef struct node {
	int			export;
	char		*key;
	char		*value;
	struct node *next;
}	t_node;

typedef struct s_token {
	char	*pipe;
	char	*r_in;
	char	*r_out;
	int		append;
	char	*here_doc;
}	t_token;

typedef struct s_lexlst {
	char			*word;
	struct s_lexlst	*next;
}	t_lexlst;

typedef struct s_parser {
	char				**cmd;
	int					(*builtin)(struct s_parser *);
	char				*rd_in;
	char				*rd_out;
	struct s_parser 	*next;
}	t_parser;

// PARSER FUNCTIONS
t_lexlst 	*lexer(char *cmd_line);
int			parser(char *cmd_line, t_parser **lstp);
int			expander(t_lexlst **lex, t_node **env);

// PARSER UTILS
int 		count_pipes(t_lexlst *lex);
void    	goto_next(t_lexlst **lex);
int			is_builtin(char *str);
int			elem_parser_init(t_parser **ele, int c);
int 		count_word_lex(t_lexlst  **lex);
int			add_rdrctn(t_parser *p, t_lexlst *lex);

//LEXER UTILS
int			checker_quotes(char *line, int s, int d);
int			size_quotes(const char *str);
int			is_token(char *str);
int			check_token(char *line);

// LIBFT FUNCTIONS
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

//LST LEX FUNCTIONS
t_lexlst	*lexlst_new(void *content);
void		ft_lstadd_front(t_lexlst **lst, t_lexlst *new);
int			ft_lstsize(t_lexlst *lst);
t_lexlst	*ft_lstlast(t_lexlst *lst, int stop);
void		ft_lstadd_back(t_lexlst **lst, t_lexlst *new);
void		lexlst_clear(t_lexlst **lst);

//LST PARSER FUNCTIONS
int			parserlst_size(t_parser *lst);
t_parser	*parserlst_last(t_parser *lst, int stop);
void		parserlst_addback(t_parser **lst, t_parser *new);
t_parser	*parser_new(char **cmd, int (*builtin)(struct s_parser *),
			t_lexlst *rdrctn);


// DISPLAY
void    	ft_printlist(t_lexlst *head_a);
void    	ft_printparse(t_parser *head);
int			error_msg(char *str);

#endif