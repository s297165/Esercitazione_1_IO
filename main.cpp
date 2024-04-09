#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double maps(double x)
{
    double y = 3.0/4*x-7.0/4;
    return y;
}
int main()
{
    ifstream inFile("data.csv");
    if (inFile.fail())
    {

        std::cerr <<"File does not exist"<< std::endl;
    };

    ofstream outFile("result.csv");
    double x;
    double mean=0.0;
    int cont=0;
    outFile << "# N mean " << scientific << setprecision(16)<< endl;
    while (inFile >> x)
    {
        mean= (mean*cont+maps(x))/(cont +1);
        cont++;
        outFile << cont << " " << mean << endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}



