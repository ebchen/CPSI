/*
 ID: bradyawn
 PROG: contest
 LANG: C++11
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;	
typedef pair<int,int> i2;
typedef pair<ll,ll> ll2;

bool vis[26]; //useless

int deg[26];
int degout[26]; //useless

vector<int> adj[26];

bool mat[26][26];

int ans[26];

int n;
char last;

int solve()
{
    queue<int> q;
    
    for (int i = 0; i <= last; i++)
        if (deg[i] == 0) q.push(i);
    
    bool mult = false;
    
    int it = 0;
    while (!q.empty())
    {
        if (q.size() > 1) mult = true; //multiple options
        auto cur = q.front(); q.pop();
        ans[it++] = cur;
        for (auto e : adj[cur])
            if (--deg[e] == 0) q.push(e);
    }
    
    if (it != last+1) return 1;
    
    if (mult) return 0; //multiple options - incomplete
    return -1;
}

int main()
{
    //ifstream inf("");
    //ofstream outf("");
    //cout << setprecision(10);
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> last >> n;
    
    last -= 'a';
    
    string s, p; //cur, prev
    for (int t = 0; t < n; t++)
    {
        cin >> s;
        
        if (p.size() > s.size() && p.substr(0, s.size()) == s)
        {
            cout << 1 << '\n';
            return 0;
        }
        
        for (int i = 0; i < min(s.size(), p.size()); i++)
        {
            if (s[i] != p[i])
            {
                if (mat[p[i]-'a'][s[i]-'a']) break;
                adj[p[i]-'a'].push_back(s[i]-'a');
                mat[p[i]-'a'][s[i]-'a'] = 1;
                degout[p[i]-'a']++;
                deg[s[i]-'a']++;
                break;
            }
        }
        
        p = s;
    }
    
    int ret = solve();
    
    if (ret == -1) {for (int i = 0; i <= last; i++) cout << char(ans[i]+'a'); cout << '\n';}
    else cout << ret << '\n';
    
    return 0;
}


