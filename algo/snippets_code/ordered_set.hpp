/*
Details for snippet generator program:
title       : Ordered Set via GNU PBDS
prefix      : import_oset
description : Ordered Set via GNU PBDS
*/
#ifndef ORDERED_SET_SNIPPET
#define ORDERED_SET_SNIPPET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename type>
using ordered_set = tree<type,null_type,std::less<type>,rb_tree_tag,tree_order_statistics_node_update>;
#endif