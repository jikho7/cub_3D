/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:33 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 00:21:27 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	lstsize(t_parse *lst)
{
	int	nbr_element;

	nbr_element = 0;
	while (!lst)
		return (0);
	while (lst)
	{
		nbr_element++;
		lst = lst->next;
	}
	return (nbr_element);
}

t_parse	*lstnew(char *data, t_list **gc_lst)
{
	t_parse	*new_element;

	new_element = my_malloc(1, sizeof(t_parse), gc_lst);
	if (new_element == NULL)
		return (NULL);
	(*new_element).content = data;
	new_element->next = NULL;
	return (new_element);
}

void	add_back(t_parse **head, t_parse *node_to_add)
{
	t_parse	*current;

	current = *head;
	if (*head == NULL)
	{
		*head = node_to_add;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = node_to_add;
	node_to_add->next = NULL;
}

void	display_lst(t_parse **ptr_to_head, char *name)
{
	t_parse	*current_node;
	int		count;

	current_node = *ptr_to_head;
	count = 0;
	printf("\n%s :\n", name);
	if (*ptr_to_head != NULL)
	{
		while (current_node->next != NULL)
		{
			printf("Index = %d : ", count);
			display_node(current_node);
			current_node = current_node->next;
			count++;
		}
		printf("Index = %d : ", count);
		display_node(current_node);
	}
	else
		printf("The stack is empty.\n");
	printf("\n");
}

void	display_node(t_parse *lst)
{
	if (lst != NULL)
	{
		printf("[%p] {content = %s | nx = %p}\n", lst,
			lst->content,
			lst->next);
	}
}
