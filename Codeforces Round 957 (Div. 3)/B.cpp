#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;
 
 
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int sum, piecesNum;
        cin >> sum >> piecesNum;
        vector<int> pieces(piecesNum);
        for (int i = 0; i < piecesNum; i++) {
            int piece;
            cin >> piece;
            pieces[i] = piece;
        }
        sort(pieces.begin(), pieces.end());
        int length = 0, operations = 0;
        for (int i = 0; i < piecesNum - 1; i++) {
            if (pieces[i] > 1) {
                length += pieces[i];
                operations += pieces[i] - 1;
            }
            else {
                length++;
            }
        }
        cout << length + operations << endl;
    }
    return 0;
}