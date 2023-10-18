/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:36:24 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:38:11 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Fichiers de rendu -
Paramètres lst: Le début de la liste.
Valeur de retour Taille de la liste
Fonctions externes autorisées
Aucune
Description Compte le nombre d’éléments de la liste.
*/

int	ft_lstsize(t_list *lst)
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
