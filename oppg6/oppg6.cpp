/**
 * OPPG 6
 * 
 * Leking med strings. Declare og bruke strings og sammenligne osv
 * 
 * @file oppg6.cpp
 * @author Richard Frøyland
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "Teststring1";

    string s2 = ("String2");

    char s3[] = {"String3"};

    string inputstring;

    cout << s1 << endl;

    cout << s1 << s2 << "\n";

/*     cout << "Enter a string: ";
    getline(cin, inputstring);
    cout << ("\n");
    cout << inputstring << endl; */

    s1.append(s2);
    cout << s1 << endl;

    string assignstring;

    assignstring.assign(s2);

    cout << assignstring << endl;

    if (!s2.compare(s1))
    {
        cout << "Lik string";
    }
    else 
    {
        cout << "ulik string";
    }

    if (!s2.compare(s3))
    {
        cout << "Lik string";
    }
    else 
    {
        cout << "ulik string";
    }

    cout << endl << endl;

    cout << s1.length() << endl;
    
    cout << s2.length() << endl;

    cout << s1.max_size() << endl;

    s1.resize(200, 's');

    cout << s1 << endl;
    return 0;
}