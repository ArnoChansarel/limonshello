/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:46:55 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 14:25:32 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#ifndef PATH_MAX
# define PATH_MAX 1024
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <dirent.h>
# include <string.h>

typedef struct s_lexer
{
	char *str;
	int	token;
	struct s_lexer *next;
}				t_lexer;

typedef struct s_env {
    int export;
	char *key;
	char *value;
    struct s_env *next;
} 				t_env;

typedef struct s_cmd
{
	char	buf[PATH_MAX];
	char	**tab;
	int		fd;
	int		pid;
	int		exit_status;
	t_env	*head;
}				t_cmd;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_isalpha(int c);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isdigit(int c);

int		ft_env(t_cmd *cmd);
int		ft_unset(t_cmd *cmd);
int		ft_export(t_cmd *cmd);
int		ft_exit(t_cmd *cmd);
int		ft_echo(t_cmd *cmd);
int		ft_cd(t_cmd *cmd);
int		ft_pwd(t_cmd *cmd);

void	cd_home(char *home, char *pwd, t_cmd *cmd);
void	cd_point(t_cmd *cmd, char *pwd);
void	cd_minus(t_cmd *cmd, t_env *tmp);
void	cd_go_to_directory(char *directory, char *pwd, t_cmd *cmd);
void	cd_slash(t_cmd *cmd, char *pwd);
char	*list_return_value_from_key(t_cmd *cmd, char *str1);
t_env	*is_pwd_set(t_cmd *cmd);
int		update_old_pwd(t_cmd *cmd, char *str);
void	build_env_list(char **envp, t_cmd *cmd);
void	delete_node(t_env *head);
void	push(t_env * head, int export, char *key, char *value);
void	printlist(t_cmd *cmd);
#endif