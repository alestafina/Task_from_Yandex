#include <iostream>
#include <vector>

using namespace std;

void coloration(vector<vector<int>> &board, vector<int> &colors);
void output(vector<vector<int>> &board);

int main() {
    int k = 0, n = 0;
    cin >> n;
    cin >> k;
    vector<vector<int>> board(n);
    vector<int> colors;
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            board[i].push_back(0);
    }
    for (int i = 0; i < k; i++)
        colors.push_back(i + 1);

    coloration(board, colors);
    output(board);
    return 0;
}

void coloration(vector<vector<int>> &board, vector<int> &colors) {
    int size = board.size() * board.size();
    int l = 0;
    if (colors.size() != 1 && size != 1) {
        if (size >= colors.size() && size % colors.size() == 0) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board.size(); j++) {
                    if (i % 2 == 0) {
                        if (l < colors.size()) {
                            board[i][j] = colors[l];
                            l++;
                        } else {
                            l = 0;
                            board[i][j] = colors[l];
                            l++;
                        }
                    } else {
                        l++;
                        if (l < colors.size()) {
                            board[i][j] = colors[l];
                            l++;
                        } else {
                            l = 0;
                            board[i][j] = colors[l];
                            l++;
                        }
                    }
                }
                if (colors[l] == colors.size()) l = 0;
            }
        }
    } else board[0][0] = colors[0];
}

void output(vector<vector<int>> &board) {
    if (board[0][0] == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
}
