/*
134. 加油站
在一条单行道上，有 n 个加油站，其中第 i 个加油站可以给汽车加油 gas[i] 升油。你有一辆油箱容量无限的汽车，从第 0 个加油站出发，按顺序经过所有加油站。如果你的油箱里没有足够的油来到达下一个加油站，你就不能继续前进。

给定一个数组 gas 和一个数组 cost，其中 gas[i] 是第 i 个加油站可以加的油量，cost[i] 是从第 i 个加油站到下一个加油站需要消耗的油量。

如果你可以从某个加油站出发并绕环路行驶一周，返回该起点的索引；否则返回 -1。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int i=0;
        while(i<n)
        {
            int sumGas = 0;
            int sumCost = 0;
            int cnt = 0;
            while(cnt<n)
            {
                int j = (i + cnt) % n;
                sumGas += gas[j];
                sumCost += cost[j];
                if(sumCost > sumGas)
                {
                    break;
                }
                cnt++;
            }
            if(cnt==n)
            {
                return i;
            }
            else
            {
                i = i + cnt + 1;
            }
        }return -1;
        }
    int canCompleteCircuit_2(vector<int>& gas, vector<int>& cost)
    {
        int n=gas.size();
        int totSum=0;
        int curSum=0;
        int start=0;
        for (int i = 0; i < n;i++)
        {
            totSum += gas[i] - cost[i];
            curSum += gas[i] - cost[i];
            if(curSum < 0)
            {
                start = i + 1;
                curSum = 0;
            }
        }
        return totSum >= 0 ? start : -1;
    }
    
};

int main() {
    Solution s;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<s.canCompleteCircuit(gas,cost)<<endl;
    cout<<s.canCompleteCircuit_2(gas,cost)<<endl;
    return 0;
}