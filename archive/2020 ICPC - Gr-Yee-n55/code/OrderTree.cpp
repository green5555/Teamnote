  
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// multiset 사용시 pair<원소값, cnt++>
int main(){
	ordered_set X;
	//insert(a) : a를 삽입한다
	X.insert(1); // 0번째 원소 = 1
	X.insert(2); // 1번째 원소 = 2
	X.insert(4); // 2번째 원소 = 4
	X.insert(8); // 3번째 원소 = 8
	X.insert(16); // 4번째 원소 = 16
	//iterator
	for(auto it = X.begin(); it != X.end(); ++it)
		cout << *it << ' ';
	cout << '\n'; // 1 2 4 8 16
	//find_by_order(a) : a번째 원소의 iterator를 반환한다.
	//단, a > X.size()면 X.end()를 반환한다.
	cout<<*X.find_by_order(1)<<endl; // 2
	cout<<*X.find_by_order(2)<<endl; // 4
	cout<<*X.find_by_order(4)<<endl; // 16
	cout<<(X.end()==X.find_by_order(6))<<endl; // true
	//order_of_key(a) : a보다 작은 원소의 개수를 반환한다.
	cout<<X.order_of_key(-5)<<endl;  // 0
	cout<<X.order_of_key(1)<<endl;   // 0
	cout<<X.order_of_key(3)<<endl;   // 2
	cout<<X.order_of_key(4)<<endl;   // 2
	cout<<X.order_of_key(400)<<endl; // 5
}