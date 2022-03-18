#include<iostream>

using namespace std;

int main() {
    
    int hour, minute;
    cin >> hour >> minute;
    int time;
    cin >> time;
    if ((time + minute)>=60) {
        int addHour = (time + minute) / 60;
        int afterMinute = (time + minute) % 60;
        hour += addHour;
        if (hour >= 24)    hour -= 24;
        cout << hour << " " << afterMinute;
    }
    else {
        cout << hour << " " << time + minute;
    }

    return 0;
}