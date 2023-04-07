/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:28:41 by achansar          #+#    #+#             */
/*   Updated: 2023/04/07 13:13:29 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include "executor.h"
#include "structs.h"

# ifndef PATH_MAX
#	define PATH_MAX 1024
# endif

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
# include <limits.h>
# include <dirent.h>
# include <string.h>
#include "executor.h"

int	g_exit_value;

// PARSER FUNCTIONS
t_lexlst 	*lexer(char *cmd_line);
int			parser(char *cmd_line, t_cmd **lstp, int *pipes, t_env *env);

// EXPANDER FUNCTIONS
int			expander(char **cmd, t_env **env);
int 		send_to_expander(t_cmd **cmd_lst);
int 		lookfor_var(char **cmd, t_env **env, int size);

// EXPANDER UTILS
int			get_var_size(char *str);
int			ft_strncmp2(const char *s1, const char *s2, size_t n);
int			expand_quotes(char **cmd, t_env **env);

// PARSER UTILS
int 		count_pipes(t_lexlst *lex);
void    	goto_next(t_lexlst **lex);
int			is_builtin(char *str);
int			elem_parser_init(t_cmd **ele, int c, int index);
int 		count_word_lex(t_lexlst  **lex);
int			add_rdrctn(t_cmd *p, t_lexlst *lex);

//LEXER UTILS
int			checker_quotes(char *line, int s, int d);
int			size_quotes(const char *str);
int			is_token(char *str);
int			check_token(char *line);
int			check_token_ends(char *line);
int			skip_quotes(char *line);

// LIBFT FUNCTIONS
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		ft_putstr_fd(char *str, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *str, int fd);
void		ft_putchar_fd(char c, int fd);
char		*ft_strchr(const char *s, int c);
int			ft_isalpha(int c);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_itoa(int n);
int			ft_isalnum(int c);

//LST LEX FUNCTIONS
t_lexlst	*lexlst_new(void *content);
void		ft_lstadd_front(t_lexlst **lst, t_lexlst *new);
int			ft_lstsize(t_lexlst *lst);
t_lexlst	*ft_lstlast(t_lexlst *lst, int stop);
void		ft_lstadd_back(t_lexlst **lst, t_lexlst *new);
void		lexlst_clear(t_lexlst **lst);

//LST PARSER FUNCTIONS
int			parserlst_size(t_cmd *lst);
t_cmd		*parserlst_last(t_cmd *lst, int stop);
void		parserlst_addback(t_cmd **lst, t_cmd *new);
t_cmd		*parser_new(char **cmd, int (*builtin)(struct s_cmd *),
			t_lexlst *rdrctn);

// DISPLAY
void    	ft_printlist(t_lexlst *head_a);
void    	ft_printparse(t_cmd *head);
int			error_msg(char *str);
void	print_head(void);

// SIGNAL
void		sig_handler(int status);

// BUILTINS FUNCTIONS
int	ft_pwd(t_cmd *cmd);
int	ft_cd(t_cmd *cmd);
int	ft_echo(t_cmd *cmd);
int	ft_env(t_cmd *cmd);
int	ft_exit(t_cmd *cmd);
int	ft_export(t_cmd *cmd);
int	ft_pwd(t_cmd *cmd);
int	ft_unset(t_cmd *cmd);

// BUILTINS LINKED LIST
void	delete_node(t_env *head);
void	push(t_env *head, int export, char *key, char *value);
t_env	*build_env_list(char **envp);
char	*list_return_value_from_key(t_cmd *cmd, char *str1);
void	printlist(t_cmd *cmd);

// BUILTINS UTILS
void	cd_home(char *home, char *pwd, t_cmd *cmd);
void	cd_point(t_cmd *cmd, char *pwd);
void	cd_minus(t_cmd *cmd);
void	cd_go_to_directory(char *directory, char *pwd, t_cmd *cmd);
void	cd_slash(t_cmd *cmd, char *pwd);
t_env	*is_pwd_set(t_cmd *cmd);
int		update_old_pwd(t_cmd *cmd, char *str);
int		get_cmd_id(char *str);
void 	buitins_exec(int i, t_cmd *cmd);
void	ft_free_array(char **tobefreed);
int		ft_print_in_order(t_cmd *cmd);
void    get_builtin_function(char *str, int (**builtin)(struct s_cmd *));

#endif