#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    string name;
    int burst_time;
    int arrival_time;
    int completion_time;
};
bool compare(process a, process b)
{
    return a.arrival_time<b.arrival_time;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    vector< process > processes;
    int number_of_processes;

    while(cin >> number_of_processes)
    {
        int time = 0;

        for(int i=0;i<number_of_processes;i++)
        {
            process p;
            cin >> p.id >> p.name >> p.burst_time >> p.arrival_time;
            processes.push_back(p);
        }
        sort(processes.begin(),processes.end(),compare);
        int average_turnaround_time=0;

        for(process &p : processes)
        {
            p.completion_time=max(p.arrival_time+p.burst_time,time+p.burst_time);
            time = p.completion_time;
        }

        double ATT = 0;

        int cases = 0;

        for(process &p : processes)
        {
            cout << ++cases << " " << p.name << " " << p.completion_time-p.burst_time << "-" << p.completion_time << " " << p.completion_time-p.arrival_time << endl;
            ATT+=(p.completion_time-p.arrival_time);
        }
        cout << "A.T.T = ";
        cout << (ATT/processes.size()) << endl << endl;
    }

    return 0;

}
/*
test cases:
given input:
3
01 A 40 0
02 B 50 0
03 C 10 5
2
04 D 20 38
05 E 15 25

output:
1 A 0-40 40
2 B 40-90 90
3 C 90-100 95
A.T.T = 75

1 A 0-40 40
2 B 40-90 90
3 C 90-100 95
4 E 100-115 90
5 D 115-135 97
A.T.T = 82.4

input:
4
1 A 5 0
2 B 6 0
3 C 4 5
4 D 10 17
output:
1 A 0-5 5
2 B 5-11 11
3 C 11-15 10
4 D 17-27 10
A.T.T = 9

input:
5
1 A 5 0
2 B 6 0
3 C 8 0
4 D 2 0
5 E 3 23
output:
1 A 0-5 5
2 B 5-11 11
3 C 11-19 19
4 D 19-21 21
5 E 23-26 3
A.T.T = 11.8

input:
4
1 A 5 2
2 B 6 7
3 C 4 13
4 D 10 17
output:
1 A 2-7 5
2 B 7-13 6
3 C 13-17 4
4 D 17-27 10
A.T.T = 6.25
*/



