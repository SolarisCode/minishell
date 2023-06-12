/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:42:46 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/11 18:38:01 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_swap(t_env *a, t_env *b)
{
	char	*temp1;
	char	*temp2;

	temp1 = a->var;
	temp2 = a->value;
	a->var = b->var;
	a->value = b->value;
	b->var = temp1;
	b->value = temp2;
}

void	ft_sort_linked_list(t_env **head_ref)
{
	int		swapped;
	t_env	*current;

	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return ;
	while (1)
	{
		swapped = 0;
		current = *head_ref;
		while (current->next != NULL)
		{
			if (strcmp(current->var, current->next->var) > 0)
			{
				ft_swap(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		if (!swapped)
			break ;
	}
}

void	ft_free_node(t_env *node)
{
	free(node->value);
	free(node->var);
	free(node);
}

t_env	*ft_find_last_node(t_env *head_ref)
{
	t_env	*current;

	current = head_ref;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_add_back(t_env **head_ref, t_env *node)
{
	t_env	*last_node;

	last_node = ft_find_last_node(*head_ref);
	last_node->next = node;
	node->next = NULL;
}
