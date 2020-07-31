//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3390/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour == 12 ? 0 : hour;
        double hourAngle = 30.0 * hour + 0.50 * minutes;
        double minutesAngle = 6.0 * minutes;
        
        double diff1 = abs(hourAngle - minutesAngle);
        double diff2 = 360.0 - diff1;
        
        return diff1 < diff2 ? diff1 : diff2;
    }
};
//hour - angle =  30 * hour(0 if hour = 12, else hour) + minutes * (0.5) 
//minutes - angle = 6 * minutes