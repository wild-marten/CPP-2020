//Wiktoria Kuna 316418
#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

const vector<pair<int, string>> rzym = 
{{1000, "M"}, {900, "CM"}, {500, "D"}, 
{400, "CD"}, {100, "C"}, {90, "XC"}, 
{50, "L"}, {40, "XL"}, {10, "X"}, 
{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

string bin2rom(int x)
{
    if(x < 1 or x > 3999)
        throw invalid_argument("Number out of range");

    string romNum;

    int j=0;
    while(x > 0)
    {
        while(x - rzym[j].first >= 0)
        {
            x -= rzym[j].first;
            romNum += rzym[j].second;
        }
        j++;
    }
    return romNum;
}

int main(int argc, char **argv)
{
    try
    {
        if(argc == 1)
            throw invalid_argument("Run program with at least one parameter");

        for(int i = 1; i < argc; i++)
        {
            string str = bin2rom(stoi(argv[i]));
            cout << str <<endl;
        }
    }
    catch(const exception &e)
    {
        clog << e.what()<<endl;
    }
}