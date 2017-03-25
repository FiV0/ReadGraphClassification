#ifndef TEST_HPP_INCLUDED
#define TEST_HPP_INCLUDED

/* module to print some structures*/

#include <vector>

#include "GraphIO.hpp"
#include "algo.hpp"
#include "algo_clique.hpp"

template<typename T> void print_vector(vector<T> & v);

template<typename T> void print_vv(vector<vector<T> > & v);

void testLexBFS(graph & g);

void testLexBFS_plus(graph & g,vector<int> init);

void testMultiSweep(graph & g);

void print_cliqueTree(cliqueTree & ct);

void testCliqueTree(graph & g);

void testIntervalGraph(graph & g);

void testLexBFS(graph & g);

#endif // TEST_HPP
