#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2차원 배열을 만들고 데이터를 넣은 뒤 움직이게 하는 방식이다.
// 사각형 테두리는 1이라는 값이고 사각형 내부는 9, 외부는 0이다.
// 내부하고 외부를 구분짓는 이유는 외부는 초기에 아무것도 없을 때 0이고
// 그위에 숫자를 써서 경로를 만들어야하는데 사각형이 겹치는 부분의 경우,
// 그 경로는 없애야한다. 그런데 0 위에 쓰다보니까 사각형 내부를 0으로
// 했다면 사각형 내부를 전부 1로 칠해버리는 불상사가 발생한다. -> 조건문을 그렇게 작성
// 
// 정상적으로 경로를 1로 만들었다면 움직이게 해야하는데 경우가 2가지 밖에 없으므로
// 2가지 다 가보고 짧은 경로를 리턴하면 된다.
// 
// 한가지 문제가 있었는데 1이 겹쳐있는 경우이다. 1번 예시처럼 ㄷ경로가 있으면 우리 
// 눈으로 보기에는 빈공간이 보이지만 배열로보면 1이 뭉텅이로 위치하게 보인다.
// 이것은 격자의 최소 간격이 1이라서 생기는 한계이므로 최소간격을 0.5로 만든다.
// 즉 사이즈를 2배로 키우고 결과를 2로 나누어 답을 낸다.
//

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

    MaxX = (MaxX + 1) * 2;
    MaxY = (MaxY + 1) * 2;

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

    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = rectangle[i][0]*2; j <= rectangle[i][2]*2; j++)
        {
            for (int k = rectangle[i][1]*2; k <= rectangle[i][3]*2; k++)
            {
                if (j == rectangle[i][0]*2 || j == rectangle[i][2]*2 || k == rectangle[i][1]*2 || k == rectangle[i][3]*2)
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

    int count = 0;
    int player[2] = { characterX*2,characterY*2 };
    while (1)
    {
        Map[player[0]][player[1]] = 7;
        for (int i = 0; i < MaxX; i++)
        {
            for (int j = 0; j < MaxY; j++)
            {
                cout << Map[i][j] << " ";
            }
            cout << endl;
        }
        if (player[0] == itemX*2 && player[1] == itemY*2)
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

    int count2 = 0;
    player[0] = characterX * 2;
    player[1] = characterY * 2;
    Map[itemX * 2][itemY * 2] = 1;
    while (1)
    {
        Map[player[0]][player[1]] = 7;
        for (int i = 0; i < MaxX; i++)
        {
            for (int j = 0; j < MaxY; j++)
            {
                cout << Map[i][j] << " ";
            }
            cout << endl;
        }
        if (player[0] == itemX * 2 && player[1] == itemY * 2)
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
        else if (Map[player[0]][player[1] + 1] == 1)
        {
            player[1]++;
        }
        else if (Map[player[0]][player[1] - 1] == 1)
        {
            player[1]--;
        }
        count2++;
        int j;
        cin >> j;
    }

    for (int i = 0; i < MaxX; i++)
    {
        delete[] Map[i];
    }
    delete[] Map;

    int answer = 0;

    if (count >= count2)
    {
        answer = count2/2;
    }
    else if (count < count2)
    {
        answer = count/2;
    }
    return answer;
}

int main()
{
    vector<vector<int>> rectangle = { {1,1,8,4}, {2,2,4,9},{3,6,9,8},{6,3,7,7} };
    int result = solution(rectangle, 9, 7, 6, 1);
    cout << result;
    int j = 0;
    cin >> j;
}