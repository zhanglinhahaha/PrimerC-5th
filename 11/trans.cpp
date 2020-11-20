#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;
    string key;
    string value;
    while(map_file >> key && getline(map_file, value)) {
        if(value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for key: " + key);
    }
    return trans_map;
}

const string & transform(const string &s, const map<string, string> &m) {
    auto map_it = m.find(s);
    if(map_it != m.end())
        return map_it->second;
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file);
    string text;
    while(getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while(stream >> word) {
            if(firstword)
                firstword = false;
            else
                cout << " ";
            if(word[word.size()-1] == ',' || word[word.size()-1] == '.' || word[word.size()-1] == '?' || word[word.size()-1] == '!') word = word.substr(0, word.size() - 1);
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

void test33() {
    ifstream fmap("map.txt");
    ifstream finput("input.txt");
    word_transform(fmap, finput);
}

int main() {
    test33();
    return 0;
}
