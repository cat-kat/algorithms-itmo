#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    std::vector<int> a(n);
    std::cin>>n;
    for(int i = 0; i < n; i++) {
        std::cin>>a[i];
    }
    std::cin>>m;
    for (int i=0; i<m; i++) {
        int el
        std::cin>>el;
        if(std::binary_search(a.begin(), a.end(), el)) {
            std::cout<<std::lower_bound(a.begin(), a.end(), el)<<" "<<std::upper_bound(a.begin(), a.end(), el)<<'/n';
        } else {
            cout<<"-1 -1"<<'/n';
        }
    }



}