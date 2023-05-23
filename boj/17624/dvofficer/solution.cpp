#include<iostream>
#include<vector>
#define LMT 5001
#define INT_MX 1000000000
using namespace std;

/**
 * https://www.acmicpc.net/problem/17624
 * BOJ 17624번 검은 돌
 * DP, TREE, DP On TREE
*/

int N, B;
int black[LMT];

vector<int> edge[LMT];
int dp[LMT][LMT][2] = {0,};

int ansTable[5001][2] = {0,};
int ans[LMT][LMT];
int visited[LMT] = {0,};

/**
 * Initialize tables for dp
 * for dep table dp [i][j][0], [i][j][1] means
 * the maximum and minimum number of nodes in the subtree of node i that have j black nodes
*/
void init_dp(){
    for(int i=0;i<=N;i++){
        black[i] = 0;
        ansTable[i][1] = INT_MX;
    }
    for(int i=1;i<=N;i++)
        for(int j=0;j<=B;j++){
            dp[i][j][0] = 0;
            dp[i][j][1] = INT_MX;
            ans[i][j] = 0;
        }
}

/**
 * read input and prepare table for DFS algorithm.
*/
void read_graph(){
    for(int i=0;i<B;i++){
        int x;
        cin >> x;
        black[x] = 1;
    }

    for(int i=1;i<N;i++){
        int x, y;
        cin >> x >> y;
        edge[y].push_back(x);
        edge[x].push_back(y);
    }
}

/**
 * For Leaf node, there is only one node in the subtree.
 * So you just memorize for node x it have black node or not.
*/
int dfs(int x){
    if(visited[x])
        return -1;
    visited[x] = 1;
    int blackCnt = black[x];
    dp[x][black[x]][0] = 1;
    dp[x][black[x]][1] = 1;
    /**
     * For non-leaf node, you have to calculate the number of 
     * subtree for each child node from count of black node.
    */
    for(int next: edge[x]){
        int ret = dfs(next);
        if(ret < 0) continue;
        int j, j1, j2;
        int dp_cp[5001][2];
        /**
         * For each child, find the max subtree and min subtree size
         * for each count of black node
         * Node with out copying memory, the intended value can be corrupted
        */
        for(int i=black[x];i<=blackCnt + ret;i++){
            dp_cp[i][0] = dp[x][i][0];
            dp_cp[i][1] = dp[x][i][1];
        }
        /**
         * Compute from the number of black nodes
         * for every possible pairs.
        */
        for(int j1 = black[x]; j1 <= blackCnt; j1 ++){
            for(int j2 = 0; j2 <= ret; j2 ++){
                j = j1 + j2;
                dp[x][j][0] = max(dp[x][j][0], dp_cp[j1][0] + dp[next][j2][0]);
                dp[x][j][1] = min(dp[x][j][1], dp_cp[j1][1] + dp[next][j2][1]); 
             }
        }              
        blackCnt += ret;
    }
    /**
     * Return the number of black node in the subtree of node x
     * that have max size
    */
    return blackCnt;
}

/**
 * From dfs result, you can find
 * the range of tree size that have j black nodes
 * for every root node.
 * you should combine it into table without root node information.
 * Or, you will get time limit exceeded.
*/
void prepare_answer_table(){
    for(int i=1;i<=N;i++){
        for(int j=0;j<=B;j++){
           ansTable[j][0] = max(ansTable[j][0], dp[i][j][0]);
           ansTable[j][1] = min(ansTable[j][1], dp[i][j][1]);    
        }           
    }

    for(int i=0;i<=B;i++){
        for(int k=ansTable[i][1]; k <= ansTable[i][0];k++)
            ans[k][i] = 1;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();  
    cin >> N >> B;   

    init_dp();

    read_graph();

    dfs(1);
    prepare_answer_table();
    
    int Q;
    int result = 0;
    cin >> Q;
    
    /**
     * If table is prepared, you can just read table and print answer.
    */
    while(Q--){
        int s, b;
        cin >> s >> b;
        result += ans[s][b];
    }
    cout << result << endl;
    return 0;
}