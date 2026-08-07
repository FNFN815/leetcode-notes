/*380. O(1) 时间插入、删除和获取随机元素
实现RandomizedSet 类：
RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；
否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；
否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。
每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
*/

#include<vector>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
class RandomizedSet {
    private:
    vector<int> nums;
    unordered_map<int,int> valToIndex;
    public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(valToIndex.count(val))
        {
            return false;
        }
        int index = nums.size();
        nums.push_back(val);
        valToIndex[val] = index;
        return true;
    }

    
    bool remove(int val) {
        if(!valToIndex.count(val))
        {
            return false;
        }
        int index=valToIndex[val];
        int last=nums.back();
        nums[index]=last;
        valToIndex[last]=index;
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }

};
int main(){
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    int param_3 = obj->getRandom();
    bool param_2 = obj->remove(1);
    cout<<param_1<<" "<<param_2<<" "<<param_3<<endl;
    return 0;
}