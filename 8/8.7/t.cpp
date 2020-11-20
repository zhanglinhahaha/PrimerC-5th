#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        return -1;
    }
    std::ifstream fin;
    std::ofstream fout;
    fout.open(argv[2], std::ofstream::app);
    fin.open(argv[1]);
    std::string item;
    if(fin && fout) {
        while(!fin.eof() && fin.peek() != EOF) {
            getline(fin, item);
            fout << item << "\n";
        }
    }
    fin.close();
	fout.close();
    return 0;
}
