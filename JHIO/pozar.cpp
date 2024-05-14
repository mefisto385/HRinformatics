//CREDIT TO BORNAG
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
using namespace std;
typedef pair<int, int> par;
int ROWS, COLS, K, R, Q, Xi, Yi, Ai, Ti;
queue<pair<pair<int, int>, int>> q;
int koliko[2001];
int tab[2001][2001];

int countFire(int minute){
    int found = 0;

    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(tab[r][c] <= minute+1 && tab[r][c] > 0){
                found++;
            }
        }
    }
    return found;
}

void kvadrat(int Xi, int Yi, int Ai){
    if (koliko[0] == (ROWS*COLS)){return;}
    Xi -= 1;
    Yi -= 1;
    int topLeftX = max(Xi-Ai+1,0); // 7
    int topLeftY = max(Yi-Ai+1,0); // 0
    int bottomRightX = min(Xi+Ai-1, ROWS-1); // 11
    int bottomRightY = min(Yi+Ai-1, COLS-1); // 4

    //cout << max(0, topLeftX) << ' ' << max(0, topLeftY) << endl;
    //cout << min(ROWS, bottomRightX) <<  ' ' << min(COLS, bottomRightY) << endl;

    for(int row = topLeftX; row <= bottomRightX; row++){
        for(int col = topLeftY; col <= bottomRightY; col++){
            //cout << row << ' ' << col << '\n';
            if(tab[row][col] == 0){
                tab[row][col] = 1;
                koliko[0]++;
                //q.push({{row, col}, 1});
                if(row == topLeftX || row == bottomRightX || col == topLeftY || col == bottomRightY){
                    q.push({{row, col}, 1});
                    //cout << row << ' ' << col << ' ' << 1 << endl;
                }
            }
        }
    }
}

void romb(int Xi, int Yi, int Ai){
    if (koliko[0] == (ROWS*COLS)){return;}
    /*Xi -= 1;
    Yi -= 1;
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            int a = (abs(Xi-row))+ abs((Yi-col));
            if(a<Ai){
                tab[row][col] = 1;
            }
        }
    }*/
    /*Xi -= 1;
    Yi -= 1;
    int topLeftX = Xi-Ai;
    int topLeftY = Yi-Ai;
    int bottomRightX = Xi+Ai+1;
    int bottomRightY = Yi+Ai+1;

    //cout << max(0, topLeftX) << ' ' << max(0, topLeftY) << endl;
    //cout << min(ROWS, bottomRightX) <<  ' ' << min(COLS, bottomRightY) << endl;

    for(int row = max(0, topLeftX); row < min(ROWS, bottomRightX)-1; row++){
        for(int col = max(0, topLeftY); col < min(COLS, bottomRightY)-1; col++){
            int a = (abs(Xi-row))+ abs((Yi-col));
            if(a<Ai){
                tab[row][col] = 1;
            }
        }
    }*/
    Xi -= 1;
    Yi -= 1;
    int topLeftX = max(Xi-Ai+1,0);
    int topLeftY = max(Yi-Ai+1,0); // 3 3 2 1 1     5 5
    int bottomRightX = min(Xi+Ai-1, ROWS-1);
    int bottomRightY = min(Yi+Ai-1, COLS-1);

    //cout << max(0, topLeftX) << ' ' << max(0, topLeftY) << endl;
    //cout << min(ROWS, bottomRightX) <<  ' ' << min(COLS, bottomRightY) << endl;

    for(int row = topLeftX; row <= bottomRightX; row++){
        for(int col = topLeftY; col <= bottomRightY; col++){
            //cout << row << ' ' << col << '\n';
            int a = (abs(Xi-row))+ abs((Yi-col));
            if(a < Ai && tab[row][col] == 0){
                koliko[0]++;
                tab[row][col] = 1;
                //q.push({{row, col}, 1});
                if(abs(Xi-row) + abs(Yi-col) == Ai-1){
                    q.push({{row, col}, 1});
                }
            }
        }
    }
}


uint64_t micros()
{
    uint64_t us = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    return us;
}

int main() {
    //koliko[0] = 0;
	cin >> ROWS >> COLS;
    cin >> K >> R >> Q;
    int Ai, Xi, Yi;
    vector<pair<int, int>> susjedi;
    vector<int> pMins;
    int k = 0;

    for(int i = 0; i < K; i++){
        scanf("%d", &Xi);
        scanf("%d", &Yi);
        scanf("%d", &Ai);
        //cin >> Xi >> Yi >> Ai;
        if(Ai==1 && tab[Xi-1][Yi-1] == 0){tab[Xi-1][Yi-1] = 1; koliko[0]++; q.push({{Xi-1, Yi-1}, 1}); continue;}
        kvadrat(Xi, Yi, Ai);
    }

    for(int i = 0; i < R; i++){
        scanf("%d", &Xi);
        scanf("%d", &Yi);
        scanf("%d", &Ai);
        //cin >> Xi >> Yi >> Ai;
        if(Ai==1 && tab[Xi-1][Yi-1] == 0){tab[Xi-1][Yi-1] = 1; q.push({{Xi-1, Yi-1}, 1}); koliko[0]++; continue;}
        romb(Xi, Yi, Ai);
    }


    for(int i = 0; i < Q; i++){
        cin >> Ti;
        //scanf("%d", Ti);
        pMins.push_back(Ti);
    }

    int maxq = *max_element(pMins.begin(), pMins.end());


    /*for(int ro = 0; ro < ROWS; ro++){
        for(int co = 0; co < COLS; co++){
            if(tab[ro][co] == 1){
                q.push({{ro, co}, 1});
            }
        }
    }*/
    //koliko[0];


    auto start = micros();
    //cout << "Start " << q.size() << endl;;
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cu = q.front().second;
        susjedi.clear();
        q.pop();

        if(koliko[cu] == 0)
            koliko[cu] = koliko[cu-1];
            k = koliko[cu-1];

        if(cu == maxq+1){
            break;
        }

        //Susjedi
        int cu1 = cu + 1;
        int offsetX[] = {0,1,0,-1};
        int offsetY[] = {-1,0,1,0};

        for(int i = 0; i < 4; i++){
            int nx = cx + offsetX[i];
            int ny = cy + offsetY[i];
            if(nx < 0 || nx >= ROWS || ny < 0 || ny >= COLS){
                continue;
            }

            if(tab[nx][ny] == 0){
                //susjedi.push_back({nx, ny});
                tab[nx][ny] = cu1;
                koliko[cu]++;
                q.push({{nx, ny}, cu1});
            }
        }

        /*for(par susjed : susjedi){
            int sx = susjed.first;
            int sy = susjed.second;

            tab[sx][sy] = cu+1;
            koliko[cu]++;
            q.push({{sx, sy}, cu+1});
        }*/

    }

    for(int m = 0; m < pMins.size(); m++){
        //printf("%d\n", countFire(pMins[m]));
        int h = koliko[pMins[m]];
        if(h == 0) printf("%d\n", k);
        else{ printf("%d\n", h);}
             //cout << k << ' ' << h << endl;}
        //printf(countFire(pMins[m]));

    }

    /*for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            cout << tab[r][c];
        }
        cout << endl;
    }*/

    /*cout << "Emdl" << endl;
    for(int i = 0; i < maxq; i++){
        cout << koliko[i] << endl;
    }*/
    auto elapsed = micros() - start;
    //cout << elapsed << endl;
    return 0;

}
