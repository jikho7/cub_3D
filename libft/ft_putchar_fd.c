/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:04 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:48:35 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/*
int main(int ac, char** av)
{
	
	ft_putchar_fd('B', 1);
	int lettre;

	FILE *fil = fopen("test.c", "r" );
	if(fil == NULL)
	   exit(1);
	while((lettre = fgetc(fil)) != EOF)
	printf("%c", lettre);
	 fclose(fil);
	return(0);
}*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
open_ft(<file_name_to_open>, <opening_mode>), return a fileDesciptor (int fd)
control if open is okay, or not, return -1
O_RDONLY, open n read
O_WRONLY write only
O_RDWR read n write
O_CREAT create a file which doesn't exist
O_APPEND write to the end of file
O_TRUNC 
*/