#include <bits/stdc++.h>
using namespace std;
#define ll long long
map <string,int> visited;
int bfs(string start,string to,map<string, vector<string> >graph)
{
    queue<string> s;
    s.push(start);
    visited[start]=0;
    while(s.empty()==false)
    {
        string top=s.front();
        s.pop();
        if(top==to)
        {
            return visited[top];
        }
        int tot=graph[top].size();
        for(int i=0;i<tot;i++)
        {
            if(!visited.count(graph[top][i]))
            {
                visited[graph[top][i]]=visited[top]+1;
                s.push(graph[top][i]);
            }
        }
    }

}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        map<string, vector <string> > graph;
        string word,tmp;
        cin>>word;
        while(word!="*")
        {
            graph[word];
         map<string, vector <string> >:: const_iterator it;
         int d=0;
         for(it=graph.begin();it!=graph.end();it++)
         {
             tmp=(*it).first;
             int tm=tmp.size();
             d=0;
             if(tm==word.size())
             {
                 for(int i=0;i<tm && d<0;i++)
                 {
                     if(tmp[i]!=word[i])
                     {
                         d++;
                     }
                 }
                 if(d==1)
                 {
                     graph[tmp].push_back(word);
                     graph[word].push_back(tmp);
                 }
             }
         }
         cin>>word;
        }
        string start,to,line;
        size_t pos;
        getline(cin,line);
        getline(cin,line);
        while(line!="")
        {
            pos=line.find(" ");
            start=line.substr(0,pos);
            to=line.substr(pos+1,line.size());
            visited.clear();
            cout<<start<<" "<<to<<" "<<bfs(start,to,graph)<<endl;
            if(!getline(cin,line))
                break;
        }
        if(n!=0)
            cout<<endl;
    }
    return 0;

}
