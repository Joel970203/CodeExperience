#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int board[25][25];
int dy[4] = {-1,0,1,0}; // 북, 동, 남, 서
int dx[4] = {0,1,0,-1};

int dice[6] = {1,6,2,5,4,3}; 
// dice[0]=위, [1]=아래, [2]=북, [3]=남, [4]=서, [5]=동

void roll(int dir) {
    int tmp[6];
    copy(begin(dice), end(dice), tmp);

    if (dir==0) { // 북
        dice[0]=tmp[3]; dice[1]=tmp[2]; dice[2]=tmp[0]; dice[3]=tmp[1];
        dice[4]=tmp[4]; dice[5]=tmp[5];
    } else if (dir==1) { // 동
        dice[0]=tmp[4]; dice[1]=tmp[5]; dice[4]=tmp[1]; dice[5]=tmp[0];
        dice[2]=tmp[2]; dice[3]=tmp[3];
    } else if (dir==2) { // 남
        dice[0]=tmp[2]; dice[1]=tmp[3]; dice[2]=tmp[1]; dice[3]=tmp[0];
        dice[4]=tmp[4]; dice[5]=tmp[5];
    } else if (dir==3) { // 서
        dice[0]=tmp[5]; dice[1]=tmp[4]; dice[4]=tmp[0]; dice[5]=tmp[1];
        dice[2]=tmp[2]; dice[3]=tmp[3];
    }
}

int bfs(int sy,int sx) {
    bool visited[25][25] = {false};
    queue<pair<int,int>> q;
    q.push({sy,sx});
    visited[sy][sx]=true;
    int target=board[sy][sx];
    int cnt=1;

    while(!q.empty()){
        auto [y,x]=q.front(); q.pop();
        for(int d=0;d<4;d++){
            int ny=y+dy[d], nx=x+dx[d];
            if(ny<0||ny>=N||nx<0||nx>=M) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx]!=target) continue;
            visited[ny][nx]=true;
            q.push({ny,nx});
            cnt++;
        }
    }
    return cnt*target;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> board[i][j];

    int y=0,x=0,dir=1; // 시작 위치 (0,0), 방향 동쪽
    int answer=0;

    for(int k=0;k<K;k++){
        int ny=y+dy[dir], nx=x+dx[dir];
        // 경계 넘어가면 반대방향
        if(ny<0||ny>=N||nx<0||nx>=M){
            dir=(dir+2)%4;
            ny=y+dy[dir]; nx=x+dx[dir];
        }
        y=ny; x=nx;

        // 주사위 굴리기
        roll(dir);

        // 점수 획득
        answer += bfs(y,x);

        // 이동 방향 결정
        int A=dice[1]; // 아랫면
        int B=board[y][x];
        if(A>B) dir=(dir+1)%4;       // 시계
        else if(A<B) dir=(dir+3)%4;  // 반시계
    }

    cout << answer << "\n";
}
