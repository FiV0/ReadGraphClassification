#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#include <map> 

using namespace std;

int main(int , char * argv []){
	ifstream is(argv[1]);
	ofstream of(argv[2]);
	if(!is.is_open()){
		cout << "Error\nCould not open " << argv[1] << endl;
		return EXIT_FAILURE;
	}

	is.ignore(1024,'\n');

	map<int,int> m;
	int x,y,c=0,qs,qe,ql,ss,se,sl,ig;
	double id,ig2;
	while(is >> x >> y >> qs >> qe >> ql >> ig >> ss >> se >> sl >> ig >> id >> ig2){
		if(m.find(x) == m.end()){
			m[x] = c;
			++c;
		}
		if(m.find(y) == m.end()){
			m[y] = c;
			++c;
		}
		double cover = max((double)(abs(qs - qe)+1)/(double)ql,(double)(abs(ss-se)+1)/(double)sl);
		of << m[x] << " " << m[y] << " " << cover << " " << id << endl;
	}
	for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it){
		of << it->first << " " << it->second << endl;
	}
	
	return 0;
}
