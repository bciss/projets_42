/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 23:40:47 by bciss             #+#    #+#             */
/*   Updated: 2015/06/11 01:09:03 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include "libfta.h"

#define OK printf("%d\033[38;5;2mOK\t\033[0m", i);
#define KO printf("%d\033[38;5;1mKO\t\033[0m", i);
#define A "\0"
#define B "YO"
#define C "blabla"
#define D "what's up ?\0 NIGGA"

/*
void	ft_puts(char *str);
int		ft_strlen(char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
char	*ft_strdup(char *str);
void	ft_memset(void *str, int c, size_t n);
void	ft_memcpy(void *str, const void *str2, size_t n);
void	ft_strcat(char *str, char *str2);
void	ft_cat(int fd);*/


#define	TEST(fun1, fun2, name) printf("\n\n\033[38;5;13m		TEST %s\n\033[0m", name);for(i = -1; i <= 200; i++){if (fun1(i) != fun2(i)) KO else OK;};

#define	TESTlen(fun1, fun2, name) printf("\n\n\033[38;5;13m		TEST %s\n\033[0m", name);if (fun1(name) != fun2(name)) KO else OK;;

int		main(void)
{
	int		i;
	char	*str;
	char	*st;
	char	*str2;
	char	*dup;
	char	buf[100];
	int		fd;
	char	*tol;
	char	*tol2;

/************************************************************************/
/*                                                                      */
/*                     Test des ft_is*                                  */
/*                                                                      */
/************************************************************************/

	TEST(ft_isalpha, isalpha, "ft_isalpha");
	TEST(ft_isdigit, isdigit, "ft_isdigit");
	TEST(ft_isprint, isprint, "ft_isprint");
	TEST(ft_isascii, isascii, "ft_isascii");
	TEST(ft_tolower, tolower, "ft_tolower");
	TEST(ft_toupper, toupper, "ft_touper");
	TEST(ft_isalnum, isalnum, "ft_isalnum");
	TEST(ft_isspace, isspace, "ft_isspace");
	TEST(ft_islower, islower, "ft_islower");
	TEST(ft_isupper, isupper, "ft_isupper");



/************************************************************************/
/*                                                                      */
/*                     Test de ft_strlen                                */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_strlen\033[0m");
	TESTlen(ft_strlen, strlen, A);
	TESTlen(ft_strlen, strlen, B);
	TESTlen(ft_strlen, strlen, C);
	TESTlen(ft_strlen, strlen, D);



/************************************************************************/
/*                                                                      */
/*                     Test de ft_tolower                               */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_tolower\033[0m\n");
	tol = strdup("ceci est UNE GRANDELIGNE !");
	printf("avant le tolower : %s\n", tol);
	int		t = 0;
	while (tol[t] != '\0')
	{
		tol[t] = ft_tolower(tol[t]);
		t++;
	}
	printf("apres le tolower : %s\n", tol);



/************************************************************************/
/*                                                                      */
/*                     Test de ft_toupper                               */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_toupper\033[0m\n");
	tol2 = strdup("ET SA C'EST une petite ligne.");
	printf("avant le toupper : %s\n", tol2);
	t = 0;
	while (tol2[t] != '\0')
	{
		tol2[t] = ft_toupper(tol2[t]);
		t++;
	}
	printf("apres le toupper : %s\n", tol2);



/************************************************************************/
/*                                                                      */
/*                     Test de ft_memset                                */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_memset\033[0m\n");
	str = strdup("ceci est une chaine mallocé");
	st = strdup("ceci est une chaine mallocé");
	ft_memset(str, 'y', 10);
	memset(st, 'y', 10);
	if (!strcmp(str, st))
		OK
	else
		KO



/************************************************************************/
/*                                                                      */
/*                     Test de ft_memcpy                                */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_memcpy\033[0m\n");
	str2 = strdup("blablablablablablablablablablablablablablablabla");
	ft_memcpy(str2, str, 2);
	printf("%s\n", str2);



/************************************************************************/
/*                                                                      */
/*                     Test de ft_strdup                                */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_strdup\033[0m\n");
	str2 = ft_strdup("yo MOMA!");
	printf("%s\n", str2);



/************************************************************************/
/*                                                                      */
/*                     Test de ft_bzero                                 */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_bzero\033[0m\n");
	bzero(str2, 100);
	printf("%s\n", str2);


/************************************************************************/
/*                                                                      */
/*                     Test de ft_strcat                                */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_strcat\033[0m\n");
	ft_strcat(str2, str);
	printf("%s\n", str2);



/************************************************************************/
/*                                                                      */
/*                     Test de ft_cat                                   */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_cat\033[0m\n");
	fd = open("./ft_bzero.s", O_RDWR);
	if (fd < 0)
		printf("ouuups fd = %d\n", fd);
	ft_cat(fd);
	printf("ca doit afficher :Whats up nigga\n");



/************************************************************************/
/*                                                                      */
/*                     Test de ft_puts                                  */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_puts\033[0m\n");
	str = NULL;
	ft_puts(NULL);
	ft_puts("si tu me vois c bon =D");

/************************************************************************/
/*##################################################################### */
/*                           LES BONUS                                  */
/*##################################################################### */
/************************************************************************/

/************************************************************************/
/*                                                                      */
/*                      Test de ft_strncat                              */
/*                                                                      */
/************************************************************************/

	printf("\033[38;5;13m\n\n\t\tTEST ft_memalloc\033[0m\n");
	char	*lolo;

	lolo = ft_memalloc(30);
	strcat(lolo, "salut bien ou bien ? =D");
	printf("%s\n", lolo);

/************************************************************************/
/*                                                                      */
/*                      Test de ft_strncat                              */
/*                                                                      */
/************************************************************************/

	char	*truc;
	char	*truc2;

	printf("\033[38;5;13m\n\n\t\tTEST ft_strncat\033[0m\n");
	truc = ft_strdup("yoeuh");
	truc2 = ft_strdup("123 soleil!");
	truc = ft_strncat(truc, truc2, 3);
	printf("%s\n", truc);
	return (0);
}
