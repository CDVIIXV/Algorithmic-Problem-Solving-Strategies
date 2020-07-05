

#include <iostream>

using namespace std;

const int MAX_ROW = 8;
const int MAX_COL = 8;
const int MAX_DIRECTION = 8;
const int MAX_WORD_COUNT = 3;
const int DERECTION[MAX_DIRECTION][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int row, col, wordCount;
char board[MAX_ROW][MAX_COL] = {0, };
string words[MAX_WORD_COUNT];

bool inRange(int y, int x);
bool hasWord(int y, int x, int direction, const string& word);
bool input();
void output();

bool inRange(int y, int x)
{
    return y >= 0 && y < row && x >= 0 && x < col;
}

bool hasWord(int y, int x, int direction, const string& word)
{
    if(!inRange(y, x))
    {
        return false;
    }

    if(board[y][x] != word[0])
    {
        return false;
    }

    if(word.size() == 1)
    {
        return true;
    }

    return hasWord(y + DERECTION[direction][0], x + DERECTION[direction][0], direction, word.substr(1));
}

int main(void)
{
    int w, row, col, wordCount;
    bool findFlag;
    input();
    output();
    return 0;
}

bool input()
{
    int y, x, w;

    // Fast input/output speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Fill the board with input
    cin >> row >> col;
    if(row > MAX_ROW || col > MAX_COL)
    {
        cout << "Board size too small.\n";
        return false;
    }
    for(y = 0; y < row; y++)
    {
        for(x = 0; x < col; x++)
        {   
            cin >> board[y][x];
        }
    }

    // set words with input
    cin >> wordCount;
    if(wordCount > MAX_WORD_COUNT)
    {
        cout << "Too many words.\n";
        return false;
    }
    for(w = 0; w < wordCount; w++)
    {  
        cin >> words[w];
    }
    return true;
}

void output()
{
    int y, x, w, d;
    bool find;
    for(w = 0; w < wordCount; w++)
    {
        find = false;
        for(y = 0; y < row && !find; y++)
        {
            for(x = 0; x < col && !find; x++)
            {
                for(d = 0; d < MAX_DIRECTION && !find; d++)
                {
                    if(hasWord(y, x, d, words[w]))
                    {
                       find = true;
                    }
                }
            }
        }
        if(find)
        {
            cout << words[w] << " is found!\n";
        }
        else
        {
            cout << words[w] << " is not found!\n";
        }
    }
}