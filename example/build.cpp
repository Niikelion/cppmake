#include "CppMake/Project.hpp"
#include "CppMake/Application.hpp"

using namespace std;

int main() {
    Project project("test");

    project.create<Application>("test").addSources({
        "main.cpp"
    });
}