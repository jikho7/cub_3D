/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:21:19 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:21:19 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new);
/*Fichiers de rendu -
Paramètres lst: L’adresse du pointeur vers le premier élément
de la liste.
new: L’adresse du pointeur vers l’élément à
rajouter à la liste.
Valeur de retour Aucune
Fonctions externes autorisées
Aucune
Description Ajoute l’élément ’new’ au début de la liste.

*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		new->next = NULL;
	else
		new->next = *lst;
	*lst = new;
}
