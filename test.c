/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:33:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 00:42:05 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict/libdict.h"
#include "libvect/libvect.h"
#include <string.h>
#include <stdio.h>

#define SEP " | "

#define ADD(k, v) dict_str_add(d, k, v)

#define LOOKUP(k, v) test++; \
	ent = dict_str_lookup(&d, k); \
	vect_mset_end(&ent->val, '\0', 1); \
	if (ent && !strcmp(v, ent->val.data)) ok++;

#define DEL(k, v)  test++; \
	dict_del(&d, k); \
	ent = dict_str_lookup(&d, k); \
	if (!ent) ok++;

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

#define PRE \
	TEST("banana", "fruit"); \
	TEST("lazy", "me"); \
	TEST("Trump", "bad"); \
	TEST("flowers are", "blue"); \
	TEST("hashmaps are", "cool"); \
	TEST("bleu blanc", "rouge"); \
	TEST("answer", "42"); \
	TEST("logic", "fail"); \
	TEST("holy", "thunder"); \
	TEST("baby", "rage"); \
	TEST("dummy", "ymmud"); \
	TEST("love", "you"); \
	TEST("don't", "bully"); \
	TEST("Lolita", "Vladimir Nabokov"); \
	TEST("Cent ans de solitude", "Gabriel Garcia Marquez"); \
	TEST("La mort du roi Tsongor", "Laurent Gaude"); \

#define TEST_RUN(s) \
	printf("-- TEST %s\n", s); \
	test = 0; \
	ok = 0; \
	i = 0; \
	PRE; \
	printf("-- OK: %d\\%d\n", ok, test); \
	printf("%lu used, %lu total\n", d.used, d.total); \
	n_entries(&d); \
	printf("\n");

void		n_entries(t_dict *d)
{
	t_dict_ent	*ent;
	size_t		i;
	size_t		n;

	n = 0;
	ent = d->ents;
	i = 0;
	while (dict_iter(d, &ent, &n))
	{
		i++;
		ent++;
	}
	printf("%lu entries\n", i);
}

void		build_dict(t_dict *d)
{
	dict_str_init(d);
#define TEST ADD
	PRE;
}

void		import_dict(t_dict *d)
{
#undef TEST
#define TEST IMPORT
	PRE;
}

int			main(void)
{
	t_dict d;
	t_dict_ent *ent;
	size_t i;
	int test;
	int ok;
	char **exp;

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
	exp = dict_str_export(&d, "=");
	TEST_RUN("export");

	dict_free(&d);
	return (0);
}
