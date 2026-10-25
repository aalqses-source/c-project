#include<iostream>
using namespace std;

char arr[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char position;
char player = 'X';
int xcount = 0;
int test;
int ocount = 0;

void show()
{
    cout << "\n\n\t\t\t_________________ " << endl;
    cout << "\t\t\t|     |     |     |" << endl;
    cout << "\t\t\t|  " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << "  |" << endl;
    cout << "\t\t\t|_____|_____|_____|" << endl;
    cout << "\t\t\t|     |     |     |" << endl;
    cout << "\t\t\t|  " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << "  |" << endl;
    cout << "\t\t\t|_____|_____|_____|" << endl;
    cout << "\t\t\t|     |     |     |" << endl;
    cout << "\t\t\t|  " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << "  |" << endl;
    cout << "\t\t\t|_____|_____|_____|" << endl;
}

void play()
{
    cout << "Please enter the position (1-9) for player: " << player << endl;
    cin >> position;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == position)
            {
                arr[i][j] = player;
                goto next;
            }
        }
    }

    cout << "Invalid position!" << endl;
    return;

next:
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

char winner()
{
    test = 0;

    for (int i = 0; i < 3; i++)
    {
        xcount = ocount = 0;

        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'X' && arr[i][j] != 'O'){
                test = 1;
            }
            if (arr[i][j] == 'X'){
                xcount++;
            }
            else if (arr[i][j] == 'O'){
                ocount++;
        }
    }

        if (xcount == 3){
            return 'X';
        }
        else if (ocount == 3){
            return 'O';
    }
}

    for (int i = 0; i < 3; i++)
    {
        xcount = ocount = 0;
        for (int j = 0; j < 3; j++)
        {
            if (arr[j][i] == 'X'){
                xcount++;
            }
            else if (arr[j][i] == 'O'){
                ocount++;
            }
        }
        if (xcount == 3){
            return 'X';
        }
        else if (ocount == 3){
            return 'O';
        }
    }
    if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X'){
        return 'X';
    }
    else if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O'){
        return 'O';
    }
    if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X'){
        return 'X';}
    else if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O'){
        return 'O';
    }
    if (test == 0){
        return 'z';
    }
    return '.';
}
int main()
{
    while (winner() == '.')
    {
        show();
        play();
        system("cls");
    }

    show();

    if (winner() == 'z')
    {
        cout << "No one is winner" << endl;
    }
    else
    {
        cout << "The winner in this game is player: "
             << winner() << " congratulations" << endl;
    }

    return 0;
}