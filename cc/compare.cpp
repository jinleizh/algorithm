#include <iostream>
#include <math.h>
using namespace std;

class Solution {
    public:
        bool compare(const string l, const string r) {
            //edge case
            if (l.empty() || r.empty()) return false;

            int left = transToInt(l, 2);
            cout<<"left="<<left<<endl;
            int right = transToInt(r, 16);
            cout<<"right="<<right<<endl;
            if (-1 == left || -1 == right) return false;
            return left == right;
        }

        int transToInt(string str, int base) {
            //edge case
            if (base != 2 && base != 16) return -1;
            if (str.empty()) return -1;
            
            int val = 0;
            for (int i = 0; i < str.length(); i++) {
                char c = str[i];
                if (2 == base) {
                    if (c != '0' && c != '1') return -1;
                    val += (c - '0') * pow(2, str.length() - 1 - i);
                }

                if (16 == base) {
                    int t = getVal(c);
                    if (-1 == t) return -1;
                    val += t * pow(16, str.length() - 1 - i);
                }
            }
    
            return val;
        }

        int getVal(char c) {
            if (c >= '0' && c <= '9') return c - '0';
            if (c >= 'a' && c <= 'f') return 10 + c - 'a';
            if (c >= 'A' && c <= 'F') return 10 + c - 'A';
            return -1;
        }
};

int main() {
    string bin = "11010101";
    string hex = "55";
    Solution s;
    bool ans = s.compare(bin, hex);
    if (ans) {
        cout<<"equal"<<endl;
    } else {
        cout<<"not equal"<<endl;
    }
    return 0;
}
