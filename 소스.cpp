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
                        Map[j][k] = 1;
                    }
                }
                else
                {
                    Map[j][k] = 9;
                }
            }
        }
    }

    int TotalLength = 0;
    for (int i = 0; i < MaxX + 1; i++)
    {
        for (int j = 0; j < MaxY + 1; j++)
        {
            if (Map[i][j] == 1)
            {
                TotalLength++;
            }
        }
    }

    int count = 0;
    int player[2] = { characterX,characterY };
    while (1)
    {
        for (int i = 0; i < MaxX + 1; i++)
        {
            for (int j = 0; j < MaxY + 1; j++)
            {
                cout << Map[i][j] << " ";
            }
            cout << endl;
        }
        cout << player[0] << " " << player[1] << endl;
        if (player[0] == itemX && player[1] == itemY)
        {
            break;
        }
        if (Map[player[0] + 1][player[1]] == 1)
        {
            player[0]++;
        }
        else if (Map[player[0] - 1][player[1]] == 1)
        {
            player[0]--;
        }
        else if (Map[player[0]][player[1]+1] == 1)
        {
            player[1]++;
        }
        else if (Map[player[0]][player[1] - 1] == 1)
        {
            player[1]--;
        }
        count++;
        int j;
        cin >> j;
    }

    for (int i = 0; i < MaxX + 1; i++)
    {
        delete[] Map[i];
    }
    delete[] Map;

    int count2 = TotalLength - count;
    int answer = 0;

    if (count >= count2)
    {
        answer = count2;
    }
    else if (count < count2)
    {
        answer = count;
    }
    return answer;
}

int main()
{
    vector<vector<int>> rectangle = { {1,1,7,4}, {3,2,5,5},{4,3,6,9},{2,6,8,8} };
    int result = solution(rectangle, 1, 3, 7, 8);
    cout << result;

}