#include <iostream>
#include "Properties.h"

using namespace std;
using namespace Properies;

struct Obj {

    Property<int, ReadWrite> intProperty;

    Property<string, ReadWrite> strProperty;

    Obj() : intProperty(10, [] (const int& value) { cout << "read value: " << value << endl; }),
            strProperty(string("value str"), [] (const string& value) {}, [] (const string& value) { cout << "write value: " << value << endl; }) {}

};

int main() {
    Obj obj;

    obj.intProperty = 10;
    cout << obj.intProperty << endl;

    obj.intProperty = 20;
    cout << obj.intProperty << endl;

    obj.strProperty = string("hello, world!");
    cout << (string)obj.strProperty << endl;

    /*
     * read value: 10
     * 10
     * read value: 20
     * 20
     * write value: hello, world!
     * hello, world!
     */

    return 0;
}