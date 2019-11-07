#include <iostream>
#include <vector>
//#include <algorithm>
//#include <iterator>

#include "forwardlist.h"

int main() {
    {
        ForwardList<int> l = {1};

        l.top();

//        std::vector<int> a(1, 2, 3);
//        std::vector<int> c = {1, 3};

//        std::cout << "a: " << a.size() << "\n c: " << c.size() << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
