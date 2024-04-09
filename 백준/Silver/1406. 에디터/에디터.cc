#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    list<char> editor(s.begin(), s.end());
    auto cursor = editor.end();
    
    int m;
    cin >> m;
    while (m--) {
        char op;
        cin >> op;
        if (op == 'L') {
            if (cursor != editor.begin()) {
                cursor--;
            }
        } else if (op == 'D') {
            if (cursor != editor.end()) {
                cursor++;
            }
        } else if (op == 'B') {
            if (cursor != editor.begin()) {
                cursor--;
                cursor = editor.erase(cursor);
            }
        } else if (op == 'P') {
            char c;
            cin >> c;
            cursor = editor.insert(cursor, c);
            cursor++;
        }
    }
    for (auto c : editor) {
        cout << c;
    }
    cout << '\n';
    return 0;
}