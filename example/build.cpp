#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream output("generated.cmake");

    output << R"TXT(
add_executable(Main main.cpp)
)TXT";
    output.close();
    cout << "Generated\n";
}