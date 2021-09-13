#include <iostream>

using namespace std;

int a[20][20];
int dice[7];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
    int n, m, x, y, l;
    cin >> n >> m >> x >> y >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (l--) {
        int k;
        cin >> k;
        k -= 1; // make it {0, 1, 2, 3}
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
            continue; // if it goes out of map, ignore it and don't print anything
        }
        if (k == 0) { // East
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        } else if (k == 1) { // West
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        } else if (k == 2) { // North
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        } else { // if (k == 3) South
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }
        x = nx;
        y = ny;
        if (a[nx][ny] == 0) {
            a[nx][ny] = dice[6]; // 6 is the bottom side
        } else {
            dice[6] = a[nx][ny];
            a[nx][ny] = 0;
        }
        cout << dice[1] << endl;
    }
    return 0;
}