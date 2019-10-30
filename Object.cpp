#include <iostream>

using namespace std;

/** Testing object **/
class Object {
    
    int num;
    int sum;
    double sam;
    
    public:
        Object() {
            
        }
        Object(int num) {
            sum = num;
        }
        void print() {
            cout << " This is an object " << endl;
        }
};