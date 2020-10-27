#include<bits/stdc++.h>
using namespace std;
#define __delete(v,n) v.erase(remove(v.begin(),v.end(),n),v.end())

const int INF = 0x7f7f7f7f;

int minimum(vector< int > v, int current_head)
{
    int distance = INF;
    int dist_i;
    for(int i=0;i!=v.size();i++)
    {
        if(abs(current_head-v[i])<distance)
        {
            distance = abs(current_head-v[i]);
            dist_i = i;
        }
    }
    return v[dist_i];
}
void SSTF(vector< int > v, int current_head)
{
    vector< int > seq;
    int head_movement = 0;
    while(v.size())
    {
        int prev_head = current_head;
        current_head = minimum(v,prev_head);
        __delete(v,current_head);
        head_movement += abs(prev_head-current_head);
        seq.push_back(prev_head);
    }
    seq.push_back(current_head);

    cout << head_movement << endl;

    for(int x : seq)
        cout << x << " ";
    cout << endl;

}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n; cin >> n;
    vector< int > v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int diff = 0;
    for(int i=1;i!=v.size();i++)
    {
        diff += abs(v[i]-v[i-1]);
    }
    cout << diff << endl;


    /*int n; cin >> n;
    vector< int > v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(int x : v)
        cout << x << " ";
    cout << endl;
    SSTF(v,150);*/
    return 0;
}
