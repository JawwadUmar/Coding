#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#include <bits/stdc++.h>
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set os;
    os.insert(1);
    os.insert(2);
    os.insert(3);

    // Find the order of an element (0-based)
    int order_of_2 = *os.find_by_order(1); // This returns 2

    // Find the number of elements less than a value
    int count_less_than_3 = os.order_of_key(3); // This returns 2

    cout<<order_of_2<<endl;

    return 0;
}
