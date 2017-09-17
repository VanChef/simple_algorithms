#include <iostream>
#include <string.h>

using namespace std;
void UpperCase(char str[])
{
    int test = sizeof(str);//warning: sizeof on array function parameter will return size of 'char *' instead of 'char []'
    int test2 = sizeof(str[0]);

    cout << test << endl << test2 << endl;

    for (size_t i = 0; i < sizeof(str)/sizeof(str[0]); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= ('a' - 'A'); 
        }
    }
}

int main() {

    char str[] = "aBcDe";
    cout << "The length of str is " << sizeof(str)/sizeof(str[0]) << endl;
    UpperCase(str);
    cout << str << endl;

    return 0L;
}



