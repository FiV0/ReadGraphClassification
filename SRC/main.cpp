#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>

#include "algo.hpp"
#include "algo_clique.hpp"
#include "algo_interval.hpp"
#include "algo_clustering.hpp"
#include "algo_branches.hpp"
#include "algo_cycles.hpp"
#include "algo_chordless.hpp"
#include "GraphIO.hpp"
#include "test.hpp"
#include "algo_union.hpp"

using namespace std;

// normal graph 
// membership
// originalfile
// union type 
// quasi clique cut off
// laminar_index

int main(int , char * argv[]){
	srand(time(NULL));
	
	//time start
	unsigned long long nsec;
	long double sec;
	timespec start,end;

	clock_gettime(CLOCK_REALTIME,&start);
	
	graph g;
	edges e;
	vector<int> assign;

	CovId covIds;

	if(!get_maxCover_and_id(argv[1],covIds)){
		return 1;				
	}
	
	/*if(!read_graph_coloring(g,e,nb,assign,argv[1],atoi(argv[2]))){
		return 1;
	}

	create_gephi_coloring(e,argv[3],nb,assign);

	string name(argv[3]);
	string name_without_ex = name.substr(0,name.find_last_of("."));

	find_cycles(g,e,nb,assign,name_without_ex);

	string union_name = name_without_ex + ".union.gdf";

	const char * union_char = union_name.c_str();
	
	create_gephi_coloring(e,union_char,nb,assign); */


	/*vector<vector<int> > cycles;
	chordless_cycles(g,cycles);

	//print_vv(cycles);
	//
	cout << cycles.size() << endl;
	for(int i=0;i<(int)cycles.size();++i){
		print_vector(cycles[i]);
		cout << endl;
	}*/

	//compactCommunities2(m.g,m1.g,m.e,100,nb,assign);

	//compactCommunities(m.g,m.e,100,nb,assign);
	//
	//newman_greedy_clustering(m.g,m.e,nb,assign);
	//nb = 2;	
	//if(branches(m.g,7,assign))
	//algo_cycles(m.g,2,3,assign);
	//unify(m.g,m.e,nb,assign);	
	//


	//testLexBFS(g);
	//testCliqueTree(g);
 	//testMultiSweep(m.g);
	//testIntervalGraph(m.g);
	//vector<int> assign;
	
	//cout << diametral_path(m.g,atoi(argv[2])) << endl;

	//create_gephi_coloring(m.e,argv[3],2,assign);
 	
	/*if(check_interval(m.g)){
		cout << "ok" << endl;
	}*/
	
	//vector<int> init = {1,4,3,6,7,2,5,0};
	//vector<int> init = {0,1,2,3,4,5,6,7};
	
	//testLexBFS_plus(g,init); 
	
	/*cout << diameter(m.g) << endl;

	clock_gettime(CLOCK_REALTIME,&end);

	nsec = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
	sec = nsec / 1e9;

	cout << fixed << setprecision(10) << sec << endl;

	clock_gettime(CLOCK_REALTIME,&start);

	
	cout << diameter_iFUB(m.g) << endl;*/
	/*if(diameter_check(m.g,10))
		cout << "ok" << endl;
	else
		cout << "bigger" << endl; */

	//time end
	clock_gettime(CLOCK_REALTIME,&end);

	nsec = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
	sec = nsec / 1e9;

	cout << fixed << setprecision(10) << sec << endl;

	return 0;
}
