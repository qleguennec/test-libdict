/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:33:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 05:41:45 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict/libdict.h"
#include "libvect/libvect.h"
#include <string.h>
#include <stdio.h>

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
	dict_str_import(d, k"="v, '=');


void		build_dict(t_dict *d)
{
	dict_str_init(d);
#define TEST ADD
	TEST("banana", "fruit");
	TEST("lazy", "me");
	TEST("Trump", "bad");
	TEST("flowers are", "blue");
	TEST("hashmaps are", "cool");
	TEST("bleu blanc", "rouge");
	TEST("answer", "42");
	TEST("logic", "fail");
	TEST("holy", "thunder");
	TEST("baby", "rage");
	TEST("dummy", "ymmud");
	TEST("don't", "bully");
	TEST("Lolita", "Vladimir Nabokov");
	TEST("Cent ans de solitude", "Gabriel Garcia Marquez");
	TEST("La mort du roi Tsongor", "Laurent Gaude");
}

void		import_dict(t_dict *d)
{
#undef TEST
#define TEST IMPORT
	TEST("banana", "fruit");
	TEST("lazy", "me");
	TEST("Trump", "bad");
	TEST("flowers are", "blue");
	TEST("hashmaps are", "cool");
	TEST("bleu blanc", "rouge");
	TEST("answer", "42");
	TEST("logic", "fail");
	TEST("holy", "thunder");
	TEST("baby", "rage");
	TEST("dummy", "ymmud");
	TEST("don't", "bully");
	TEST("Lolita", "Vladimir Nabokov");
	TEST("Cent ans de solitude", "Gabriel Garcia Marquez");
	TEST("La mort du roi Tsongor", "Laurent Gaude");
}

int			main(void)
{
	t_dict d;
	t_dict_ent *ent;
	int test;
	int ok;

	build_dict(&d);
	test = 0;
	ok = 0;
#undef TEST
#define TEST LOOKUP
	TEST("banana", "fruit");
	TEST("lazy", "me");
	TEST("Trump", "bad");
	TEST("flowers are", "blue");
	TEST("hashmaps are", "cool");
	TEST("bleu blanc", "rouge");
	TEST("answer", "42");
	TEST("logic", "fail");
	TEST("holy", "thunder");
	TEST("baby", "rage");
	TEST("dummy", "ymmud");
	TEST("don't", "bully");
	TEST("Lolita", "Vladimir Nabokov");
	TEST("Cent ans de solitude", "Gabriel Garcia Marquez");
	TEST("La mort du roi Tsongor", "Laurent Gaude");
	printf("OK: %d\\%d\n", ok, test);
	printf("%lu used, %lu total\n", d.used, d.total);
	test = 0;
	ok = 0;
#undef TEST
#define TEST DEL
	TEST("banana", "fruit");
	TEST("lazy", "me");
	TEST("Trump", "bad");
	TEST("flowers are", "blue");
	TEST("hashmaps are", "cool");
	TEST("bleu blanc", "rouge");
	TEST("answer", "42");
	TEST("logic", "fail");
	TEST("holy", "thunder");
	TEST("baby", "rage");
	TEST("dummy", "ymmud");
	TEST("don't", "bully");
	TEST("Lolita", "Vladimir Nabokov");
	TEST("Cent ans de solitude", "Gabriel Garcia Marquez");
	TEST("La mort du roi Tsongor", "Laurent Gaude");
	printf("OK: %d\\%d\n", ok, test);
	printf("%lu used, %lu total\n", d.used, d.total);
	test = 0;
	ok = 0;
#undef TEST
#define TEST LOOKUP
	import_dict(&d);
	TEST("banana", "fruit");
	TEST("lazy", "me");
	TEST("Trump", "bad");
	TEST("flowers are", "blue");
	TEST("hashmaps are", "cool");
	TEST("bleu blanc", "rouge");
	TEST("answer", "42");
	TEST("logic", "fail");
	TEST("holy", "thunder");
	TEST("baby", "rage");
	TEST("dummy", "ymmud");
	TEST("don't", "bully");
	TEST("Lolita", "Vladimir Nabokov");
	TEST("Cent ans de solitude", "Gabriel Garcia Marquez");
	TEST("La mort du roi Tsongor", "Laurent Gaude");
	printf("OK: %d\\%d\n", ok, test);
	printf("%lu used, %lu total\n", d.used, d.total);

	dict_free(&d);
	return (0);
}
