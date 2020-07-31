//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3404/

class Solution {
public:
    int findIndex(int count[],int idle[]){
        int max_c=-1,ind=-1;
        for(int i=0;i<26;i++){
            if(count[i]>max_c)
                if(count[i] && idle[i]==0)
                    max_c=count[i],ind=i;
        }
        if(ind!=-1)return ind;
        for(int i=0;i<26;i++){
            if(count[i])return -2;
        }
        return -1;
    }
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)return tasks.size();
        int count[26]={0};
        for(auto v:tasks){
            count[v-'A']++;
        }
        int idle[26]={0};
        int time=0;
        int index=findIndex(count,idle);
        while(index!=-1){
            if(index==-2){
                time++;
                for(int i=0;i<26;i++){
                    if(idle[i]>0)idle[i]--;
                }
            }
            else{
                for(int i=0;i<26;i++){
                    if(idle[i]>0)idle[i]--;
                }
                time++;
                count[index]--;
                idle[index]=n;
            }
            index=findIndex(count,idle);
        }
        return time;
    }
};