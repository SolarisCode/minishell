/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_buildins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:24:17 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/14 21:56:30 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_execute_buildins(t_cmds *cmd, t_mVars *list_pointer)
{
	if ((cmd->redirect & HEREDOC) == HEREDOC)
		close(ft_here_doc(cmd->hdocs_end, list_pointer->ls_env));
	if (!cmd->path_exist)
	{
		printf("minihell: No such file or directory : %s\n", cmd->cmd);
		return ;
	}
	if (!ft_strcmp(cmd->cmd, "echo") || !ft_strcmp(cmd->cmd, "/bin/echo"))
		ft_echo(cmd);
	if (!ft_strcmp(cmd->cmd, "env") || !ft_strcmp(cmd->cmd, "/usr/bin/env"))
		ft_env(list_pointer);
	if (!ft_strcmp(cmd->cmd, "pwd") || !ft_strcmp(cmd->cmd, "/bin/pwd"))
		ft_pwd();
	if (!ft_strcmp(cmd->cmd, "export")
		|| !ft_strcmp(cmd->cmd, "/usr/bin/export"))
		ft_export(cmd, list_pointer);
	if (!ft_strcmp(cmd->cmd, "check_buffer"))
		ft_check_buffer(list_pointer);
	if (!ft_strcmp(cmd->cmd, "unset") || !ft_strcmp(cmd->cmd, "/usr/bin/unset"))
		ft_unset(cmd, list_pointer);
	if (!ft_strcmp(cmd->cmd, "exit") || !ft_strcmp(cmd->cmd, "/usr/bin/exit"))
		ft_exit();
	if (!ft_strcmp(cmd->cmd, "cd"))
		ft_cd(cmd, list_pointer);
}

void	ft_builtin_one_cmd(t_cmds *cmd, t_mVars *vars_list)
{
	int	count;

	count = 0;
	if (!ft_strcmp(cmd->cmd, "exit") || !ft_strcmp(cmd->cmd, "/usr/bin/exit"))
	{
		if (cmd->args)
			while (cmd->args[count])
				count ++;
		if (count > 1)
		{
			printf("minishell: too many arguments: exit\n");
			cmd->cmd_error = 1;
			return ;
		}
		ft_free_dstr(vars_list->env_array);
		ft_exit_minihell(NULL, cmd, vars_list);
	}
	ft_execute_buildins(cmd, vars_list);
}
