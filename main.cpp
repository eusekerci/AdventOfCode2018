#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

struct FabricPart {
public:
    int id;
    int x;
    int y;
    int height;
    int width;
};

vector<FabricPart> fabrics;
array<int,1293> fabricIndex = {0};
array<int,26> ASCII = {0};
int mList[1000000] = {0};
int fabric[1000][1000];
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

int StringToInt(string s, char sChar, char eChar, int buffer) {
    string l = "";
    int result;
    int m;
    if(eChar == 0) {
        m = s.size();
    } else {
        m = s.find(eChar);
    }
    for(int i=s.find(sChar)+buffer; i<m; i++) {
        l += s[i];
    }

    result = stoi(l);
    return result;
}

void Puzzle05() {
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            fabric[i][j] = 0;
        }
    }

    string s;
    while (getline(cin, s)) {
        int x,y,height,width;

        x = StringToInt(s, '@', ',', 2);
        y = StringToInt(s, ',', ':', 1);
        width = StringToInt(s, ':', 'x', 2);
        height = StringToInt(s, 'x', 0, 1);

        for(int i=x; i<x+width; i++) {
            for(int j=y; j<y+height; j++) {
                fabric[i][j]++;
            }
        }
    }

    int result = 0;
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            if(fabric[j][i] > 1) {
                result++;
            }
        }
    }

    cout << result << endl;
}

void Puzzle06() {
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            fabric[i][j] = 0;
        }
    }

    string s;
    while (getline(cin, s)) {
        int x,y,height,width, id;
        FabricPart fb;
        id = StringToInt(s, '#', '@', 1);
        x = StringToInt(s, '@', ',', 2);
        y = StringToInt(s, ',', ':', 1);
        width = StringToInt(s, ':', 'x', 2);
        height = StringToInt(s, 'x', 0, 1);
        fb.id = id;
        fb.x = x;
        fb.y = y;
        fb.width = width;
        fb.height = height;
        fabrics.push_back(fb);
    }

    fabricIndex.fill(0);
    for(int k=0; k<fabrics.size(); k++) {
        for(int i=fabrics[k].x; i<fabrics[k].x+fabrics[k].width; i++) {
            for(int j=fabrics[k].y; j<fabrics[k].y+fabrics[k].height; j++) {
                if(fabric[i][j] > 0) {
                    fabricIndex[fabric[i][j] - 1]++;
                    fabricIndex[k]++;
                } else {
                    fabric[i][j] = fabrics[k].id;
                }
            }
        }
    }

    int result = 0;
    for(int i=0; i<fabricIndex.size(); i++) {
        if(fabricIndex[i] == 0) {
            cout << i+1 << endl;
        }
    }
}

int main() {
    //Puzzle01();
    //Puzzle02();
    //Puzzle03();
    //Puzzle04();
    //Puzzle05();
    Puzzle06();

    return 0;
}
