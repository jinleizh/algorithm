#include <iostream>
#include <vector>
using namespace std;

void output(vector<int>& v) {
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout<<*it<<" ";
	}
}

void quickSort(vector<int>& v, int s, int e) {
	output(v);
	cout<<endl;

	int tmp = 0;
	if(s >= e) return;

	int i = s;
	for(int k=s;k<=e;k++) {
		if(v[k]<=v[e]) {
			tmp = v[k];
			v[k]=v[i];
			v[i++]=tmp;
		}
	}

	quickSort(v, s, i-2);
	quickSort(v, i,e);
}

int main(int argc, char* argv[]) {
	int a[] = {10, 4, 5, 2, 1, 19, 3, 5, 7};
	vector<int> v(a, a+sizeof(a)/sizeof(int));
	quickSort(v, 0, v.size()-1);
	output(v);
	cout<<endl;
	return 0;
}
