#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

array<int,26> ASCII = {0};
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

void Puzzle03() {
    string s;
    int twice = 0;
    bool twiceFlag;
    int triple = 0;
    bool tripleFlag;
    while (getline(cin, s)) {
        twiceFlag = false;
        tripleFlag = false;
        ASCII.fill(0);
        for(auto c : s) {
            ASCII[c-97]++;
        }
        for(auto c : ASCII) {
            if(c == 2 && !twiceFlag) {
                twice++;
                twiceFlag = true;
            }
            if(c == 3 && !tripleFlag) {
                triple++;
                tripleFlag = true;
            }
        }
    }

    cout << twice * triple;
}

void Puzzle04() {
    string s;
    vector<string> boxID;
    int mostCommon = 0;
    string commonLetters = "";
    while (getline(cin, s)) {
        boxID.push_back(s);
        if(boxID.size() > 1) {
            for(int i=0; i<boxID.size() - 1; i++) {
                int similarity = 0;
                string sameLetters = "";
                for(int j=0; j<s.length(); j++) {
                    if(s[j] == boxID[i][j]) {
                        similarity++;
                        sameLetters += s[j];
                    }
                }
                if(similarity > mostCommon) {
                    mostCommon = similarity;
                    commonLetters = sameLetters;
                }
            }
        }
    }

    cout << commonLetters << endl;
}

int main() {
    //Puzzle01();
    //Puzzle02();
    //Puzzle03();
    Puzzle04();

    return 0;
}
