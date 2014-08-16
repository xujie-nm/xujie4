#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, const char *argv[])
{
    ofstream fos;
    fos.open("test.txt");
    if(!fos)
    {
        cout << "open fail" << endl;
        return 0;
    }

    cout << "ok" << endl;

    fos.close();
    return 0;

}
