#include <iostream>
#include <utility>
#include <algorithm>

#include "test.hpp"
#include "algo_interval.hpp"
#include "algo_clustering.hpp"

using namespace std;

template<typename T> void print_vector(vector<T> & v){
	int n = v.size();
	for(int i=0;i<n;++i){
		cout << v[i] + 1<< " ";
	}
	cout << endl;
}

template<typename T> void print_vv(vector<vector<T> > & v){
	int n = v.size();
	for(int i=0;i<n;++i){
		print_vector(v[i]);
	}
}

void print_cliqueTree(cliqueTree & ct){
	vector<vector<int> > & cliques = ct.cliques;
	vector<pair<int,vector<int> > > & edges = ct.edges;

	cout << "Clique: 0 = ";
	print_vector(cliques[0]);
	cout << endl;

	for(size_t i=1;i<cliques.size();++i){
		cout << "Clique: " << i << " = ";
		print_vector(cliques[i]);
		cout << endl << "Parent: " << edges[i].first;
		cout << " MinimalSeperator = ";
		print_vector(edges[i].second);
		cout << endl;
	}
}

void testLexBFS(graph & g){
	vector<int> per,inv;

	lexBFS(g,per,inv);

	for(size_t i=0;i<per.size();++i){
		cout << per[i] + 1<< " ";
	}
	cout << endl; 
}

void testLexBFS_plus(graph & g, vector<int> init){
	vector<int> per,inv;

	lexBFS_plus(g,per,inv,init);

	for(size_t i=0;i<per.size();++i){
		cout << per[i] + 1<< " ";
	}
	cout << endl; 
}

void testMultiSweep(graph & g){
	vector<int> per,inv;
	multiSweep(5,g,per,inv);
}

void testCliqueTree(graph & g){
	cliqueTree ct;
	calcCT(g,ct);
	print_cliqueTree(ct); 
}

void print_intervals(vector<vector<pair<int,int> > > & intervals){
	for(size_t i=0;i<intervals.size();++i){
		cout << "Node " << i+1 << " : ";
		for(vector<pair<int,int> >::iterator it = intervals[i].begin();
						it != intervals[i].end(); ++it){
			cout << it->first << "<--->" << it->second << " ";
		}
		cout << endl;
	}
}

void testIntervalGraph(graph & g){
	cliqueTree ct;
	calcCT(g,ct);
	print_cliqueTree(ct);
	
	vector<vector<pair<int,int> > > intervals;
	calculate_intervals(intervals,ct);

	
	//print_intervals(intervals);

	size_t ma = 0;
	for(size_t i=0;i<intervals.size(); ++i){
		ma = max(ma,intervals[i].size());
	}
	cout << ma << endl;
}

void testLexDFS(graph & g){
	vector<int> per(g.n);
	vector<int> inv(g.n);

	lexDFS(g,0,per,inv);

	print_vector(per);
	cout<< endl;
}

