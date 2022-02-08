#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>

std::string exec(const std::string& command) {

    char buffer[128];
    std::string result;

    // Open pipe to file
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "popen failed!";
    }

    // read till end of process:
    while (!feof(pipe)) {

        // use buffer to read and add to result
        if (fgets(buffer, 128, pipe) != nullptr)
            result += buffer;
    }

    pclose(pipe);
    return result;
}

int main() {
    int n,method;
    std::string prg, file1, file2;

    //тут має читатись
    //std::cin>>n>>prg>>file1>>file2;
    n = 10;
    method = 1;
    prg = "/mnt/d/UCU/AKS/Lab1_double_convert_to_str/cmake-build-debug/Lab1_double_convert_to_str";
    file1 = "file1.txt";
    file2 = "file2.txt";

    std::string s;
    s+=prg;
    s+=" " + std::to_string(method);
    s+=" " + file1;
    s+=" " + file2;

    //записує у файл file2.txt що у Lab1_script
    for(size_t i=0; i<n; i++){
        std::string new_s = exec(s);
        //std::cout<<new_s;
    }

    return 0;
}
