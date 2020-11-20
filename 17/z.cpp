#include <iostream>
#include <string>
#include <regex>

using namespace std;

void search() {
    regex r("[[:alpha:]]+\\.(cpp|cxx|cc)$", regex::icase);//icase忽略大小写
    smatch results;
    string filename;
    while(cin >> filename)
        if(regex_search(filename, results, r))
            cout << results.str() << endl;
}

void replace() {
    string phone = "(\\()?(\\d{3}(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4}))";
    regex r(phone);
    smatch m;
    string s;
    string fmt = "$2.$5.$7";//将号码格式改为ddd.ddd.dddd
    while(getline(cin, s))
        cout << regex_replace(s, r, fmt) << endl;
    return 0;
}

int main() {
    string pattern("[^c]ei");
    //regex使用的正则表达式语言是ECMAScript，在ECMAScript中[[::alpha:]]能匹配任意字母
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    string test_str("receipt freind theif receive");
    if(regex_search(test_str, results, r))
        cout << results.str() << endl;
    //search();
    for(sregex_iterator it(test_str.begin(), test_str.end(), r), end_it; it != end_it; ++it)
        cout << it->str() << endl;
    for(sregex_iterator it(test_str.begin(), test_str.end(), r), end_it; it != end_it; ++it) {
        auto pos = it->prefix().length();
        pos = pos > 40 ? pos - 40 : 0;
        cout << it->prefix().str().substr(pos)
             << "\n\t\t>>> " << it->str() << " <<<\n"
             << it->suffix().str().substr(0, 40)
             << endl;
    }
    return 0;
}
