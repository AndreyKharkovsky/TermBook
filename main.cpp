#include <iostream>
#include <vector>
//#include <algorithm>
//#include <iterator>

#include "forwardlist.h"

int main() {
    {
        ForwardList<int> l = {1,2,3,4,5,6};

        int a = l.top();

		auto it = l.begin();

        std::cout << a << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
