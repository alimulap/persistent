#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string.h>
#include <fstream>
#include <direct.h>

bool isCxxValidVersion(int version);

int mcn(int argc, char* argv[]) {
    std::string projectName = "MyProject";
    float cmakeVersion = 3.10f;
    int cxxVersionStandard = 17;

    if (argc == 1) {
        return 1;
    }
    else if (argc == 2) {
        return 1;
    }
    else if (argc == 3) {
        if (strcmp(argv[1], "--init") != 0) {
            return 1;
        }
        projectName = argv[2];
    }
    else if (argc > 3) {
        if (strcmp(argv[1], "--init") != 0) {
            return 1;
        }
        projectName = argv[2];
        if (argc % 2 == 0) {
            std::cout << "Something is wrong.\n";
            return 1;
        }
        for (int i = 3; i < argc; i += 2) {
            if (strcmp(argv[i],"-cxxv") == 0) {
                try { cxxVersionStandard = std::stoi(argv[i+1]); }
                catch(const std::invalid_argument& e) {
                    std::cout << "cpp version must be a number\n";
                    return 1;
                }
                if (!isCxxValidVersion(cxxVersionStandard))
                    return 1;
            } else if (strcmp(argv[i], "-cmv") == 0) {
                try { cmakeVersion = std::stof(argv[i+1]); }
                catch(const std::invalid_argument& e) {
                    std::cout << "cmake version must be a floating point number\n";
                    return 1;
                }
            } else {
                std::cout << "Something is wrong\n";
                return 1;
            }
        }
    }

    char currentDir[1024];
    if(_getcwd(currentDir, sizeof(currentDir)) == nullptr) {
        std::cout << "Something is wrong.\n";
        return 1;
    }
    std::string buildDir = std::string(currentDir) + "\\build";
    std::string srcDir = std::string(currentDir) + "\\src";
    if(_mkdir(buildDir.c_str()) == -1) {
        std::cout << "Cannot make build directory.\n";
        return 1;
    }
    if(_mkdir(srcDir.c_str()) == -1) {
        std::cout << "Cannot make src directory.\n";
        return 1;
    }
    
    std::ofstream outfile;
    outfile.open("./CMakeLists.txt");

    outfile << "cmake_minimum_required(VERSION " << cmakeVersion << ")\n"
               "project(" << projectName << ")\n"
               "\n"
               "set(CMAKE_CXX_STANDARD " << cxxVersionStandard << ")\n"
               "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
               "\n"
               "include_directories(include)\n"
               "\n"
               "file(GLOB SOURCES \"src/*.cpp\")\n"
               "\n"
               "add_executable(main ${SOURCES})\n" << std::endl;

    outfile.close();

    outfile.open("./src/main.cpp");

    outfile << "#include <iostream>\n"
               "\n"
               "int main() {\n"
               "\tstd::cout << \"Hello universe.\";\n"
               "}\n" << std::endl;

    outfile.close();

    std::system("cmake -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON");
    std::system("ninja -C .\\build");

    std::cout << "success.\n";

    return 0;
}

bool isCxxValidVersion(int version) {
    int validVersion[] = { 3, 11, 14, 17, 20 };
    for (int i : validVersion) {
        if (version == i) {
            return true;
        }
    }
    std::cout << "Invalid c++ version\n";
    return false;
}
