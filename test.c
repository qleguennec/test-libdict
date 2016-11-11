/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:33:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 14:52:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict/libdict.h"
#include "libvect/libvect.h"
#include "test.h"
#include <string.h>
#include <stdio.h>

#define SEP " | "

#define ADD(k, v) dict_str_add(d, k, v)

#define LOOKUP(k, v) test++; \
	ent = dict_lookup(&d, k); \
	if (ent) vect_mset_end(&ent->val, '\0', 1); \
	if (ent && !strcmp(v, ent->val.data) && !strcmp(k, ent->key)) ok++;

#define DEL(k, v)  test++; \
	if (dict_modify(&d, k, &dict_ent_del) && !dict_lookup(&d, k)) ok++;

#define IMPORT(k, v); \
	dict_str_import(d, k SEP v, SEP);

#define EXPORT(k, v); test++; \
	i = 0; \
	while (exp[i]) \
	{ \
		if (!strcmp(k SEP v, exp[i])) \
			ok++; \
		i++; \
	}

#define TEST_RUN(s) \
	printf("-- TEST %s\n", s); \
	test = 0; \
	ok = 0; \
	i = 0; \
	PRE; \
	printf("-- OK: %d\\%d\n", ok, test); \
	printf("%lu used, %lu total\n", d.used, d.total); \
	printf("%lu del, %lu total\n", d.del, d.total); \
	printf("\n");

void		build_dict(t_dict *d)
{
	dict_str_init(d, 1);
#define TEST ADD
	PRE;
}

void		import_dict(t_dict *d)
{
#undef TEST
#define TEST IMPORT
	PRE;
}

void		exp_print(char **exp)
{
	while (*exp)
		printf("%s\n", *exp++);
}

int			main(void)
{
	t_dict d;
	t_dict_ent *ent;
	char **exp;
	size_t i;
	int test;
	int ok;

	build_dict(&d);
#undef TEST
#define TEST LOOKUP
	TEST_RUN("lookup");
#undef TEST
#define TEST DEL
	TEST_RUN("del");
#undef TEST
#define TEST LOOKUP
	import_dict(&d);
	TEST_RUN("import-lookup");
#undef TEST
#define TEST EXPORT
	exp = dict_str_export(&d, SEP);
	TEST_RUN("export");

	char **exp1 = exp;
	while (*exp)
		free(*exp++);
	free(exp1);

#undef TEST
#define TEST DEL
	TEST_RUN("free");

	dict_free(&d);
	return (0);
}
