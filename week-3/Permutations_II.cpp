/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>uniquepermutations(vector<int>nums){
    sort(nums.begin(),nums.end());
vector<vector<int>>res;
backtrack(nums,0,nums.size(),res);
return res;
}
void backtrack(vector<int>&nums,int low,int high,vector<vector<int>>&res){
if(low==high-1){
    res.push_back(nums);
    return;
}
for(int i=low;i<high;i++){
    if(low!=i&&(nums[low]=nums[i])){
        continue;
    }
    swap(nums[i],nums[low]);
    backtrack(nums,low+1,high,res);
}
}
