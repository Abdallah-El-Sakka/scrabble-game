#include <iostream>

using namespace std;

int scoreCalc(string);
int indexFinder(char,char[]);

int main()
{
    
    string player1 , player2;
    
    cout << "Player1: ";
    cin >> player1;
    
    cout << "Player2: ";
    cin >> player2;
    
    
    if(scoreCalc(player1) > scoreCalc(player2))
        cout << "Player 1 wins !" << endl;
    else if(scoreCalc(player1) < scoreCalc(player2))
        cout << "Player 2 wins !" << endl;
    else
        cout << "Tie !" << endl;
        
}

int scoreCalc(string S)
{
    
    int SCORES[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

    char ALPHA[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    int score = 0;
    
    for(int i = 0 ; i < S.length() ; i++)
    {
        
        int index = indexFinder(S[i] , ALPHA);
        
        if(index > 0)
        {
            score += SCORES[index];
        }
        
    }
    
    return score;
}

int indexFinder(char s,char alphas[])
{
    
    for(int i = 0 ; i < 26 ; i++)
    {
        
        if(alphas[i] == s) return i;
        
    }
    
    return 0;
    
}
