#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, N;
vector<string> words;
bool found = false;

void checkMagicSquare(vector<string>& square) {
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < i; ++j) {
            if (square[i][j] != square[j][i]) {
                return;
            }
        }
    }
    found = true;
    for (const string& row : square) {
        cout << row << "\n";
    }
}

void permute(int depth, vector<string>& chosen, vector<bool>& used) {
    if (found) return;
    if (depth == L) {
        checkMagicSquare(chosen);
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            used[i] = true;
            chosen[depth] = words[i];
            permute(depth + 1, chosen, used);
            if (found) return;
            used[i] = false;
        }
    }
}

int main() {
    cin >> L >> N;
    words.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }
    sort(words.begin(), words.end());

    vector<string> chosen(L);
    vector<bool> used(N, false);
    permute(0, chosen, used);

    if (!found) {
        cout << "NONE";
    }

    return 0;
}
