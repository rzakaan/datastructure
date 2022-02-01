#include <iostream>
#include <stack>

using namespace std;
int main(){
    cout << "std::stack " << endl;
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty()) {
        cout << "stack top   : " << s.top() << endl;
        s.pop();
    }
}