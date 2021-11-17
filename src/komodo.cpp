#include "program.h"

int main(int argc, char **argv)
{
    // Only program name
    if (argc <= 1)
    {
        std::cout << "Komodo Interpreter Version 0.0.1" << std::endl;
        std::cout << std::endl;
        std::cout << "Usage: " << std::endl;
        std::cout << "   kom <file_path>" << std::endl;
        return 0;
    }

    std::string entry_point_file = argv[1];

    Program program(entry_point_file);

    program.simulate();
}