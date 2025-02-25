#include <iostream>
#include <fstream>

using namespace std;

class FileHandler {
public:
    ofstream file;
    FileHandler(const string& filename) {
        file.open(filename);
        if (!file) throw runtime_error("File could not be opened!");
    }
    ~FileHandler() {
        file.close();
        cout << "File closed automatically.\n";
    }
};

int main() {
    try {
        FileHandler fh("example.txt");
        fh.file << "Writing to file\n";
        throw runtime_error("An error occurred!");
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
