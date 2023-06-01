# LeetCode每日一题汇总版(C++版)



# 1110. 删点成林

## 1. 原题

**<font color="#dd0000">原题链接：</font>**https://leetcode.cn/problems/delete-nodes-and-return-forest/

**<font color="#dd0000">难度：</font><font color="#00dd00">中等</font>**

**<font color="#dd0000">1110. 删点成林</font>**

<font color="#0000dd">给出二叉树的根节点 root，树上每个节点都有一个不同的值。如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。返回森林中的每棵树。你可以按任意顺序组织答案。</font>  

**<font color="#dd0000">示例1 :</font>**

![image-20230530152443597](E:\algorithmCode\leetcode\每日一题\img\image-1110-删点成林.png)

```c++
输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]
```

**<font color="#dd0000">示例2 :</font>**

```c++
输入：root = [1,2,4,null,3], to_delete = [3]
输出：[[1,2,4]]
```

**<font color="#dd0000">提示 :</font>**

> 1. 树中的节点数最大为 1000。
> 2. 每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
> 3. to_delete.length <= 1000
> 4. to_delete 包含一些从 1 到 1000、各不相同的值。





## 2. 思路

><font color="#dd00dd">1. 使用BFS来遍历整个树，遍历过程中判断是否需要删除当前节点p；（变量：Q用于遍历,Q_parent保存Q中元素对应的父节点，to_delete_S集合方便判断节点是否需要删除）</font>
>
><font color="#dd00dd">2.遍历过程 ：每次从队列中取出一个节点p，将p的左右节点加入到队列Q中，然后判断当前节点p是否需要删除，是否删除的情况将影响p的左右节点的父节点Q_parent中的取值，①p需要删除：要将p节点与左右节点和父节点的连接删除(指针置空)，p的左右节点的父节点置为空；②p不需要删除：如果p的父节点为空，则说明p为新树的根节点，将其加入到ans中，最后将p的左右节点的父节点设为p。</font>

## 3. 代码

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        queue<TreeNode*> Q,Q_parent;//Q用于广度优先搜索，Q_parent用来记录当前节点的父节点
        vector<TreeNode*> ans;//保存答案
        set<int> to_delete_S;//to_delete_S集合保存需要删除的节点
        for(int x: to_delete) to_delete_S.insert(x);
        if(root==nullptr) return ans;
        
        //【广度优先遍历】
        Q.push(root);
        Q_parent.push(nullptr);
        while(!Q.empty()){
            //【取队首节点并出队】
            TreeNode* p = Q.front(),*p_parent = Q_parent.front();//获取队首节点p，以及p的父节点
            Q.pop();Q_parent.pop();//两个队列同步出队
            //【新节点入队】
            if(p->left!=nullptr) Q.push(p->left);
            if(p->right!=nullptr) Q.push(p->right);

            //【判断是否需要删除当前节点p】
            if(to_delete_S.count(p->val)){//-【存在与to_delete中，需要删除】
                //【如果p节点的父节点p_parent不为空，则需要将p_parent与p之间的连接删除】
                if(p_parent!=nullptr){
                    if(p_parent->left!=nullptr && p_parent->left->val==p->val) p_parent->left=nullptr;
                    if(p_parent->right!=nullptr && p_parent->right->val==p->val) p_parent->right=nullptr;
                }
                //【因为当前节点p需要删除，所以需要将p的左右节点的父节点设为空，并将p的left和right置为空】
                if(p->left!=nullptr) Q_parent.push(nullptr);
                if(p->right!=nullptr) Q_parent.push(nullptr);
                p->left=nullptr;
                p->right=nullptr;
            }else{//-【不进行删除】
                //【由于当前节点p是不需要删除的，所以将p的左右节点的父节点设为p】
                if(p->left!=nullptr) Q_parent.push(p);
                if(p->right!=nullptr) Q_parent.push(p);
                //【如果p_parent为空，说明p节点作为树的根节点，需要加入到ans中】
                if(p_parent==nullptr){
                    ans.push_back(p);
                }
            }
        }
        return ans;
    }
};
```



---------------------

# 2517. 礼盒的最大甜蜜度

## 1. 原题

**<font color="#dd0000">原题链接：</font>**https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/

**<font color="#dd0000">难度：</font><font color="#00dd00">中等</font>**

**<font color="#dd0000">2517. 礼盒的最大甜蜜度</font>**

<font color="#0000dd">给你一个正整数数组 price ，其中 price[i] 表示第 i 类糖果的价格，另给你一个正整数 k 。商店组合 k 类 不同 糖果打包成礼盒出售。礼盒的 甜蜜度 是礼盒中任意两种糖果 价格 绝对差的最小值。返回礼盒的 最大 甜蜜度。</font>  

**<font color="#dd0000">示例1 :</font>**

```c++
输入：price = [13,5,1,8,21,2], k = 3
输出：8
解释：选出价格分别为 [13,5,21] 的三类糖果。
礼盒的甜蜜度为 min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8 。
可以证明能够取得的最大甜蜜度就是 8 。
```

**<font color="#dd0000">示例2 :</font>**

```c++
输入：price = [1,3,1], k = 2
输出：2
解释：选出价格分别为 [1,3] 的两类糖果。 
礼盒的甜蜜度为 min(|1 - 3|) = min(2) = 2 。
可以证明能够取得的最大甜蜜度就是 2 。
```

**<font color="#dd0000">示例3 :</font>**

```c++
输入：price = [7,7,7,7], k = 2
输出：0
解释：从现有的糖果中任选两类糖果，甜蜜度都会是 0 。
```

**<font color="#dd0000">提示 :</font>**

> 1. `1 <= price.length <= 105`
> 2. `1 <= price[i] <= 109`
> 3. `2 <= k <= price.length`



## 2. 思路

><font color="#dd00dd">思路：由题意可知"甜蜜度"的范围取值为[0,max_price-min_price]， 那么我们可以尝试"甜蜜度"的所有可能，判断"甜蜜度"=mid是否可以通过选取k个糖果而获得； 遍历"甜蜜度"的所有可能时课采用二分查找；判断函数check选取k个糖果可采用贪心算法（只要当前选取的糖果与前一个选取的糖果的差值>=mid，就可以将该糖果加入到礼盒，依次类推）；</font>

## 3. 代码

```c++
class Solution {
public:
/*思路：由题意可知"甜蜜度"的范围取值为[0,max_price-min_price]，
        那么我们可以尝试"甜蜜度"的所有可能，判断"甜蜜度"=mid是否可以通过选取k个糖果而获得；
        遍历"甜蜜度"的所有可能时课采用二分查找；
        判断函数check选取k个糖果可采用贪心算法（只要当前选取的糖果与前一个选取的糖果的差值>=mid，就可以将该糖果加入到礼盒，依次类推）；
        */
    bool check(vector<int>& price,int k,int mid){
        int count = 0,pre_price = -INT_MAX/2;
        for(int p : price){
            if(p - pre_price >= mid){
                count++;
                pre_price = p;
            }
            if(count>=k) return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int left=0,right=price[price.size()-1]-price[0];
        while(left<right){
            int mid = (left+right+1)/2;
            if(check(price,k,mid)){//可以满足"甜蜜度"=mid
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};
```





















