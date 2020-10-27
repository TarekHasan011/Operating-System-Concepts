#include<bits/stdc++.h>
using namespace std;

bool Is_need_less_than_or_equal_to_work(int work[], int need[200][200], int process_number, int resources)
{
    for(int i=0;i<resources;i++)
    {
        if(need[process_number][i]<=work[i]) continue;
        return false;
    }
    return true;
}

int main()
{
    #ifdef TarekHasan
        freopen("bankersAlgorithminput.txt","r",stdin);
    #endif // TarekHasan


    //resources and capacities or instances
    int resource; cin >> resource;
    int resource_capacity[resource];
    int work[resource];

    for(int i=0;i<resource;i++)
    {
        cin >> resource_capacity[i];
        work[i]=resource_capacity[i];
    }

    //number of process
    int number_of_process; cin >> number_of_process;

    //current allocation
    int current_allocation[number_of_process][resource];

    for(int i=0;i<number_of_process;i++)
    {
        for(int j=0;j<resource;j++) cin >> current_allocation[i][j];
    }

    //maximum allocation
    int maximum_allocation[number_of_process][resource];

    for(int i=0;i<number_of_process;i++)
    {
        for(int j=0;j<resource;j++) cin >> maximum_allocation[i][j];
    }

    //need allocation
    int need[200][200];

    for(int i=0;i<number_of_process;i++)
    {
        for(int j=0;j<resource;j++)
            need[i][j]=maximum_allocation[i][j]-current_allocation[i][j];
    }

    for(int i=0;i<number_of_process;i++)
    {
        for(int j=0;j<resource;j++)
            cout << need[i][j] << " ";
        cout << endl;
    }


    //work

    for(int i=0;i<resource;i++)
    {
        for(int j=0;j<number_of_process;j++)
        {
            work[i]-=current_allocation[j][i];
        }
    }

    bool safe_state = true;
    bool taken[number_of_process]={false};

    vector< int > sequence;


    while(sequence.size()!=number_of_process)
    {
        int starting_size_of_sequence = sequence.size();


        for(int i=0;i<number_of_process;i++)
        {
            if(!taken[i])
            {
                if(Is_need_less_than_or_equal_to_work(work,need,i,resource))
                {
                    sequence.push_back(i);
                    taken[i] = true;
                    for(int j=0;j<resource;j++)
                        work[j]+=current_allocation[i][j];
                }
            }
        }


        int ending_size_of_sequence = sequence.size();

        if(starting_size_of_sequence==ending_size_of_sequence)
        {
            safe_state = false;
            break;
        }
    }

    if(safe_state)
    {
        cout << "Safe State\n";
        cout << "Sequence: < ";

        for(int i=0;i!=sequence.size();i++) cout << "P" << sequence[i] << " ";
        cout << " >"<< endl;
    }
    else
    {
        cout << "Unsafe state\n";
    }


    return 0;

}
/*
3
10 5 7
5
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/

