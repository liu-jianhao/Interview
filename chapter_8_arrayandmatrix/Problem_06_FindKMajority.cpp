#include <iostream>
#include <vector>

using namespace std;

void prinHalfKMajor(vector<int> arr) {
    int cand = 0; // 候选
    unsigned int times = 0;
    for(unsigned int i = 0; i != arr.size(); i++) {
        if(times == 0) { // 没有候选
            cand = arr[i];
            times = 1;
        } else if(arr[i] == cand) {
            times++;
        } else {
            times--;
        }
    }

    // 检查候选出现的次数是否超过一半
    times = 0;
    for(unsigned int i = 0; i != arr.size(); i++) {
        if(arr[i] == cand) {
            times++;
        }
    }
    if(times > arr.size() / 2) {
        cout << cand << endl;
    } else {
        cout << "no such number." << endl;
    }
}


void printArr(vector<int> arr) {
    for(auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 1, 2, 3, 1, 1, 2, 1 };
    printArr(arr);
    prinHalfKMajor(arr);
    return 0;
}
