#include <iostream>
#include <fstream>

void eval(const std::string& code) {

}

void repl() {

    std::string code;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, code);
        eval(code);
    }
}

void read(const std::string& path) {

    std::string code;

    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << path << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        code += line + "\n";
    }
    file.close();

    eval(code);
}

int main(int argc, char** argv) {

    if (argc == 1) repl();
    else read(argv[1]);

    return 0;
}
