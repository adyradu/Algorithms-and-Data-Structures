// Sort a list of words in Welsh alphabet
// a b c ch d dd e f ff g ng h i j l ll m n o p ph r rh s t th u w y
// combination letters: ch, dd, ff, ng, ll, ph, rh, th
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

static unordered_map<char, char> combinations;

bool compare(const string& a, const string& b)
{
    int posA = 0, posB = 0;

    while (posA < a.size() && posB < b.size())
    {
        int orderA = 0, orderB = 0;
        char ca = a[posA];
        char cb = b[posB];

        if (posA + 1 < a.size() &&
            combinations.find(ca) != combinations.end() &&
            a[posA + 1] == combinations[ca]) {
            orderA = 2 * ca + 1;
            posA += 2;
        }
        else {
            orderA = 2 * ca;
            posA++;
        }

        if (posB + 1 < b.size() &&
            combinations.find(cb) != combinations.end() &&
            b[posB + 1] == combinations[cb]) {
            orderB = 2 * cb + 1;
            posB += 2;
        }
        else {
            orderB = 2 * cb;
            posB++;
        }

        if (orderA > orderB) {
            return false;
        }
        else if (orderA < orderB) {
            return true;
        }
    }

    if (a.size() > b.size()) {
        return false;
    }

    return true;
}

int main(void)
{
    combinations.insert(pair<char, char>('c', 'h'));
    combinations.insert(pair<char, char>('d', 'd'));
    combinations.insert(pair<char, char>('f', 'f'));
    combinations.insert(pair<char, char>('n', 'g'));
    combinations.insert(pair<char, char>('l', 'l'));
    combinations.insert(pair<char, char>('p', 'h'));
    combinations.insert(pair<char, char>('r', 'h'));
    combinations.insert(pair<char, char>('t', 'th'));

    vector<string> str = {
        "ddunchan",
        "ddunczan",
        "duncan",
        "",
        "a",
        "ab",
        "paragraph",
        "paragraph",
        "paragrap",
        "phrhddd",
        "phrhdd",
        "ddd",
        "ded",
        "dde",
        "ana",
        "ama",
        "aa",
        "elefant",
        "abhch",
        "abhc"
    };

    sort(str.begin(), str.end(), compare);

    for (int i = 0; i < str.size(); ++i) {
        cout<<str[i]<<" ";
    }

    cout<<endl;

    //cout<<compare("edduc", "eddu")<<endl;

    return 0;
}