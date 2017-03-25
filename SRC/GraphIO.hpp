#ifndef GRAPH_IO_HPP_INCLUDED
#define GRAPH_IO_HPP_INCLUDED

#include <vector>
#include <map>

// graph input output library

using namespace std;

struct graph{
	int n,m;
	vector<vector<int> > g;
};

struct graph_edge_nb{
	int n,m;
	vector<vector<pair<int,int> > >g;
};

struct edges{
	int n,m;
	vector<int> u,v;
};

struct mapping{
	graph g;
	edges e;
	map<int,int> m;
};

struct mapping_edge_nb{
	graph_edge_nb g;
	edges e;
	map<int,int> m;
};

struct CovId{
	vector<double> covs;
	vector<double> ids;
};

/* Reads a graph with n m on first line.
 * edges list follows ( m lines)
 * Node id's must be 0 <= id < n
 */

bool read_graph(graph & g,char * file);

bool read_graph_edge_nb(graph_edge_nb & g, char * f);

/* As read_graph above but node id's can be arbitrary.
 * Creates mapping (see above) between original and new nodes
 */
bool read_cc(mapping& m, char * file);

bool read_cc_edge_nb(mapping_edge_nb & m, char * file);

bool read_edges(edges & e, char * file);

bool read_graph_coloring(graph & g, edges &, int &, 
								vector<int> &col, char * file, int);

bool create_gephi_coloring(edges & e, const char * file, 
								int nbCommunities, vector<int>& assign);

bool get_maxCover_and_id(const char * input, CovId &);

#endif // GRAPH_IO_INCLUDE
