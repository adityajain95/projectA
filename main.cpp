#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define CLR(x)  memset(x,0,sizeof(x))
#define RESET(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;
#define mod 1000000007LL
#define pii pair<int,int>
#define INF 100000000000000001LL
#define N 100019
#define eps 0.0000001

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int a[503][503][4];
ll d[22][503][503];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,i,j;
    cin>>n>>m>>k;
    for(i=0;i<n;i++) {
    	for(j=0;j<m-1;j++) {
    		int x;
    		cin>>x;
    		a[i][j][2] = x;
    		a[i][j+1][3] = x;
    	}
    }

    for(i=0;i<n-1;i++) {
    	for(j=0;j<m;j++) {
    		int x;
    		cin>>x;
    		a[i][j][0] = x;
    		a[i+1][j][1] = x;
    	}
    }

    if(k&1) {
    	for(i=0;i<n;i++) {
    		for(j=0;j<m;j++)
    			cout<<-1<<" ";
    		cout<<endl;
    	}
    	return 0;
    }
    k=k/2;

    for(i=0;i<n;i++) {
		for(j=0;j<m;j++){
			d[0][i][j]=0;
			for(int p=1;p<=k;p++) {
				d[p][i][j] = INF;
			}
		}
	}

	for(int p=1;p<=k;p++) {
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				for(int r=0;r<4;r++) {
					int ni = i + dx[r];
					int nj = j + dy[r];
					if(ni<0 || ni>n || nj<0 || nj>m) continue;
					d[p][ni][nj] = min(d[p][ni][nj], d[p-1][i][j] + a[i][j][r]);
				}
			}
		}
	}

	for(i=0;i<n;i++) {
		for(j=0;j<m;j++)
			cout<<2*d[k][i][j]<<" ";
		cout<<endl;
	}

    return 0;
}