/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            if (a.start != b.start) return a.start < b.start;
            return a.end < b.end;
        });

        Interval prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (prev.end > intervals[i].start) return false;
            prev = intervals[i];
        }

        return true;
    }
};
