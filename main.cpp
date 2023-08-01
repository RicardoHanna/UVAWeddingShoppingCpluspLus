#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;


int model,money,amount;
int M,C;
int price[5][5];
int memo[1000][1000];
int shop(int money, int g) {//TOP-DOWN
  if (money < 0) return -1000000000;     // fail, return a large -ve number
  if (g == C) return M - money;        // we have bought last garment, done
  if (memo[money][g] != -1) return memo[money][g]; // TOP-DOWN: memoization
  int ans = -1;   // start with a -ve number as all prices are non negative
  for (int model = 1; model <= price[g][0]; model++)      // try all models
    ans = max(ans, shop(money - price[g][model], g + 1));
  return memo[money][g] = ans; // TOP-DOWN: assign ans to table + return it
}


int main()
{
    ifstream fin;
    fin.open("uvawedding.txt");
    if(!fin){
        cerr<<"error"<<endl;
        return 1;
    }
  int TC;
  int score;
  fin>>TC;
  while(TC--){
    fin>>M>>C;
    for(int i=0;i<C;i++){
        fin>>price[i][0];
        for(int j=1;j<=price[i][0];j++)
            fin>>price[i][j];
    }
    memset(memo, -1, sizeof memo);
    score=shop(M,0);
    if(score<0) cout<<"no solution"<<endl;
    else
        cout<<score<<endl;
  }

    return 0;
}
