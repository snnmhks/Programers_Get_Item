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

    int** Map = new int*[MaxX];
    for (int i = 0; i < MaxX; i++)
    {
        Map[i] = new int[MaxY];
    }

    for (int i = 0; i < MaxX; i++)
    {
        for (int j = 0; j < MaxY; j++)
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
                    Map[j][k] = -1;
                }
            }
        }
    }

    Map[itemX][itemY] = 3;

    int player[2] = { characterX ,characterY };
    int vector[2] = { 1,0 };
    while (1)
    {
        int Next[2] = { player[0] + vector[0],player[1] + vector[1] };
        if (Map[Next[0]][Next[1]] <= 0)
    }

    int answer = 0;
    return answer;
}