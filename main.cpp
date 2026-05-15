#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> result = topArticles(2);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}
