#include <iostream>
#include <vector>
using namespace std;

void output(vector<int>& v) {
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout<<*it<<" ";
	}
}

//递增排序
//排序第i个元素时, 判断前i-1个数是否大于它，如果大于则进行移位，直到找到比它小的数为止.
void insertSort(vector<int>& v) {
	int len = v.size();
	if(0 == len) return;

	for(int i=1; i<len; i++) {
		int k = v[i];
		int j = i-1;
		while(j>=0 && v[j] > k) {
			v[j+1] = v[j--];
		}
		v[j+1] = k;
	}
}

int main(int argc, char* argv[]) {
	int a[] = {10, 4, 5, 2, 1, 19, 3, 5, 7};
	vector<int> v(a, a+sizeof(a)/sizeof(int));
	insertSort(v);
	output(v);
	cout<<endl;
	return 0;
}
