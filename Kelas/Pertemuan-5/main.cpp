#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    cout << "pointer yang menunjuk ke suatu array"<< endl;
    int a[5] = {1,2,3,4,5};
    int (*aPtr)[5] = &a;
    for (int i =0; i <5; i++){
        cout << *aPtr <<endl;
        aPtr++;
    }
    cout << "Pointer yang menunjuk ";
    cout << "ke arah elemen array" <<endl;
    int b[5] = {1,2,3,4,5,};
    int *bPtr = b;
    for (int i = 0; i < 5; i++){
        cout << bPtr <<endl;
        // cout << *bPtr <<endl;
        bPtr++;
    }
}