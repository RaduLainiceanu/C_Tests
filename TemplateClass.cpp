//
// Created by radu on 06.04.2020.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class postString{
private:
    static int objectCount;
    int id;
    string name;
public:
    postString():id(objectCount++), name(""){
        cout << "Empty postString has been created: id="<<this->id<<endl;
    }
    postString(string s):id(objectCount++), name(s){
        cout << "postString has been created: id="<<this->id<<", name="<<this->name<<endl;
    }
    /*postString& operator=(const postString &postString){

    }*/
    friend ostream& operator<<(ostream& os, const postString& ps);
};
int postString::objectCount=0;
ostream& operator<<(ostream& os, const postString& ps){
    os << "postString name:"<<ps.name<<", id:"<<ps.id;
    return os;
}

template<class T> class Test{
private:
    T obj;
public:
    Test(T obj){
        this->obj = obj;
    }
    Test(postString ps){
        std::ostringstream os;
        os << ps;
        this->obj = os.str();
    }
    void print(){
        cout << obj << endl;
    }
};


int main() {
    postString ps("Radu");
    Test<string> test1(ps);
    test1.print();

    vector<postString> vtr;
    auto it = vtr.insert(vtr.begin(), postString("str"));
    vtr.insert(it, postString("str2"));

    return 0;
}
