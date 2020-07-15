#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main(){
    queue <int> q;
    map <int, set <int> > graph;
    set <int> visited;
    int n, m, x, y;
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    q.push(x);
    while(!q.empty()){
        x = q.front();
        visited.insert(x);
        q.pop();
        for (int t : graph[x]){
            if(visited.find(t) == visited.end()){
                q.push(t);
                y = t;
            }
        }
    }
    q.push(y);
    visited.clear();
    m = 0;
    while(!q.empty()){
        x = q.front();
        visited.insert(x);
        q.pop();
        ++m;
        for (int t : graph[x]){
            if(visited.find(t) == visited.end()){
                q.push(t);
                y = t;
            }
        }
    }
    cout << m;
    return 0;

}
/*
7
4 5
6 7
7 4
7 2
1 3
4 1
*/