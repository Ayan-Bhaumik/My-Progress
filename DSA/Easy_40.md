# Easy — 40 Problems

## 1. Two Sum

**Problem**

Given an integer array and target, return indices of two different values whose sum is target. Assume one valid pair exists.

**Reasoning**

Use a hash map from value to its index. For each x, look for target-x before inserting x. This avoids using the same position twice.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> twoSum(vector<int>& a,int t){ unordered_map<int,int> mp; for(int i=0;i<(int)a.size();++i){ int need=t-a[i]; if(mp.count(need)) return {mp[need],i}; mp[a[i]]=i; } return {}; }
};
```

**Test cases**

Example: a=[2,7,11,15], t=9 -> [0,1]
Example: a=[3,2,4], t=6 -> [1,2]

**Complexity** — O(n) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int* twoSum(int* a,int n,int target,int* returnSize){
    int *r=malloc(2*sizeof(int)); *returnSize=0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(a[i]+a[j]==target){r[0]=i;r[1]=j;*returnSize=2;return r;}
    return r;
}
```

**Python 3 Solution**

```python
class Solution:
    def twoSum(self, nums, target):
        seen = {}
        for i, x in enumerate(nums):
            need = target - x
            if need in seen:
                return [seen[need], i]
            seen[x] = i
        return []
```

---

## 2. Valid Anagram

**Problem**

Determine whether two strings contain exactly the same letters with the same frequencies.

**Reasoning**

Count each character in the first string and subtract using the second. Any non-zero count means the strings differ.

**C++17 Solution**

```cpp
class Solution { public:
 bool isAnagram(string s,string t){ if(s.size()!=t.size()) return false; array<int,26> c{}; for(char x:s) ++c[x-'a']; for(char x:t) --c[x-'a']; return all_of(c.begin(),c.end(),[](int x){return x==0;}); }
};
```

**Test cases**

("anagram","nagaram") -> true
("rat","car") -> false

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
#include <stdbool.h>
#include <string.h>
bool isAnagram(char* s,char* t){int c[26]={0};if(strlen(s)!=strlen(t))return false;for(int i=0;s[i];i++){c[s[i]-'a']++;c[t[i]-'a']--;}for(int i=0;i<26;i++)if(c[i])return false;return true;}
```

**Python 3 Solution**

```python
class Solution:
    def isAnagram(self, s, t):
        if len(s) != len(t): return False
        cnt = [0] * 26
        for a, b in zip(s, t):
            cnt[ord(a)-97] += 1
            cnt[ord(b)-97] -= 1
        return all(x == 0 for x in cnt)
```

---

## 3. Contains Duplicate

**Problem**

Return true if any value appears at least twice.

**Reasoning**

Insert each number into a set. If insertion fails, the value has already appeared.

**C++17 Solution**

```cpp
class Solution { public:
 bool containsDuplicate(vector<int>& a){ unordered_set<int> s; for(int x:a) if(!s.insert(x).second) return true; return false; }
};
```

**Test cases**

[1,2,3,1] -> true
[1,2,3,4] -> false

**Complexity** — O(n) average time, O(n) space

---

**C Solution**

```c
#include <stdbool.h>
#include <stdlib.h>
bool containsDuplicate(int* a,int n){int* b=malloc(n*sizeof(int));for(int i=0;i<n;i++)b[i]=a[i];for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(b[i]==b[j]){free(b);return true;}free(b);return false;}
```

**Python 3 Solution**

```python
class Solution:
    def containsDuplicate(self, nums):
        return len(nums) != len(set(nums))
```

---

## 4. Best Time to Buy and Sell Stock

**Problem**

Choose one day to buy and a later day to sell for maximum profit.

**Reasoning**

Keep the smallest price seen so far. Selling today gives price-minPrice, so update the best profit each day.

**C++17 Solution**

```cpp
class Solution { public:
 int maxProfit(vector<int>& p){ int mn=INT_MAX,ans=0; for(int x:p){ mn=min(mn,x); ans=max(ans,x-mn); } return ans; }
};
```

**Test cases**

[7,1,5,3,6,4] -> 5
[7,6,4,3,1] -> 0

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int maxProfit(int* p,int n){int low=p[0],ans=0;for(int i=1;i<n;i++){if(p[i]<low)low=p[i];if(p[i]-low>ans)ans=p[i]-low;}return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def maxProfit(self, prices):
        low, ans = float('inf'), 0
        for p in prices:
            low = min(low, p)
            ans = max(ans, p - low)
        return ans
```

---

## 5. Valid Palindrome

**Problem**

Ignoring non-alphanumeric characters and case, decide whether a string reads the same forward and backward.

**Reasoning**

Use two pointers. Skip characters that do not matter, compare lowercase versions, then move inward.

**C++17 Solution**

```cpp
class Solution { public:
 bool isPalindrome(string s){ int l=0,r=(int)s.size()-1; while(l<r){ while(l<r && !isalnum((unsigned char)s[l])) ++l; while(l<r && !isalnum((unsigned char)s[r])) --r; if(tolower((unsigned char)s[l])!=tolower((unsigned char)s[r])) return false; ++l; --r; } return true; }
};
```

**Test cases**

"A man, a plan, a canal: Panama" -> true
"race a car" -> false

**Complexity** — O(n) time, O(1) extra space

---

**C Solution**

```c
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
bool isPalindrome(char* s){int l=0,r=(int)strlen(s)-1;while(l<r){while(l<r&&!isalnum((unsigned char)s[l]))l++;while(l<r&&!isalnum((unsigned char)s[r]))r--;if(tolower((unsigned char)s[l])!=tolower((unsigned char)s[r]))return false;l++;r--;}return true;}
```

**Python 3 Solution**

```python
class Solution:
    def isPalindrome(self, s):
        t = ''.join(c.lower() for c in s if c.isalnum())
        return t == t[::-1]
```

---

## 6. Merge Two Sorted Lists

**Problem**

Merge two sorted singly linked lists into one sorted list.

**Reasoning**

Use a dummy node and repeatedly attach the smaller current node. Append the remaining suffix when one list ends.

**C++17 Solution**

```cpp
class Solution { public:
 ListNode* mergeTwoLists(ListNode* a,ListNode* b){ ListNode d; auto* cur=&d; while(a&&b){ if(a->val<b->val) cur->next=a,a=a->next; else cur->next=b,b=b->next; cur=cur->next; } cur->next=a?a:b; return d.next; }
};
```

**Test cases**

[1,2,4] + [1,3,4] -> [1,1,2,3,4,4]
[] + [] -> []

**Complexity** — O(n+m) time, O(1) extra space

---

**C Solution**

```c
typedef struct ListNode{int val;struct ListNode* next;}ListNode;
ListNode* mergeTwoLists(ListNode* a,ListNode* b){ListNode d={0,0},*c=&d;while(a&&b){if(a->val<=b->val)c->next=a,a=a->next;else c->next=b,b=b->next;c=c->next;}c->next=a?a:b;return d.next;}
```

**Python 3 Solution**

```python
class Solution:
    def mergeTwoLists(self, a, b):
        d = cur = ListNode(0)
        while a and b:
            if a.val <= b.val:
                cur.next, a = a, a.next
            else:
                cur.next, b = b, b.next
            cur = cur.next
        cur.next = a or b
        return d.next
```

---

## 7. Valid Parentheses

**Problem**

Check whether brackets (), [], {} are correctly opened and closed.

**Reasoning**

Push opening brackets. A closing bracket is valid only when it matches the stack top.

**C++17 Solution**

```cpp
class Solution { public:
 bool isValid(string s){ stack<char> st; for(char c:s){ if(c=='('||c=='['||c=='{') st.push(c); else { if(st.empty()) return false; char o=st.top(); st.pop(); if((c==')'&&o!='(')||(c==']'&&o!='[')||(c=='}'&&o!='{')) return false; } } return st.empty(); }
};
```

**Test cases**

"()[]{}" -> true
"([)]" -> false
"{" -> false

**Complexity** — O(n) time, O(n) space

---

**C Solution**

```c
#include <stdbool.h>
#include <stdlib.h>
bool isValid(char* s){char st[10000];int top=0;for(int i=0;s[i];i++){char c=s[i];if(c=='('||c=='['||c=='{')st[top++]=c;else{if(!top)return false;char x=st[--top];if((c==')'&&x!='(')||(c==']'&&x!='[')||(c=='}'&&x!='{'))return false;}}return top==0;}
```

**Python 3 Solution**

```python
class Solution:
    def isValid(self, s):
        st = []
        pair = {')':'(', ']':'[', '}':'{'}
        for c in s:
            if c in '([{': st.append(c)
            elif not st or st.pop() != pair[c]: return False
        return not st
```

---

## 8. Binary Search

**Problem**

Find target in a sorted array; return its index or -1.

**Reasoning**

Keep a search interval [l,r]. Compare the middle value and discard the half that cannot contain target.

**C++17 Solution**

```cpp
class Solution { public:
 int search(vector<int>& a,int t){ int l=0,r=(int)a.size()-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]==t) return m; if(a[m]<t) l=m+1; else r=m-1; } return -1; }
};
```

**Test cases**

[1,2,3,4,5],4 -> 3
[1,2,3],6 -> -1

**Complexity** — O(log n) time, O(1) space

---

**C Solution**

```c
int search(int* a,int n,int t){int l=0,r=n-1;while(l<=r){int m=l+(r-l)/2;if(a[m]==t)return m;if(a[m]<t)l=m+1;else r=m-1;}return -1;}
```

**Python 3 Solution**

```python
class Solution:
    def search(self, nums, target):
        l, r = 0, len(nums)-1
        while l <= r:
            m = (l+r)//2
            if nums[m] == target: return m
            if nums[m] < target: l = m+1
            else: r = m-1
        return -1
```

---

## 9. Flood Fill

**Problem**

Starting from a cell, recolor all 4-directionally connected cells having the original color.

**Reasoning**

DFS/BFS from the start cell. Change a cell as soon as it is visited so it cannot be processed twice.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<int>> floodFill(vector<vector<int>>& a,int sr,int sc,int color){ int old=a[sr][sc]; if(old==color) return a; int n=a.size(),m=a[0].size(); queue<pair<int,int>> q; q.push({sr,sc}); a[sr][sc]=color; int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1}; while(!q.empty()){ auto [r,c]=q.front(); q.pop(); for(int k=0;k<4;k++){ int nr=r+dr[k],nc=c+dc[k]; if(nr>=0&&nr<n&&nc>=0&&nc<m&&a[nr][nc]==old){ a[nr][nc]=color; q.push({nr,nc}); } } } return a; }
};
```

**Test cases**

[[1,1,1],[1,1,0],[1,0,1]], (1,1),2 -> [[2,2,2],[2,2,0],[2,0,1]]

**Complexity** — O(R*C) time, O(R*C) worst-case space

---

**C Solution**

```c
int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
void paint(int** g,int R,int C,int r,int c,int old,int color){g[r][c]=color;for(int k=0;k<4;k++){int nr=r+dr[k],nc=c+dc[k];if(nr>=0&&nr<R&&nc>=0&&nc<C&&g[nr][nc]==old)paint(g,R,C,nr,nc,old,color);}}
int** floodFill(int** image,int imageSize,int* imageColSize,int sr,int sc,int color){int old=image[sr][sc];if(old!=color)paint(image,imageSize,*imageColSize,sr,sc,old,color);return image;}
```

**Python 3 Solution**

```python
class Solution:
    def floodFill(self, image, sr, sc, color):
        old = image[sr][sc]
        if old == color: return image
        R, C = len(image), len(image[0])
        st = [(sr,sc)]; image[sr][sc] = color
        for r,c in st:
            for dr,dc in ((1,0),(-1,0),(0,1),(0,-1)):
                nr,nc=r+dr,c+dc
                if 0<=nr<R and 0<=nc<C and image[nr][nc]==old:
                    image[nr][nc]=color; st.append((nr,nc))
        return image
```

---

## 10. Best Time with One Transaction

**Problem**

Return the maximum profit from one buy followed by one later sell.

**Reasoning**

Same one-pass invariant as the stock problem: minimum purchase price and best gain so far.

**C++17 Solution**

```cpp
class Solution { public:
 int maxProfit(vector<int>& p){ int mn=p[0],ans=0; for(int i=1;i<(int)p.size();++i){ ans=max(ans,p[i]-mn); mn=min(mn,p[i]); } return ans; }
};
```

**Test cases**

[2,4,1] -> 2
[1] -> 0

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int maxProfit2(int* p,int n){int low=p[0],ans=0;for(int i=1;i<n;i++){if(p[i]<low)low=p[i];if(p[i]-low>ans)ans=p[i]-low;}return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def maxProfit(self, prices):
        best_buy, ans = float('inf'), 0
        for p in prices:
            best_buy = min(best_buy, p)
            ans = max(ans, p-best_buy)
        return ans
```

---

## 11. Single Number

**Problem**

Every value appears twice except one value that appears once. Return the single value.

**Reasoning**

XOR cancels equal numbers because x^x=0 and 0^x=x.

**C++17 Solution**

```cpp
class Solution { public:
 int singleNumber(vector<int>& a){ int x=0; for(int v:a) x^=v; return x; }
};
```

**Test cases**

[2,2,1] -> 1
[4,1,2,1,2] -> 4

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int singleNumber(int* a,int n){int x=0;for(int i=0;i<n;i++)x^=a[i];return x;}
```

**Python 3 Solution**

```python
class Solution:
    def singleNumber(self, nums):
        ans = 0
        for x in nums: ans ^= x
        return ans
```

---

## 12. Majority Element

**Problem**

Find the value occurring more than n/2 times.

**Reasoning**

Boyer-Moore voting keeps a candidate and a counter. The majority cannot be canceled by all other values.

**C++17 Solution**

```cpp
class Solution { public:
 int majorityElement(vector<int>& a){ int cand=0,cnt=0; for(int x:a){ if(cnt==0)cand=x; cnt += (x==cand?1:-1); } return cand; }
};
```

**Test cases**

[3,2,3] -> 3
[2,2,1,1,1,2,2] -> 2

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int majorityElement(int* a,int n){int cand=0,c=0;for(int i=0;i<n;i++){if(c==0)cand=a[i];c+=a[i]==cand?1:-1;}return cand;}
```

**Python 3 Solution**

```python
class Solution:
    def majorityElement(self, nums):
        cand = count = 0
        for x in nums:
            if count == 0: cand = x
            count += 1 if x == cand else -1
        return cand
```

---

## 13. Move Zeroes

**Problem**

Move all zeros to the end while keeping the relative order of non-zero values.

**Reasoning**

Write non-zero elements from left to right, then fill the remainder with zeroes.

**C++17 Solution**

```cpp
class Solution { public:
 void moveZeroes(vector<int>& a){ int j=0; for(int x:a) if(x) a[j++]=x; while(j<(int)a.size()) a[j++]=0; }
};
```

**Test cases**

[0,1,0,3,12] -> [1,3,12,0,0]
[0] -> [0]

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
void moveZeroes(int* a,int n){int j=0;for(int i=0;i<n;i++)if(a[i])a[j++]=a[i];while(j<n)a[j++]=0;}
```

**Python 3 Solution**

```python
class Solution:
    def moveZeroes(self, nums):
        j = 0
        for x in nums:
            if x: nums[j] = x; j += 1
        while j < len(nums): nums[j] = 0; j += 1
```

---

## 14. Reverse Linked List

**Problem**

Reverse a singly linked list in place.

**Reasoning**

Maintain prev and cur. Save cur->next, point cur back to prev, then advance both pointers.

**C++17 Solution**

```cpp
class Solution { public:
 ListNode* reverseList(ListNode* h){ ListNode* prev=nullptr; while(h){ auto* nxt=h->next; h->next=prev; prev=h; h=nxt; } return prev; }
};
```

**Test cases**

[1,2,3,4] -> [4,3,2,1]
[] -> []

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
typedef struct ListNode{int val;struct ListNode* next;}ListNode;
ListNode* reverseList(ListNode* h){ListNode*p=0,*n;while(h){n=h->next;h->next=p;p=h;h=n;}return p;}
```

**Python 3 Solution**

```python
class Solution:
    def reverseList(self, head):
        prev = None
        while head:
            nxt = head.next; head.next = prev; prev = head; head = nxt
        return prev
```

---

## 15. Linked List Cycle

**Problem**

Determine whether a linked list contains a cycle.

**Reasoning**

Floyd’s slow/fast pointers meet if and only if a cycle exists.

**C++17 Solution**

```cpp
class Solution { public:
 bool hasCycle(ListNode* h){ ListNode *s=h,*f=h; while(f&&f->next){ s=s->next; f=f->next->next; if(s==f) return true; } return false; }
};
```

**Test cases**

1->2->3->2 ... -> true
1->2->null -> false

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
#include <stdbool.h>
typedef struct ListNode{int val;struct ListNode* next;}ListNode;
bool hasCycle(ListNode* h){ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;if(s==f)return true;}return false;}
```

**Python 3 Solution**

```python
class Solution:
    def hasCycle(self, head):
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow is fast: return True
        return False
```

---

## 16. Invert Binary Tree

**Problem**

Swap the left and right children of every binary-tree node.

**Reasoning**

For each node, swap its children and recursively invert both subtrees.

**C++17 Solution**

```cpp
class Solution { public:
 TreeNode* invertTree(TreeNode* r){ if(!r) return nullptr; swap(r->left,r->right); invertTree(r->left); invertTree(r->right); return r; }
};
```

**Test cases**

[4,2,7,1,3,6,9] -> [4,7,2,9,6,3,1]

**Complexity** — O(n) time, O(h) recursion space

---

**C Solution**

```c
typedef struct TreeNode{int val;struct TreeNode* left,*right;}TreeNode;
TreeNode* invertTree(TreeNode* r){if(!r)return 0;TreeNode*t=r->left;r->left=invertTree(r->right);r->right=invertTree(t);return r;}
```

**Python 3 Solution**

```python
class Solution:
    def invertTree(self, root):
        if not root: return None
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root
```

---

## 17. Maximum Depth of Binary Tree

**Problem**

Return the number of nodes on the longest root-to-leaf path.

**Reasoning**

Depth of a node is 1 + max(depth(left), depth(right)); null has depth 0.

**C++17 Solution**

```cpp
class Solution { public:
 int maxDepth(TreeNode* r){ return r?1+max(maxDepth(r->left),maxDepth(r->right)):0; }
};
```

**Test cases**

[3,9,20,null,null,15,7] -> 3
[] -> 0

**Complexity** — O(n) time, O(h) space

---

**C Solution**

```c
typedef struct TreeNode{int val;struct TreeNode* left,*right;}TreeNode;
int maxDepth(TreeNode* r){if(!r)return 0;int a=maxDepth(r->left),b=maxDepth(r->right);return 1+(a>b?a:b);}
```

**Python 3 Solution**

```python
class Solution:
    def maxDepth(self, root):
        if not root: return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
```

---

## 18. Climbing Stairs

**Problem**

You may climb 1 or 2 steps. Count ways to reach step n.

**Reasoning**

The last move is from n-1 or n-2, so dp[n]=dp[n-1]+dp[n-2]. Keep only two values.

**C++17 Solution**

```cpp
class Solution { public:
 int climbStairs(int n){ int a=1,b=1; for(int i=0;i<n;i++) tie(a,b)=make_tuple(b,a+b); return a; }
};
```

**Test cases**

n=2 -> 2
n=5 -> 8

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int climbStairs(int n){int a=1,b=1;for(int i=0;i<n;i++){int t=a+b;a=b;b=t;}return a;}
```

**Python 3 Solution**

```python
class Solution:
    def climbStairs(self, n):
        a,b=1,1
        for _ in range(n): a,b=b,a+b
        return a
```

---

## 19. House Robber

**Problem**

Choose non-adjacent houses to maximize stolen money.

**Reasoning**

For each house, either skip it (old best) or rob it plus the best up to i-2.

**C++17 Solution**

```cpp
class Solution { public:
 int rob(vector<int>& a){ int prev2=0,prev1=0; for(int x:a){ int cur=max(prev1,prev2+x); prev2=prev1; prev1=cur; } return prev1; }
};
```

**Test cases**

[1,2,3,1] -> 4
[2,7,9,3,1] -> 12

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int rob(int* a,int n){int p=0,q=0;for(int i=0;i<n;i++){int t=q>p+a[i]?q:p+a[i];p=q;q=t;}return q;}
```

**Python 3 Solution**

```python
class Solution:
    def rob(self, nums):
        prev2 = prev1 = 0
        for x in nums: prev2, prev1 = prev1, max(prev1, prev2+x)
        return prev1
```

---

## 20. Maximum Subarray

**Problem**

Find the maximum sum over any non-empty contiguous subarray.

**Reasoning**

Kadane’s algorithm decides whether to start fresh at x or extend the previous subarray.

**C++17 Solution**

```cpp
class Solution { public:
 int maxSubArray(vector<int>& a){ int cur=a[0],ans=a[0]; for(int i=1;i<(int)a.size();++i){ cur=max(a[i],cur+a[i]); ans=max(ans,cur); } return ans; }
};
```

**Test cases**

[-2,1,-3,4,-1,2,1,-5,4] -> 6
[1] -> 1

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int maxSubArray(int* a,int n){int cur=a[0],ans=a[0];for(int i=1;i<n;i++){cur=(a[i]>cur+a[i])?a[i]:cur+a[i];if(cur>ans)ans=cur;}return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def maxSubArray(self, nums):
        cur=ans=nums[0]
        for x in nums[1:]: cur=max(x,cur+x); ans=max(ans,cur)
        return ans
```

---

## 21. Fizz Buzz

**Problem**

For numbers 1..n output Fizz for multiples of 3, Buzz for 5, both for 15, else the number.

**Reasoning**

Check divisibility by 15 first, then 3 and 5; otherwise convert the number to a string.

**C++17 Solution**

```cpp
class Solution { public:
 vector<string> fizzBuzz(int n){ vector<string> r; for(int i=1;i<=n;i++){ if(i%15==0) r.push_back("FizzBuzz"); else if(i%3==0) r.push_back("Fizz"); else if(i%5==0) r.push_back("Buzz"); else r.push_back(to_string(i)); } return r; }
};
```

**Test cases**

n=5 -> ["1","2","Fizz","4","Buzz"]
n=15 -> ... ,"FizzBuzz"

**Complexity** — O(n) time, O(n) output space

---

**C Solution**

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char** fizzBuzz(int n,int* returnSize){char**r=malloc(n*sizeof(char*));*returnSize=n;for(int i=1;i<=n;i++){r[i-1]=malloc(9);if(i%15==0)strcpy(r[i-1],"FizzBuzz");else if(i%3==0)strcpy(r[i-1],"Fizz");else if(i%5==0)strcpy(r[i-1],"Buzz");else sprintf(r[i-1],"%d",i);}return r;}
```

**Python 3 Solution**

```python
class Solution:
    def fizzBuzz(self, n):
        return ['FizzBuzz' if i%15==0 else 'Fizz' if i%3==0 else 'Buzz' if i%5==0 else str(i) for i in range(1,n+1)]
```

---

## 22. Intersection of Two Arrays

**Problem**

Return distinct values appearing in both arrays.

**Reasoning**

Put all values from the first array in a set, then add matching values from the second to the answer set.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> intersection(vector<int>& a,vector<int>& b){ unordered_set<int>s(a.begin(),a.end()),out; for(int x:b) if(s.count(x)) out.insert(x); return vector<int>(out.begin(),out.end()); }
};
```

**Test cases**

[1,2,2,1],[2,2] -> [2]
[4,9,5],[9,4,9,8,4] -> [4,9]

**Complexity** — O(n+m) average time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int* intersection(int* a,int n,int* b,int m,int* rs){qsort(a,n,sizeof(int),cmp);qsort(b,m,sizeof(int),cmp);int*r=malloc((n<m?n:m)*sizeof(int)),i=0,j=0,k=0;while(i<n&&j<m){if(a[i]<b[j])i++;else if(a[i]>b[j])j++;else{if(k==0||r[k-1]!=a[i])r[k++]=a[i];i++;j++;}}*rs=k;return r;}
```

**Python 3 Solution**

```python
class Solution:
    def intersection(self, a, b):
        return list(set(a) & set(b))
```

---

## 23. Reverse String

**Problem**

Reverse a character array in place.

**Reasoning**

Two pointers swap the outer characters and move inward.

**C++17 Solution**

```cpp
class Solution { public:
 void reverseString(vector<char>& s){ int l=0,r=(int)s.size()-1; while(l<r) swap(s[l++],s[r--]); }
};
```

**Test cases**

["h","e","l","l","o"] -> ["o","l","l","e","h"]

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
void reverseString(char* s,int n){for(int i=0,j=n-1;i<j;i++,j--){char t=s[i];s[i]=s[j];s[j]=t;}}
```

**Python 3 Solution**

```python
class Solution:
    def reverseString(self, s):
        s.reverse()
```

---

## 24. First Unique Character

**Problem**

Return the index of the first character that occurs exactly once, or -1.

**Reasoning**

Count frequencies first, then scan left to right for the first count of one.

**C++17 Solution**

```cpp
class Solution { public:
 int firstUniqChar(string s){ array<int,26> c{}; for(char x:s)++c[x-'a']; for(int i=0;i<(int)s.size();++i) if(c[s[i]-'a']==1)return i; return -1; }
};
```

**Test cases**

"leetcode" -> 0
"loveleetcode" -> 2

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int firstUniqChar(char* s){int c[26]={0};for(int i=0;s[i];i++)c[s[i]-'a']++;for(int i=0;s[i];i++)if(c[s[i]-'a']==1)return i;return -1;}
```

**Python 3 Solution**

```python
class Solution:
    def firstUniqChar(self, s):
        from collections import Counter
        c=Counter(s)
        for i,x in enumerate(s):
            if c[x]==1: return i
        return -1
```

---

## 25. Length of Last Word

**Problem**

Return the length of the final word in a space-separated string.

**Reasoning**

Scan from the end, skip trailing spaces, then count characters until the next space.

**C++17 Solution**

```cpp
class Solution { public:
 int lengthOfLastWord(string s){ int i=(int)s.size()-1; while(i>=0&&s[i]==' ')--i; int ans=0; while(i>=0&&s[i]!=' ')--i,++ans; return ans; }
};
```

**Test cases**

"Hello World" -> 5
"   fly me   to   the moon  " -> 4

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
#include <string.h>
int lengthOfLastWord(char* s){int i=(int)strlen(s)-1;while(i>=0&&s[i]==' ')i--;int ans=0;while(i>=0&&s[i]!=' ')ans++,i--;return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def lengthOfLastWord(self, s):
        return len(s.rstrip().split(' ')[-1])
```

---

## 26. Ransom Note

**Problem**

Return whether the first string can be formed using letters from the second, each source letter usable once.

**Reasoning**

Count source letters, then consume one count per target letter.

**C++17 Solution**

```cpp
class Solution { public:
 bool canConstruct(string a,string b){ array<int,26> c{}; for(char x:b)++c[x-'a']; for(char x:a)if(--c[x-'a']<0)return false; return true; }
};
```

**Test cases**

"a","b" -> false
"aa","aab" -> true

**Complexity** — O(n+m) time, O(1) space

---

**C Solution**

```c
#include <stdbool.h>
#include <string.h>
bool canConstruct(char* r,char* m){int c[26]={0};for(int i=0;m[i];i++)c[m[i]-'a']++;for(int i=0;r[i];i++)if(--c[r[i]-'a']<0)return false;return true;}
```

**Python 3 Solution**

```python
class Solution:
    def canConstruct(self, ransomNote, magazine):
        from collections import Counter
        return not (Counter(ransomNote)-Counter(magazine))
```

---

## 27. Happy Number

**Problem**

Repeatedly replace a number by the sum of squares of its digits. Return whether it reaches 1.

**Reasoning**

The process eventually repeats for non-happy inputs. A set detects the first repeated state.

**C++17 Solution**

```cpp
class Solution { public:
 int sq(int n){ int s=0; while(n){ int d=n%10;n/=10;s+=d*d;} return s; }
 bool isHappy(int n){ unordered_set<int>s; while(n!=1&&!s.count(n)){ s.insert(n); n=sq(n); } return n==1; }
};
```

**Test cases**

19 -> true
2 -> false

**Complexity** — O(log n) per step; O(number of states) space

---

**C Solution**

```c
#include <stdbool.h>
int sq(int n){int s=0;while(n){int d=n%10;s+=d*d;n/=10;}return s;}
bool isHappy(int n){int s=n,f=n;do{s=sq(s);f=sq(sq(f));}while(s!=f);return s==1;}
```

**Python 3 Solution**

```python
class Solution:
    def isHappy(self, n):
        seen=set()
        while n!=1 and n not in seen:
            seen.add(n); n=sum(int(c)**2 for c in str(n))
        return n==1
```

---

## 28. Middle of the Linked List

**Problem**

Return the middle node; for even length, return the second middle.

**Reasoning**

Slow moves one step and fast two. When fast reaches the end, slow is at the required middle.

**C++17 Solution**

```cpp
class Solution { public:
 ListNode* middleNode(ListNode* h){ ListNode*s=h,*f=h; while(f&&f->next){s=s->next;f=f->next->next;} return s; }
};
```

**Test cases**

[1,2,3,4,5] -> node 3
[1,2,3,4,5,6] -> node 4

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
typedef struct ListNode{int val;struct ListNode* next;}ListNode;
ListNode* middleNode(ListNode* h){ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;}return s;}
```

**Python 3 Solution**

```python
class Solution:
    def middleNode(self, head):
        slow=fast=head
        while fast and fast.next: slow,fast=slow.next,fast.next.next
        return slow
```

---

## 29. Remove Duplicates from Sorted Array

**Problem**

Remove duplicates in-place from a sorted array and return the number of unique elements.

**Reasoning**

Keep a write pointer. Every value different from the previous written value is copied once.

**C++17 Solution**

```cpp
class Solution { public:
 int removeDuplicates(vector<int>& a){ int j=0; for(int x:a) if(j==0||a[j-1]!=x) a[j++]=x; return j; }
};
```

**Test cases**

[1,1,2] -> k=2, prefix=[1,2]
[0,0,1,1,1,2,2,3,3,4] -> k=5

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int removeDuplicates(int* a,int n){if(!n)return 0;int k=1;for(int i=1;i<n;i++)if(a[i]!=a[i-1])a[k++]=a[i];return k;}
```

**Python 3 Solution**

```python
class Solution:
    def removeDuplicates(self, nums):
        if not nums: return 0
        j=1
        for i in range(1,len(nums)):
            if nums[i]!=nums[i-1]: nums[j]=nums[i]; j+=1
        return j
```

---

## 30. Merge Sorted Array

**Problem**

Given sorted arrays where the first has extra space, merge the second into the first in-place.

**Reasoning**

Fill from the end so existing values are not overwritten before they are compared.

**C++17 Solution**

```cpp
class Solution { public:
 void merge(vector<int>& a,int m,vector<int>& b,int n){ int i=m-1,j=n-1,k=m+n-1; while(j>=0) a[k--]=(i>=0&&a[i]>b[j])?a[i--]:b[j--]; }
};
```

**Test cases**

[1,2,3,0,0,0],3,[2,5,6],3 -> [1,2,2,3,5,6]

**Complexity** — O(m+n) time, O(1) space

---

**C Solution**

```c
void merge(int* a,int m,int* b,int n){int i=m-1,j=n-1,k=m+n-1;while(j>=0){if(i>=0&&a[i]>b[j])a[k--]=a[i--];else a[k--]=b[j--];}}
```

**Python 3 Solution**

```python
class Solution:
    def merge(self, nums1, m, nums2, n):
        i,j,k=m-1,n-1,m+n-1
        while j>=0:
            if i>=0 and nums1[i]>nums2[j]: nums1[k]=nums1[i]; i-=1
            else: nums1[k]=nums2[j]; j-=1
            k-=1
```

---

## 31. Pascal Triangle

**Problem**

Generate the first n rows of Pascal’s triangle.

**Reasoning**

Each inner value is the sum of the two values above it; edges are always 1.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<int>> generate(int n){ vector<vector<int>> r; for(int i=0;i<n;i++){ r.push_back(vector<int>(i+1,1)); for(int j=1;j<i;j++) r[i][j]=r[i-1][j-1]+r[i-1][j]; } return r; }
};
```

**Test cases**

n=5 -> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

**Complexity** — O(n^2) time, O(n^2) output space

---

**C Solution**

```c
// LeetCode-style dynamic allocation.
int** generate(int n,int* rs,int** cs){int**a=malloc(n*sizeof(int*));*rs=n;*cs=malloc(n*sizeof(int));for(int i=0;i<n;i++){(*cs)[i]=i+1;a[i]=calloc(i+1,sizeof(int));a[i][0]=a[i][i]=1;for(int j=1;j<i;j++)a[i][j]=a[i-1][j-1]+a[i-1][j];}return a;}
```

**Python 3 Solution**

```python
class Solution:
    def generate(self, numRows):
        ans=[]
        for r in range(numRows):
            row=[1]*(r+1)
            for j in range(1,r): row[j]=ans[-1][j-1]+ans[-1][j]
            ans.append(row)
        return ans
```

---

## 32. Majority via Sorting

**Problem**

Find the majority value by sorting the array.

**Reasoning**

After sorting, a value occurring more than half the time must occupy the middle index.

**C++17 Solution**

```cpp
class Solution { public:
 int majorityElement(vector<int>& a){ sort(a.begin(),a.end()); return a[a.size()/2]; }
};
```

**Test cases**

[2,2,1,1,1,2,2] -> 2

**Complexity** — O(n log n) time, O(1) extra space (ignoring sort stack)

---

**C Solution**

```c
#include <stdlib.h>
int cmpi(const void*a,const void*b){return *(int*)a-*(int*)b;}
int majorityElementSort(int* a,int n){qsort(a,n,sizeof(int),cmpi);return a[n/2];}
```

**Python 3 Solution**

```python
class Solution:
    def majorityElement(self, nums):
        nums.sort(); return nums[len(nums)//2]
```

---

## 33. Missing Number

**Problem**

Array contains distinct values from 0..n with one missing. Return the missing value.

**Reasoning**

XOR every index and every value. Equal values cancel, leaving the missing index/value.

**C++17 Solution**

```cpp
class Solution { public:
 int missingNumber(vector<int>& a){ int x=a.size(); for(int i=0;i<(int)a.size();++i) x^=i^a[i]; return x; }
};
```

**Test cases**

[3,0,1] -> 2
[0,1] -> 2

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int missingNumber(int* a,int n){int x=n;for(int i=0;i<n;i++)x^=i^a[i];return x;}
```

**Python 3 Solution**

```python
class Solution:
    def missingNumber(self, nums):
        ans=len(nums)
        for i,x in enumerate(nums): ans ^= i ^ x
        return ans
```

---

## 34. Best Time Unlimited Transactions

**Problem**

Maximize profit when any number of buy/sell transactions are allowed, but only one share at a time.

**Reasoning**

Take every positive day-to-day gain; each rise can be captured by buying before it and selling after it.

**C++17 Solution**

```cpp
class Solution { public: int maxProfit(vector<int>&a){int ans=0;for(int i=1;i<a.size();i++)ans+=max(0,a[i]-a[i-1]);return ans;} };
```

**Test cases**

[7,1,5,3,6,4] -> 7

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int maxProfitUnlimited(int* p,int n){int ans=0;for(int i=1;i<n;i++)if(p[i]>p[i-1])ans+=p[i]-p[i-1];return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def maxProfit(self, prices):
        return sum(max(0,b-a) for a,b in zip(prices,prices[1:]))
```

---

## 35. Intersection of Two Linked Lists

**Problem**

Return the first node shared by two singly linked lists, or null.

**Reasoning**

Walk pointer A through A then B, and pointer B through B then A. They traverse equal total distances and meet at the intersection.

**C++17 Solution**

```cpp
class Solution { public: ListNode* getIntersectionNode(ListNode*a,ListNode*b){auto*x=a,*y=b;while(x!=y){x=x?x->next:b;y=y?y->next:a;}return x;} };
```

**Test cases**

A=[4,1], B=[5,6,1] sharing node 1 -> node 1

**Complexity** — O(n+m) time, O(1) space

---

**C Solution**

```c
typedef struct ListNode{int val;struct ListNode* next;}ListNode;
ListNode* getIntersectionNode(ListNode*a,ListNode*b){ListNode*p=a,*q=b;while(p!=q){p=p?p->next:b;q=q?q->next:a;}return p;}
```

**Python 3 Solution**

```python
class Solution:
    def getIntersectionNode(self, a, b):
        p,q=a,b
        while p is not q:
            p=p.next if p else b
            q=q.next if q else a
        return p
```

---

## 36. Palindrome Linked List

**Problem**

Determine whether linked-list values form a palindrome.

**Reasoning**

Find the midpoint with slow/fast pointers, reverse the second half, then compare both halves.

**C++17 Solution**

```cpp
class Solution { public: bool isPalindrome(ListNode*h){ListNode*s=h,*f=h;while(f&&f->next)s=s->next,f=f->next->next;ListNode*rev=nullptr;while(s){auto*n=s->next;s->next=rev;rev=s;s=n;}while(rev){if(h->val!=rev->val)return false;h=h->next;rev=rev->next;}return true;} };
```

**Test cases**

[1,2,2,1] -> true
[1,2] -> false

**Complexity** — O(n) time, O(1) extra space

---

**C Solution**

```c
#include <stdbool.h>
#include <stdlib.h
typedef struct ListNode{int val;struct ListNode* next;}ListNode;
bool isPalindrome(ListNode*h){int a[100000],n=0;while(h)a[n++]=h->val,h=h->next;for(int i=0;i<n/2;i++)if(a[i]!=a[n-1-i])return false;return true;}
```

**Python 3 Solution**

```python
class Solution:
    def isPalindrome(self, head):
        vals=[]
        while head: vals.append(head.val); head=head.next
        return vals==vals[::-1]
```

---

## 37. Binary Tree Inorder Traversal

**Problem**

Return inorder values of a binary tree.

**Reasoning**

Use a stack to simulate recursive inorder: push left chain, visit node, then move right.

**C++17 Solution**

```cpp
class Solution { public: vector<int> inorderTraversal(TreeNode*r){vector<int>ans;stack<TreeNode*>st;while(r||!st.empty()){while(r)st.push(r),r=r->left;r=st.top();st.pop();ans.push_back(r->val);r=r->right;}return ans;} };
```

**Test cases**

[1,null,2,3] -> [1,3,2]

**Complexity** — O(n) time, O(h) space

---

**C Solution**

```c
// Recursive reference version; caller should provide output allocation per judge.
void dfsInorder(struct TreeNode*r,int*out,int*sz){if(!r)return;dfsInorder(r->left,out,sz);out[(*sz)++]=r->val;dfsInorder(r->right,out,sz);}
```

**Python 3 Solution**

```python
class Solution:
    def inorderTraversal(self, root):
        ans=[]; st=[]; cur=root
        while st or cur:
            while cur: st.append(cur); cur=cur.left
            cur=st.pop(); ans.append(cur.val); cur=cur.right
        return ans
```

---

## 38. Symmetric Tree

**Problem**

Check whether a binary tree is a mirror of itself.

**Reasoning**

Compare left subtree of one node with right subtree of the other recursively.

**C++17 Solution**

```cpp
class Solution { public: bool eq(TreeNode*a,TreeNode*b){if(!a||!b)return a==b;return a->val==b->val&&eq(a->left,b->right)&&eq(a->right,b->left);} bool isSymmetric(TreeNode*r){return !r||eq(r->left,r->right);} };
```

**Test cases**

[1,2,2,3,4,4,3] -> true

**Complexity** — O(n) time, O(h) space

---

**C Solution**

```c
#include <stdbool.h>
typedef struct TreeNode{int val;struct TreeNode* left,*right;}TreeNode;
bool mirror(TreeNode*a,TreeNode*b){if(!a||!b)return a==b;return a->val==b->val&&mirror(a->left,b->right)&&mirror(a->right,b->left);}
bool isSymmetric(TreeNode*r){return !r||mirror(r->left,r->right);}
```

**Python 3 Solution**

```python
class Solution:
    def isSymmetric(self, root):
        def ok(a,b):
            if not a or not b: return a is b
            return a.val==b.val and ok(a.left,b.right) and ok(a.right,b.left)
        return ok(root.left,root.right)
```

---

## 39. Path Sum

**Problem**

Determine whether a root-to-leaf path sums to target.

**Reasoning**

Subtract the current value from target. At a leaf, success means the remainder equals zero.

**C++17 Solution**

```cpp
class Solution { public: bool hasPathSum(TreeNode*r,int t){if(!r)return false;if(!r->left&&!r->right)return r->val==t;return hasPathSum(r->left,t-r->val)||hasPathSum(r->right,t-r->val);} };
```

**Test cases**

[5,4,8,11,null,13,4,7,2,null,null,null,1],22 -> true

**Complexity** — O(n) time, O(h) space

---

**C Solution**

```c
#include <stdbool.h>
typedef struct TreeNode{int val;struct TreeNode* left,*right;}TreeNode;
bool hasPathSum(TreeNode*r,int t){if(!r)return false;if(!r->left&&!r->right)return r->val==t;return hasPathSum(r->left,t-r->val)||hasPathSum(r->right,t-r->val);}
```

**Python 3 Solution**

```python
class Solution:
    def hasPathSum(self, root, targetSum):
        if not root: return False
        if not root.left and not root.right: return root.val==targetSum
        return self.hasPathSum(root.left,targetSum-root.val) or self.hasPathSum(root.right,targetSum-root.val)
```

---

## 40. Stack Using Queues

**Problem**

Implement a stack using queues.

**Reasoning**

Use one queue and rotate the first n-1 elements to the back after each push, making the newest item the front.

**C++17 Solution**

```cpp
class MyStack { queue<int>q; public: void push(int x){q.push(x);for(int i=1;i<q.size();i++){q.push(q.front());q.pop();}} int pop(){int x=q.front();q.pop();return x;} int top(){return q.front();} bool empty(){return q.empty();} };
```

**Test cases**

push(1),push(2),top()->2,pop()->2

**Complexity** — push O(n), pop/top O(1)

---

**C Solution**

```c
#include <stdlib.h>
typedef struct{int a[10000];int n;}MyStack;
MyStack* myStackCreate(){return calloc(1,sizeof(MyStack));}
void myStackPush(MyStack*s,int x){s->a[s->n++]=x;for(int i=s->n-1;i>0;i--){int t=s->a[i];s->a[i]=s->a[i-1];s->a[i-1]=t;}}
int myStackPop(MyStack*s){int x=s->a[0];for(int i=1;i<s->n;i++)s->a[i-1]=s->a[i];s->n--;return x;}
int myStackTop(MyStack*s){return s->a[0];}
bool myStackEmpty(MyStack*s){return s->n==0;}
```

**Python 3 Solution**

```python
class MyStack:
    def __init__(self): self.q=[]
    def push(self,x): self.q.append(x); self.q=self.q[-1:]+self.q[:-1]
    def pop(self): return self.q.pop(0)
    def top(self): return self.q[0]
    def empty(self): return not self.q
```

---

