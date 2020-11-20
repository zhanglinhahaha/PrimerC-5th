#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {
	vector<PersonInfo> people;
	string line, word;
	ifstream fin;
	fin.open("test.txt");
	while(!fin.eof() && fin.peek() != EOF) {
		PersonInfo info;
		getline(fin, line);
		istringstream record(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);	
	}
	for(auto p : people) {
		cout << p.name << endl;	
	}
	return 0;
}
