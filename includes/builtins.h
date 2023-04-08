/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:45:40 by achansar          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:47 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "structs.h"

// BUILTINS FUNCTIONS
int	    ft_pwd(t_cmd *cmd);
int	    ft_cd(t_cmd *cmd);
int	    ft_echo(t_cmd *cmd);
int	    ft_env(t_cmd *cmd);
int	    ft_exit(t_cmd *cmd);
int	    ft_export(t_cmd *cmd);
int	    ft_pwd(t_cmd *cmd);
int	    ft_unset(t_cmd *cmd);

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
void    get_builtin_function(char *str, t_env *env, int (**builtin)(struct s_cmd *));


#endif
