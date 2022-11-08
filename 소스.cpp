#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) 
{
    int MaxX = 0;
    int MaxY = 0;

    for (int i = 0; i < rectangle.size(); i++)
    {
        if (rectangle[i][2] > MaxX)
        {
            MaxX = rectangle[i][2];
        }
        if (rectangle[i][3] > MaxY)
        {
            MaxY = rectangle[i][3];
        }
    }

    int** Map = new int*[MaxX + 1];
    for (int i = 0; i < MaxX + 1; i++)
    {
        Map[i] = new int[MaxY + 1];
    }

    for (int i = 0; i < MaxX + 1; i++)
    {
        for (int j = 0; j < MaxY + 1; j++)
        {
            Map[i][j] = 0;
        }
    }

    int TotalLength = 0;
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = rectangle[i][0]; j <= rectangle[i][2]; j++)
        {
            for (int k = rectangle[i][1]; k <= rectangle[i][3]; k++)
            {
                if (j == rectangle[i][0] || j == rectangle[i][2] || k == rectangle[i][1] || k == rectangle[i][3])
                {
                    if (Map[j][k] == 0)
                    {
                        TotalLength++;
                        Map[j][k] = 1;
                    }
                    else if (Map[j][k] == 1)
                    {
                        Map[j][k] = 2;
                    }
                }
                else
                {
                    Map[j][k] = 9;
                }
            }
        }
    }

    Map[itemX][itemY] = 3;

    int player[2] = { characterX ,characterY };
    int vector[2] = { 0,0 };
    int count = 0;

    if (Map[player[0] + 1][player[1]] == 1)
    {
        vector[0] = 1;
    }
    else if (Map[player[0] - 1][player[1]] == 1)
    {
        vector[0] = -1;
    }
    else if (Map[player[0]][player[1]+1] == 1)
    {
        vector[1] = 1;
    }
    else if (Map[player[0]][player[1]-1] == 1)
    {
        vector[1] = -1;
    }

    while (1)
    {
        int Next[2] = { player[0] + vector[0],player[1] + vector[1] };
        if (Map[Next[0]][Next[1]] == 3)
        {
            count++;
            break;
        }
        if (Map[Next[0]][Next[1]] == 1)
        {
            player[0] = Next[0];
            player[1] = Next[1];
            count++;
        }
        if (Map[Next[0]][Next[1]] == 2)
        {
            if (Map[player[0] + vector[1]][player[1] + vector[0]] == 0)
            {
                int tmp = vector[0];
                vector[0] = vector[1];
                vector[1] = tmp;
            }
            else if (Map[player[0] + vector[1]][player[1] + vector[0]] == 9)
            {
                int tmp = -vector[0];
                vector[0] = -vector[1];
                vector[1] = tmp;
            }
            player[0] = Next[0];
            player[1] = Next[1];
            count++;
        }
        else
        {
            int P = Map[player[0] + vector[1]][player[1] + vector[0]];
            if (P == 1 || P == 2 || P == 3)
            {
                int tmp = vector[0];
                vector[0] = vector[1];
                vector[1] = tmp;
            }
            else
            {
                int tmp = -vector[0];
                vector[0] = -vector[1];
                vector[1] = tmp;
            }
        }

        Map[player[0]][player[1]] = 7;
        for (int i = 0; i < MaxX + 1; i++)
        {
            for (int j = 0; j < MaxY + 1; j++)
            {
                cout << Map[i][j] << " ";
            }
            cout << endl;
        }
        cout << vector[0] << " " << vector[1] << endl;
        int j;
        cin >> j;
    }

    int count2 = TotalLength - count;
    int answer = 0;

    if (count >= count2)
    {
        answer = count;
    }
    else if (count < count2)
    {
        answer = count2;
    }

    for (int i = 0; i < MaxX + 1; i++)
    {
        delete[] Map[i];
    }
    delete[] Map;

    return answer;
}

int main()
{
    vector<vector<int>> rectangle = { {1,1,7,4}, {3,2,5,5},{4,3,6,9},{2,6,8,8} };
    int result = solution(rectangle, 1, 3, 7, 8);
    cout << result;

}