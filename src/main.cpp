#include "output_command.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc <= 2)
        return 0;

    if (string (argv[1]) == "-a")
        AlgorithmMode(argc, argv);
    else if (string (argv[1]) == "-c")
        ComparisonMode(argc, argv);
    else
        cout << "Error!!! Valid Argument!!!\n";

    return 0;
}
