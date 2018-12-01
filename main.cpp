#include <iostream>
#include <vector>

using namespace std;

int mList[1000000] = {0};
vector<int> mInputs;
int i = 0;
int a = 0;
int result = -1;

void Puzzle01() {
    while(cin >> a)
        i+=a;
    cout << i;
}

void Puzzle02() {
    mList[500000] = 1;

    while (cin >> a) {
        mInputs.push_back(a);
    }

    while(result == -1) {
        for (int item : mInputs) {
            i += item;
            mList[i+500000]++;
            if(mList[i+500000] > 1) {
                result = i;
                break;
            }
        }
    }
    cout << result;
}

int main() {
    //Puzzle01();
    Puzzle02();

    return 0;
}