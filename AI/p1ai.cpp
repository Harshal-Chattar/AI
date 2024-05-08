#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class p1ai
{
    public :
    int nodes[10],m[10][10];
    bool visited[10];
    int size;
    queue <int> que;
    stack <int> s;
    void BFS();
    void DFS();
    void DFSR(int v);
    void getdata();
    void display();
};

void p1ai ::getdata()
{
    cout<<"\nEnter No of nodes : ";
    cin >> size;
    for(int i = 0; i < size; i++)
    {
        cout<<"\nEnter node : ";
        cin >> nodes[i];
        visited[i] = false;
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            m[i][j] = 0;
        }
    }
    for(int i = 0; i < size; i++)
    {
        int n;
        int temp,index;
        cout<<"\nEnter How many nodes are adjecent to "<<nodes[i]<<" : ";
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cout<<"\nEnter the "<<j+1<<" adjecent node : ";
            cin >> temp;
            for(int k = 0; k < size; k++)
            {
                if(temp == nodes[k])
                {
                    index = k;
                    break;
                }
            }
            m[i][index] = 1;
            m[index][i] = 1;
        } 
    }
}

void p1ai :: BFS()
{
    int temp,index;
    cout<<"\nEnter the starting v : ";
    cin >> temp;
    for(int i = 0; i < size; i++ )
    {
        if(temp == nodes[i])
        {
            index = i;
            break;
        }
    }
    visited[index] = true;
    que.push(index);
    while(!que.empty())
    {
        cout<<nodes[que.front()]<<"\t";
        for(int i = 0; i < size; i++)
        {
            if(m[que.front()][i] == 1 && visited[i] == false)
            {
                que.push(i);
                visited[i] = true;
            }
        }
        que.pop();
    }
}

// recursive code 
void p1ai::DFSR(int v)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (v == nodes[i])
        {
            index = i;
            break;
        }
    }

    visited[index] = true;
    cout << nodes[index] << "\t";

    for (int i = 0; i < size; i++)
    {
        if (m[index][i] == 1 && visited[i] == false)
        {
            DFSR(nodes[i]);
        }
    }
}

void p1ai::DFS()
{
    int temp;
    cout << "\nEnter the starting vertex : ";
    cin >> temp;

    DFSR(temp);

    
    // int index = -1;
    // for (int i = 0; i < size; i++)
    // {
    //     if (temp == nodes[i])
    //     {
    //         index = i;
    //         break;
    //     }
    // }

    // if (index == -1)
    // {
    //     cout << "Starting v not found in the graph.\n";
    //     return;
    // }
}

//  non recursive code 
// void p1ai :: DFS()
// {
//     int temp,index;
//     cout<<"\nEnter the starting v : ";
//     cin >> temp;
//     for(int i = 0; i < size; i++ )
//     {
//         if(temp == nodes[i])
//         {
//             index = i;
//             break;
//         }
//     }
//     visited[index] = true;
//     s.push(index);
//     cout<<nodes[s.top()]<<"\t";
//     while(!s.empty())
//     {
//         int flag = 0;
//         for(int i = 0; i < size; i++)
//         {
//             if(m[s.top()][i] == 1 && visited[i] == false)
//             {
//                 s.push(i);
//                 visited[i] = true;
//                 cout<<nodes[s.top()]<<"\t";
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag == 0)
//         {
//             s.pop();
//         }
//     }
// }

void p1ai :: display()
{
    cout<<"\n";
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<m[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    int n;
    p1ai p;
    p.getdata();
    cout<<"\nEnter your choice  : \n1. BFS Traversal \n2. DFS Traversal \n";
    cin >> n;
    switch (n)
    {
        case 1 : 
        {
            p.BFS();
            break;
        }
        case 2 : 
        {
            p.DFS();
            break;
        }
        default : 
        {
            cout<<"\nInvalid Choice !!";
        }
    }
}



