#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkPuddles(vector<vector<int>>& puddles, int y, int x) {
    for (int i = 0; i < puddles.size(); i++) {
        if (puddles[i][0] == x && puddles[i][1] == y) {
            return false;
        }
    }
    return true;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int a = 0;
    int b = 0;
    vector<vector<int>> map(101, vector<int>(101, 1));
    for (int i = 0; i < puddles.size(); i++) {
        a = puddles[i][0];
        b = puddles[i][1];
        if (a == 1) {
            for (int i = b; i <= n; i++) {
                map[i][a] = 0;
            }
        }
        else if (b == 1) {
            for (int i = a; i <= m; i++) {
                map[b][i] = 0;
            }
        }
        map[b][a] = 0;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (checkPuddles(puddles, i, j)) {
                a = map[i - 1][j] % 1000000007;
                b = map[i][j - 1] % 1000000007;
                map[i][j] = (a + b) % 1000000007;
            }
            
            
        }
    }
    return map[n][m] % 1000000007;
}