#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class Interval {
    public:
        int start;
        int end;

        Interval() {}        

        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }


        bool operator < (const Interval& input) const {
            return this->start < input.start;
        }
};

class MyComp {
    public:
        Interval interval;

        //minHeap
        bool operator () (const Interval& l, const Interval& r) const {
            return l.end > r.end;
        }
};

class Solution {
    public:
        int getMeetingRoom(vector<Interval> input) {
            //edge case
            if (input.empty()) return 0;            

            //sorted by start time
            sort(input.begin(), input.end());
            
            int room = 0;
            int ans = 0;
            priority_queue<Interval, vector<Interval>, MyComp> minHeap;
            for (int i = 0; i < input.size(); i++) {
                while (!minHeap.empty() && input[i].start >= minHeap.top().end) {
                    room--;
                    minHeap.pop();
                }

                room++;
                minHeap.push(input[i]);
                ans = max(ans, room);        
            }

            return ans;
        }

        int getMR(vector<Interval> input) {
            //edge case
            if (input.empty()) return 0;            

            map<int, int> roomCnt;
            for (Interval interval : input) {
                roomCnt[interval.start]++;//use room
                roomCnt[interval.end]--;//release room
            }

            int ans = 0;
            int room = 0;
            for (auto& it : roomCnt) {
                room += it.second;
                ans = max(ans, room);
            }

            return ans;
        }
};

int main() {
    vector<Interval> input;
    Solution s;
    input.push_back(Interval(1,2));
    input.push_back(Interval(1,3));
    input.push_back(Interval(2,5));
    input.push_back(Interval(3,5));
    input.push_back(Interval(3,6));
    input.push_back(Interval(7,7));
    int ans = s.getMeetingRoom(input);
    cout<<"meetingRoom="<<ans<<endl;

    int mans = s.getMR(input);
    cout<<"meetingRoom2="<<ans<<endl;
    return 0;
}
