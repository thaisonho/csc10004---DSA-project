#include "output_command.h"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        if (argc <= 2) throw -1;

        if (std::string(argv[1]) == "-a")
        {
            bool check = AlgorithmMode(argc, argv);
            if (check == false)
                 throw -1;
        }
        else if (std::string(argv[1]) == "-c")
        {
            bool check = ComparisonMode(argc, argv);

            if (check == false)
                 throw -1;
        }
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
