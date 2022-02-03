#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;
void show(std::vector<int> lst) {
    for (int i = 0; i < lst.size(); i++) {
        std::cout << lst[i] << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    std::vector<int>::const_iterator itr;
    
    vec.push_back(77);
    vec.push_back(55);
    vec.push_back(22);
    vec.push_back(44);
    vec.pop_back();

    itr = vec.end();
    auto ptr_prev = prev(itr, 1);

    itr = vec.begin();
    auto ptr_next = next(itr, 1);

    cout << "vector size : " << vec.size() << endl;
    cout << "vector at   : " << vec.at(0) << endl;
    cout << "vector prev : " << *ptr_prev << endl;
    cout << "vector next : " << *ptr_next << endl;

    show(vec);

    for(itr = vec.begin(); itr != vec.end(); ++itr) {        
        std::cout << *itr << std::endl;
    }

    // after c++11
    for(const auto& item : vec) {
        std::cout << item << std::endl;
    }
}