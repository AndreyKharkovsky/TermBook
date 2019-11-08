#include <iostream>
#include <algorithm>

#include "forwardlist.h"

int main() {
    {
        ForwardList<int> l = {1,2,3,4};

        ForwardList<int>::ForwardList_iterator it = l.begin();

        for (auto it = l.begin(); it != l.end(); ++it) {
            std::cout << *it << std::endl;
        }

        std::cout << std::distance(l.begin(), l.end()) << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
