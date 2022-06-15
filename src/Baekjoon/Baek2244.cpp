#include<iostream>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;

//2244번 민코프스키 합
//Convex Hull(CCW(Counter Clock Wise)) 사용

typedef pair<long long, long long> Point2f;
Point2f a[1010];
Point2f b[1010];

//counter clock wise : 좌회전하는지 판단
//벡터 AB와 벡터 AC의 CW/CCW
// 0보다 크면 반시계방향으로 도는 것, 0보다 작으면 시계방향으로 도는 것
//int에 1LL을 곱해주면 long long으로 형변환을 쉽게 할 수 있음
int ccw(Point2f a, Point2f b, Point2f c) {
    long long res = a.x * b.y + b.x * c.y + c.x * a.y;
    res -= b.x * a.y + c.x * b.y + a.x * c.y;
    if (res > 0) return 1;          //시계 반대방향
    if (res) return -1;             //시계 방향
    return 0;                           //평면상
}

long long dist(Point2f a, Point2f b) {
    long long dx = 1LL*a.x - b.x;
    long long dy = 1LL * a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {

    vector<Point2f> arr;
    int aNum, bNum;
    int xTmp, yTmp;
    int pIdx = 0;
    cin >> aNum >> bNum;
    pIdx = aNum * bNum;
    for (int i = 0; i < aNum; i++) {
        cin >> xTmp >> yTmp;
        a[i].x = xTmp; a[i].y = yTmp;
    }
    for (int i = 0; i < bNum; i++) {
        cin >> xTmp >> yTmp;
        b[i].x = xTmp; b[i].y = yTmp;
    }
    //모든 가능성이 있는 점들 vector 제작
    for (int i = 0; i < aNum; i++) {
        for (int j = 0; j < bNum; j++) {
            arr.push_back(Point2f{ a[i].x + b[j].x,a[i].y + b[j].y });
        }
    }

    //arr의 최소 값을 찾아서 0번 자리와 바꿈(0번을 제일 작은 값으로 설정)
    swap(arr[0], *min_element(arr.begin(), arr.end()));
    //0번을 제외한 점들을 반시계 방향으로 정렬
    //[&]{}는 람다식으로써 해당 함수에따라서 sort를 할지 말지 결정함
    sort(arr.begin() + 1, arr.end(), [&](Point2f& a, Point2f& b) {
        int cw = ccw(arr[0], a, b);
        //cw가 0 이상이면 반시계 방향이고 true를 반환 0이면 false 반환, cw가 -1인 경우(시계 방향) if문을 들어오지 않음
        if (cw) return cw > 0;          
        return dist(arr[0], a) < dist(arr[0], b); //cw가 -1인 경우 기준점 arr[0]에서의 거리순으로 정렬
        });

    vector<Point2f> hull;
    for (int i = 0; i < arr.size();i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), arr[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(arr[i]);
    }
    cout << hull.size() << "\n";
    for (int i = 0; i < hull.size(); i++) {
        cout << hull[i].x << " " << hull[i].y << "\n";
    }

    return 0;
}