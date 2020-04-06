#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T> void print(T s){
    cout << "A template print(): "  << s << endl;
}
template <class C> void print2(double d){
    cout << "Template print2() with a constructor: " << C(d) << endl;
}
void print(int i){
    cout << "Not a template print(): " << i << endl;
}

int main() {

    print<string>("Hello");
    print<int>(5);

    print (4);
    print<>(4);

    print2<double>(5.4);
    return 0;
}
