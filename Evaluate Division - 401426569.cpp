/*
Author : Poojan Thaker 
Problem name : Evaluate Division
Runtime : 4 ms 
Memory : 8.8 MB
Problem link : https://leetcode.com/problems/evaluate-division/
*/
class Solution {
public:
        vector<string> path(string start,string end, unordered_map<string,vector<string>>& adj){
                queue<string> q;
        unordered_set<string> visited;
        unordered_map<string,string> parent;
                q.push(start);
        visited.insert(start);
                while(!q.empty()){
            string t = q.front();
            if(t==end)break;
            q.pop();
            for(auto x:adj[t]){
                if(!visited.count(x)){
                    visited.insert(x);
                    q.push(x);
                    parent[x]=t;
                }
            }
        }
            vector<string> ans;
        if(!visited.count(end))return ans;
        string pp = end;
                while(pp!=start){
            ans.push_back(pp);
            pp=parent[pp];
        }
                ans.push_back(start);
        reverse(ans.begin(),ans.end());
        return ans;
    }
                vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<string>> adj;
        map<pair<string,string>,double> vals;
                int i=0;
        for(auto x:equations){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            vals[{x[0],x[1]}]=values[i];
            vals[{x[1],x[0]}]=1.0/values[i];
            i++;
        }
        vector<double> qans;
        for(auto q:queries){
            string start = q[0];
            string end = q[1];
                        if(!adj.count(q[0])||!adj.count(q[1])){
                qans.push_back(-1);
                continue;
            }
                        if(q[0]==q[1]){
                qans.push_back(1);
                continue;
            }
            vector<string> path1 = path(start,end,adj);
            if(path1.empty()){
                // cout<<"this";
                qans.push_back(-1);
                continue;
            }
            for(auto x:path1){
                cout<<x<<" ";
            }
            cout<<endl;
            double ans=1;
            for(int i=1;i<path1.size();i++){
                ans*=vals[{path1[i-1],path1[i]}];
            }
            qans.push_back(ans);
        }
                return qans;
    }
};
