#include <bits/stdc++.h>
using namespace std;
 
random_device rand_dev;
mt19937 generator(rand_dev());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uniform_int_distribution<long long>  distr(1, 20);
    uniform_int_distribution<long long>  dq(1, 10);
    set<int> st;

    int n = distr(generator);
    for(int i=1; i<=n; i++) st.insert(distr(generator));

    cout<<st.size()<<endl;
    uniform_int_distribution<long long>  gg(1, st.size());

    for(int x : st) cout<<x<<' ';
    cout << endl;

    int q = dq(generator);
    cout<<q<<endl;
    while(q--){
        int l =  gg(generator);
        int r =  gg(generator);
        if(l>r) swap(l,r);
        int k = gg(generator);
        cout<< l << ' '<<r<<' '<<k<<endl;
    }
}
