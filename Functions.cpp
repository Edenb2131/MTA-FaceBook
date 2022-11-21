
#include "Functions.h"
#define LEN 100

void checkMemoryAllocation(void* ptr) {
    if (ptr == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
}

//Getting a string with unknown length from the user
char* getDynamicString() {
    char* str = new char[LEN];
    checkMemoryAllocation(str);
    cin.getline(str, LEN);
    return str;

 ///// Another option: /////
 ///// This is a function that gets a string from the user and returns it as a dynamic string. /////
//    int n=1;
//    char *a = new char[LEN],c=getchar();
//    while(true)
//    {
//        if(c == '\n' || c == EOF){
//            break;
//        }
//        a[n-1]=c;
//        c=getchar();
//        n++;
//    }
//    char* str = new char[n];
//    checkMemoryAllocation(str);
//    strcpy(str,a);
//    delete[] a;
//    return str;

}


