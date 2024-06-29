#include "output_command.h"

const int Sz = 1e6;

int A[Sz];
int B[Sz];

int GetSortName(const string &sortName)
{
    if (sortName == "selection-sort") return 0;
    if (sortName == "insertion-sort") return 1;
    if (sortName == "bubble-sort") return 2;
    if (sortName == "shaker-sort") return 3;
    if (sortName == "shell-sort") return 4;
    if (sortName == "heap-sort") return 5;
    if (sortName == "merge-sort") return 6;
    if (sortName == "quick-sort") return 7;
    if (sortName == "counting-sort") return 8;
    if (sortName == "radix-sort") return 9;
    if (sortName == "flash-sort") return 10;

    return -1;
}

int GetInputOrder(const string &inputOrder)
{
    if (inputOrder == "-rand") return 0;
    if (inputOrder == "-nsorted") return 1;
    if (inputOrder == "-rev") return 3;
    if (inputOrder == "-sorted") return 2;

    return -1;
}

int GetOutputParameter(const string &outputParameter)
{
    if (outputParameter == "-time") return 1;
    if (outputParameter == "-comp") return 2;
    if (outputParameter == "-both") return 3;

    return -1;
}

void OutputRuntime(int a[], int inputSize, const string &sortName, int command_type)
{
    if (command_type == 0) cout << "Running time: ";
    else cout << " | ";

    switch (GetSortName(sortName))
    {
        case 0:
        {
            cout << funcRunTime(SelectionSort, a, inputSize);
            break;
        }

        case 1:
        {
            cout << funcRunTime(InsertionSort, a, inputSize);
            break;
        }

        case 2:
        {
            cout << funcRunTime(bubbleSort, a, inputSize);
            break;
        }

        case 3:
        {
            cout << funcRunTime(shakerSort, a, inputSize);
            break;
        }

        case 4:
        {
            cout << funcRunTime(ShellSort, a, inputSize);
            break;
        }

        case 5:
        {
            cout << funcRunTime(HeapSort, a, inputSize);
            break;
        }

        case 6:
        {
            cout << funcRunTime(MergeSort, a, inputSize);
            break;
        }

        case 7:
        {
            cout << funcRunTime(quickSort, a, 0, inputSize);
            break;
        }

        case 8:
        {
            cout << funcRunTime(CountingSort, a, inputSize);
            break;
        }

        case 9:
        {
            cout << funcRunTime(radixSort, a, inputSize);
            break;
        }

        case 10:
        {
            cout << funcRunTime(flashSort, a, inputSize);
            break;
        }

        default:
            break;
    }

    if (command_type != 0)
        cout << "\n";
}

void OutputComparisons(int a[], int inputSize, const string &sortName, int command_type)
{
    if (command_type == 0) cout << "Comparisons: ";
    else cout << " | ";


    long long count_compare = 0;
    switch (GetSortName(sortName))
    {
        case 0:
        {
            SelectionSort(a, inputSize, count_compare);
            break;
        }

        case 1:
        {
            InsertionSort(a, inputSize, count_compare);
            break;
        }

        case 2:
        {
            bubbleSort(a, inputSize, count_compare);
            break;
        }

        case 3:
        {
            shakerSort(a, inputSize, count_compare);
            break;
        }

        case 4:
        {
            ShellSort(a, inputSize, count_compare);
            break;
        }

        case 5:
        {
            HeapSort(a, inputSize, count_compare);
            break;
        }

        case 6:
        {
            MergeSort(a, 0, inputSize - 1, count_compare);
            break;
        }

        case 7:
        {
            quickSort(a, 0, inputSize, count_compare);
            break;
        }

        case 8:
        {
            CountingSort(a, inputSize, count_compare);
            break;
        }

        case 9:
        {
            radixSort(a, inputSize, count_compare);
            break;
        }

        case 10:
        {
            flashSort(a, inputSize, count_compare);
            break;
        }

        default:
            break;
    }

    cout << count_compare;

    if (command_type != 0)
        cout << "\n";
}

void OutputArray(const std::string &filePath, int a[], int inputSize)
{
    ofstream out (filePath);

    if (!out.is_open())
        return;

    out << inputSize << '\n';

    for (int i = 0; i < inputSize; i++)
        out << a[i] << " ";

    out << '\n';

    out.close();
}

void CopyArray(int a[], int b[], int inputSize)
{
    for (int i = 0; i < inputSize; i++)
        a[i] = b[i];
}

void OutputParameter(int type, int A[], int inputSize, const string &sortName)
{
    if (type == 1)
        OutputRuntime(A, inputSize, sortName, 0);
    else if (type == 2)
        OutputComparisons(A, inputSize, sortName, 0);
    else
    {
        OutputRuntime(A, inputSize, sortName, 0);
        CopyArray(A, B, inputSize); // unsorted array
        OutputComparisons(A, inputSize, sortName, 0);
    }
}

void AlgorithmMode(int argc, char *argv[])
{
    if (GetSortName(argv[2]) == -1 || GetOutputParameter(argv[argc - 1]) == -1)
        return;

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << Name[GetSortName(argv[2])] << '\n';

    if (argc == 5)
    {
        string filePath = string(argv[3]);

        if (filePath[0] >= '0' && filePath[0] <= '9') // command 3
        {
            int inputSize = stoi(filePath);
            cout << "Input size: " << inputSize << '\n';
            cout << '\n';

            int type = GetOutputParameter(string(argv[argc - 1]));

            for (int i = 0; i < 4; i++)
            {
                cout << "Input order: " << DataOrder[i] << "\n";
                cout << "-------------------------------------------" << '\n';

                GenerateData(B, inputSize, i);
                CopyArray(A, B, inputSize); // unsorted array

                string digit = to_string(i + 1);
                OutputArray("input_" + digit + ".txt", A, inputSize);

                OutputParameter(type, A, inputSize, string(argv[2]));

                cout << "\n";
            }
        }
        else // Command 1
        {
            cout << "Input file: " << filePath << '\n';
            ifstream inp (filePath);
            if (!inp.is_open())
                return;


            int inputSize = 0;
            inp >> inputSize;
            cout << inputSize << "\n";

            cout << "Input size: " << inputSize << '\n';

            for (int i = 0; i < inputSize; i++)
                inp >> B[i];

            CopyArray(A, B, inputSize);

            cout << "-------------------------------------------" << '\n';

            int type = GetOutputParameter(argv[argc - 1]);

            OutputParameter(type, A, inputSize, string(argv[2]));

            OutputArray("output.txt", A, inputSize);
            inp.close();
        }
    }
    else if (argc == 6) // Command 2
    {
        int inputSize = stoi(string(argv[3]).c_str());
        cout << "Input size: " << inputSize << '\n';

        int typeOrder = GetInputOrder(string(argv[4]));
        cout << "Input order: " << DataOrder[typeOrder] << '\n';

        cout << "-------------------------------------------" << '\n';

        GenerateData(B, inputSize, typeOrder);
        CopyArray(A, B, inputSize);

        OutputArray("input.txt", A, inputSize);

        int type = GetOutputParameter(string(argv[argc - 1]));

        OutputParameter(type, A, inputSize, string(argv[2]));

        OutputArray("output.txt", A, inputSize);
    }
}

void ComparisonMode(int argc, char *argv[])
{
    if (GetSortName(argv[2]) == -1 || GetSortName(argv[3]) == -1)
        return;

    cout << "COMPARE MODE\n";
    cout << "Algorithm: ";
    cout << Name[GetSortName(argv[2])] << " | " << Name[GetSortName(argv[3])] << "\n";

    if (argc == 5) // Command 4
    {
        string filePath = string(argv[argc - 1]);
        cout << "Input file: " << filePath << "\n";

        ifstream inp(filePath);

        if (!inp.is_open())
            return;

        int inputSize = 0;
        inp >> inputSize;

        for (int i = 0; i < inputSize; i++)
            inp >> B[i];

        CopyArray(A, B, inputSize);

        cout << "Input size: " << inputSize << '\n';
        cout << "-------------------------------------------" << '\n';

        OutputRuntime(A, inputSize, argv[2], 0);

        CopyArray(A, B, inputSize);
        OutputRuntime(A, inputSize, argv[3], 1);

        CopyArray(A, B, inputSize);
        OutputComparisons(A, inputSize, argv[2], 0);

        CopyArray(A, B, inputSize);
        OutputComparisons(A, inputSize, argv[3], 1);

        inp.close();
    }
    else // command 5
    {
        int inputSize = stoi(string(argv[argc - 2]));
        int typeOrder = GetInputOrder(string(argv[argc - 1]));

        cout << "Input size: " << inputSize << "\n";
        cout << "Input order: " << DataOrder[typeOrder] << "\n";
        cout << "-------------------------------------------" << '\n';

        GenerateData(B, inputSize, typeOrder);

        CopyArray(A, B, inputSize);
        OutputRuntime(A, inputSize, argv[2], 0);

        CopyArray(A, B, inputSize);
        OutputRuntime(A, inputSize, argv[3], 1);

        CopyArray(A, B, inputSize);
        OutputComparisons(A, inputSize, argv[2], 0);

        CopyArray(A, B, inputSize);
        OutputComparisons(A, inputSize, argv[3], 1);
    }
}
