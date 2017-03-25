#include "GraphIO.hpp"
#include "utility.hpp"

#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

//debug
#include <cassert>

using namespace std;

bool read_graph(graph & g, char * input){
	ifstream is(input);
	if(!is.is_open()){
		cout << "Error\nCould not open " << input << endl;
		return false;
	}
	is >> g.n >> g.m;
	g.g.resize(g.n);
	for(int i=0; i<g.m;++i){
		int x,y;
		is >> x >> y;
		g.g[x].push_back(y);
		g.g[y].push_back(x);
	}
	is.close();
	return true;
}

bool read_graph_edge_nb(graph_edge_nb & g, char * input){
	ifstream is(input);
	if(!is.is_open()){
		cout << "Error\nCould not open " << input << endl;
		return false;
	}
	is >> g.n >> g.m;
	g.g.resize(g.n);
	for(int i=0; i<g.m;++i){
		int x,y;
		is >> x >> y;
		g.g[x].push_back(make_pair(y,i));
		g.g[y].push_back(make_pair(x,i));
	}
	is.close();
	return true;
}

int assign_get(map<int,int> & m, int & cur, int val){
	int res;
	if(m.find(val) == m.end()){
		res = m[val] = cur;
		++cur;
	}else{
		res = m[val];	
	}
	return res;
}

bool read_cc(mapping & m, char * input){
	ifstream is(input);
	if(!is.is_open()){
		cout << "Error\nCould not open " << input << endl;
		return false;
	}
	graph & g = m.g;
	map<int,int> & ma = m.m;
	edges & e = m.e;

	is >> g.n >> g.m;
	e.n = g.n;
	e.m = g.m;
	g.g.resize(g.n);
	e.u.resize(e.m);
	e.v.resize(e.m);
	int cur = 0;
	for(int i=0; i<g.m;++i){
		assert(cur <= g.n);
		int x,y,mx,my;
		is >> x >> y;
		mx = assign_get(ma,cur,x);
		my = assign_get(ma,cur,y);
		e.u[i] = mx;
		e.v[i] = my;
		g.g[mx].push_back(my);
		g.g[my].push_back(mx);
	}
	is.close();
	return true;
}

bool read_cc_edge_nb(mapping_edge_nb & m, char * input){
	ifstream is(input);
	if(!is.is_open()){
		cout << "Error\nCould not open " << input << endl;
		return false;
	}
	graph_edge_nb & g = m.g;
	map<int,int> & ma = m.m;
	edges & e = m.e;

	is >> g.n >> g.m;
	e.n = g.n;
	e.m = g.m;
	g.g.resize(g.n);
	e.u.resize(e.m);
	e.v.resize(e.m);
	int cur = 0;
	for(int i=0; i<g.m;++i){
		assert(cur <= g.n);
		int x,y,mx,my;
		is >> x >> y;
		mx = assign_get(ma,cur,x);
		my = assign_get(ma,cur,y);
		e.u[i] = mx;
		e.v[i] = my;
		g.g[mx].push_back(make_pair(my,i));
		g.g[my].push_back(make_pair(mx,i));
	}
	is.close();
	return true;
}

bool read_edges(edges & e, char * input){
	ifstream is(input);
	if(!is.is_open()){
		cout << "Error\nCould not open " << input << endl;
		return false;
	}
	is >> e.n >> e.m;
	e.u.resize(e.m);
	e.v.resize(e.m);
	for(int i=0; i<e.m;++i){
		is >> e.u[i] >> e.v[i];
	}
	is.close();
	return true;
}

void split_string(string s,char delim, vector<string> & elems){
	stringstream ss(s);
	string item;
	while(getline(ss,item,delim)){
		elems.push_back(item);	
	}
}

bool read_graph_coloring(graph & g, edges & e, int &nb, vector<int> &col, char * input, int k){
	assert(0 <= k && k < 7);
	ifstream is(input);
	if(!is.is_open()){
		cout << "Error\nCould not open " << input << endl;
		return false;
	}
	map<int,int> m;
	string line;

	is >> g.n >> g.m;
	e.n = g.n;
	e.m = g.m;
	col.resize(g.n);
	g.g.resize(g.n);
	
	getline(is,line);
	
	int c,j=0;
	for(int i=0;i<g.n;++i){
		getline(is,line);
		vector<string> parts;	
		split_string(line,',',parts);
		
		assert(parts.size() == 9);

		c = atoi(parts[2+k].c_str());

		if(m.find(c) == m.end()){
			m[c] = j;
			++j;
		}
		col[i] = m[c];
	}

	nb = j;
	for(int i=0;i<g.m;++i){
		getline(is,line);
		vector<string> parts;	
		split_string(line,',',parts);
	
		//cout << i << " " << parts.size() << endl;
		assert(parts.size() == 11);
		
		int x = atoi(parts[0].substr(1,parts[0].size()).c_str());
		int y = atoi(parts[1].substr(1,parts[1].size()).c_str());
		g.g[x].push_back(y);
		g.g[y].push_back(x);
		e.u.push_back(x);
		e.v.push_back(y);
	}
	return true;
}

bool get_maxCover_and_id(const char * input, CovId & ci){
	ifstream is(input);
	if(!is.is_open()){
		cout << "Error\nCould not open " << input << endl;
		return false;
	}

	vector<double> & covers = ci.covs;
	vector<double> & identities = ci.ids;
	
	string line;
	getline(is,line);
	while(getline(is,line)){
		vector<string> parts;
		split_string(line,'\t',parts);
	
		assert(parts.size() == 12);
		double cover = 0.0;
		for(int i=0;i<2;++i){
			int vals[3];
			for(int j=0;j<3;++j){
				vals[j] = atoi(parts[2+4*i+j].c_str());
			}
			cover = max(cover,(double)(abs(vals[0]- vals[1]) + 1)/(double)(vals[2]));
		}
		covers.push_back(cover);
		identities.push_back(atof(parts[10].c_str())/100.0);
	}
	return true;
}

bool create_gephi_coloring(edges & e, const char * input, 
								int nbCommunities, vector<int>& assign){
	ofstream of(input);
	if(!of.is_open()){
		cout << "Error\nCould not open " << input << endl;
		return false;
	}
	
	int j=0,n = e.n;
	map<int,int> m;
	vector<Color> colors;
	generate_colors(colors,nbCommunities,1);

	of << "nodedef>name INF,color VARCHAR" << endl;

	for(int i=0;i<n;++i){
		if(m.find(assign[i]) == m.end()){
			m[assign[i]] = j;
			++j;
		}
		int cur = m[assign[i]];
		of << i << ",'" << colors[cur] << "'" << endl;
	}

	of << "edgedef>node1 INT,node2 INT" << endl;

	for(int i=0;i<e.m;++i){
		of << e.u[i] << "," << e.v[i] << endl;
	}

	cout << j << " " << nbCommunities << endl;

	assert(j == nbCommunities);

	of.close();

	return true;
}

