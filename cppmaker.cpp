#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fi("/coding/code/format");
    string s(argv[1]);
    ofstream fo(s+".cpp");
    while (getline(fi,s)) 
        fo << s << endl;
    fo << endl << endl;
    fo << "int main() {" << endl; 
    if (argc > 2)
    fo << "    freopen(\"" << argv[2] << "\",\"r\",stdin);" << endl;
    if (argc > 3)
    fo << "    freopen(\"" << argv[3] << "\",\"w\",stdout);" << endl << endl;
    fo << endl << "    return 0;" << endl << "}";
    fi.close();
    fo.close();
    cout << "Thank for using cppmaker 3.0\n";
    return 0;
}
