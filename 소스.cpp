#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2���� �迭�� ����� �����͸� ���� �� �����̰� �ϴ� ����̴�.
// �簢�� �׵θ��� 1�̶�� ���̰� �簢�� ���δ� 9, �ܺδ� 0�̴�.
// �����ϰ� �ܺθ� �������� ������ �ܺδ� �ʱ⿡ �ƹ��͵� ���� �� 0�̰�
// ������ ���ڸ� �Ἥ ��θ� �������ϴµ� �簢���� ��ġ�� �κ��� ���,
// �� ��δ� ���־��Ѵ�. �׷��� 0 ���� ���ٺ��ϱ� �簢�� ���θ� 0����
// �ߴٸ� �簢�� ���θ� ���� 1�� ĥ�ع����� �һ�簡 �߻��Ѵ�. -> ���ǹ��� �׷��� �ۼ�
// 
// ���������� ��θ� 1�� ������ٸ� �����̰� �ؾ��ϴµ� ��찡 2���� �ۿ� �����Ƿ�
// 2���� �� ������ ª�� ��θ� �����ϸ� �ȴ�.
// 
// �Ѱ��� ������ �־��µ� 1�� �����ִ� ����̴�. 1�� ����ó�� ����ΰ� ������ �츮 
// ������ ���⿡�� ������� �������� �迭�κ��� 1�� �����̷� ��ġ�ϰ� ���δ�.
// �̰��� ������ �ּ� ������ 1�̶� ����� �Ѱ��̹Ƿ� �ּҰ����� 0.5�� �����.
// �� ����� 2��� Ű��� ����� 2�� ������ ���� ����.
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