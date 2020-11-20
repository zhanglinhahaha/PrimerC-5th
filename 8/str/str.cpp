#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

vector<PersonInfo> people;

void read() {
    string line,word;
    while(getline(cin, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        cout << info.name <<endl;
        while(record >> word) {
            info.phones.push_back(word);
            cout<<word<<endl;
        }
        people.push_back(info);
    }
}

int main() {
    read();
    return 0;
}
