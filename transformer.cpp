#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main(int , char * argv []){
	ifstream is(argv[1]);
	if(!is.is_open()){
		cout << "Error\nCould not open " << argv[1] << endl;
		return EXIT_FAILURE;
	}

	set<int> s;
	int x,y,c=0;
	while(is >> x >> y){
		s.insert(x);		
		s.insert(y);
		++c;
	}

	cout << s.size() << " " << c << endl;		

	return 0;
}
