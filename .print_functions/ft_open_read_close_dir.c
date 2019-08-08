/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read_close_dir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:44:06 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/11 11:32:58 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//typedef struct dirent dirent;
//typedef struct stat stat;

int		main(int argc, char ** argv) {
	DIR             *dir = NULL;
	struct dirent   *file = NULL;
	struct stat		buf;

	if (argc >= 2) {
		if (!(dir = opendir(argv[1])))
			perror("opendir : ");
		while ((file = readdir(dir)))
		{
			printf("%s\n", file->d_name);
			if (stat(file->d_name, &buf) == -1)
				perror("stat : ");
			printf("taille : %lld\n", buf.st_size);

		}

//		if (!(closedir(dir)))
//			perror("closedir : ");
	} else
		return (0);
}


