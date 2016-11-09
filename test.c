/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:33:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 03:57:17 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict/libdict.h"
#include <stdio.h>

#define ADD(k, v) dict_str_add(d, k, v)
#define LOOKUP(k) \
	ent = dict_str_lookup(&d, k); \
	printf("%s = %.*s\n", k, (int)ent->val.used, ent->val.data);


void		build_dict(t_dict *d)
{
	dict_str_init(d);
	ADD("banana", "fruit");
	ADD("lazy", "me");
}

int			main(void)
{
	t_dict d;
	t_dict_ent *ent;

	build_dict(&d);
	LOOKUP("banana");
	LOOKUP("lazy");
	return (0);
}
