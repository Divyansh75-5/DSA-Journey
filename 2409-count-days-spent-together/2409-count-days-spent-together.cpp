class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
          int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        string dates[] = {arriveAlice, leaveAlice, arriveBob, leaveBob};
        int d[4];

        for(int i = 0; i < 4; i++) {
            int m = stoi(dates[i].substr(0,2));
            int day = stoi(dates[i].substr(3,2));

            for(int j = 0; j < m-1; j++)
                day += days[j];

            d[i] = day;
        }

        int start = max(d[0], d[2]);
        int end = min(d[1], d[3]);

        return max(0, end - start + 1);
    }
};