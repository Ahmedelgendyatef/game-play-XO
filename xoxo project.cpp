#include<iostream>
#include<windows.h>
using namespace std;

char matrix[3][3] = { '1','2','3','4', '5','6', '7','8', '9' };
char player = 'x';

void print() {
    system("cls");
    cout << "-------" << endl;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cout << matrix[r][c] << "  ";
        }
        cout << endl;
    }
    cout << "-------" << endl;
}

void replace() {
    char pos;
    cout << "Enter your position (" << player << "): " << endl;
    cin >> pos;
    bool validMove = false; 
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (matrix[r][c] == pos) {
                matrix[r][c] = player;
                validMove = true; 
            }
        }
    }
    if (!validMove) {
        cout << "Invalid position! Try again." << endl;
        replace();
    } else {
        player = (player == 'x') ? 'o' : 'x';
    }
}

char checkwinner() {
    int x = 0;
    int o = 0;
    int counter = 0;

    // Check rows
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (matrix[r][c] == 'x') x++;
            else if (matrix[r][c] == 'o') o++;
        }
        if (x == 3) return 'x';
        if (o == 3) return 'o';
        x = 0; o = 0; 
    }

    // Check columns
    for (int c = 0; c < 3; c++) {
        for (int r = 0; r < 3; r++) {
            if (matrix[r][c] == 'x') x++;
            else if (matrix[r][c] == 'o') o++;
        }
        if (x == 3) return 'x';
        if (o == 3) return 'o';
        x = 0; o = 0; 
    }

    // Check diagonals
    if (matrix[0][0] == 'x' && matrix[1][1] == 'x' && matrix[2][2] == 'x') return 'x';
    if (matrix[0][0] == 'o' && matrix[1][1] == 'o' && matrix[2][2] == 'o') return 'o';
    if (matrix[0][2] == 'x' && matrix[1][1] == 'x' && matrix[2][0] == 'x') return 'x';
    if (matrix[0][2] == 'o' && matrix[1][1] == 'o' && matrix[2][0] == 'o') return 'o';

    // Check for draw
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (matrix[r][c] != 'x' && matrix[r][c] != 'o') counter++;
        }
    }
    if (counter == 0) return '=';

    return '*'; 
}

int main() {
    while (checkwinner() == '*') {
        print();
        replace();
    }
    print();
    if (checkwinner() == 'x')
        cout << "The winner is player x:" << endl;
    else if (checkwinner() == 'o')
        cout << "The winner is player o:" << endl;
    else if (checkwinner() == '=')
        cout << "It's a draw:" << endl;

    return 0;
}


