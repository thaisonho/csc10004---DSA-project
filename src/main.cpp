#include "output_command.h"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        if (argc <= 2) throw -1;

        if (std::string(argv[1]) == "-a") AlgorithmMode(argc, argv);
        else if (std::string(argv[1]) == "-c") ComparisonMode(argc, argv);
        else throw -1;
    }
    catch(int x)
    {
        if (x == -1)
        {
            std::cout << "Error: Invalid arguments!" << std::endl;
        }
    }

    return 0;
}
