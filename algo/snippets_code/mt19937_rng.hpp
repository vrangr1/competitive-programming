/*
Details for snippet generator program:
title       : RNG Snippet
prefix      : import_rng
description : RNG Snippet
*/
#ifndef RANDOM_SNIPPET
#define RANDOM_SNIPPET
#include <random>
#include <chrono>
std::mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
unsigned long long int grng(const unsigned long long int maxval){return rng()%maxval;}
#endif