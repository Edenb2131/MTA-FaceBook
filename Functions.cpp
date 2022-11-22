
#include "Functions.h"
#define LEN 100

void checkMemoryAllocation(void* ptr) {
    if (ptr == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
}






