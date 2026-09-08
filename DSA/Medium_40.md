# Medium — 40 Problems

## 1. Add Two Numbers

**Problem**

Two non-negative integers are stored in reverse order as linked lists. Return their sum in the same format.

**Reasoning**

Add one digit pair plus carry at a time. Continue while either list or carry remains; this naturally handles different lengths and a final carry.

**C++17 Solution**

```cpp
class Solution { public:
 ListNode* addTwoNumbers(ListNode* a,ListNode* b){ ListNode d; auto* cur=&d; int carry=0; while(a||b||carry){ int s=carry+(a?a->val:0)+(b?b->val:0); carry=s/10; cur->next=new ListNode(s%10); cur=cur->next; if(a)a=a->next; if(b)b=b->next; } return d.next; }
};
```

**Test cases**

[2,4,3]+[5,6,4] -> [7,0,8]
[0]+[0] -> [0]
[9,9,9,9,9,9,9]+[9,9,9,9] -> [8,9,9,9,0,0,0,1]

**Complexity** — O(max(n,m)) time, O(max(n,m)) output space

---

**C Solution**

```c
typedef struct ListNode{int val;struct ListNode* next;}ListNode;
ListNode* addTwoNumbers(ListNode*a,ListNode*b){ListNode d={0,0},*c=&d;int carry=0;while(a||b||carry){int s=carry+(a?a->val:0)+(b?b->val:0);carry=s/10;c->next=malloc(sizeof(ListNode));c=c->next;c->val=s%10;c->next=0;if(a)a=a->next;if(b)b=b->next;}return d.next;}
```

**Python 3 Solution**

```python
class Solution:
    def addTwoNumbers(self, l1, l2):
        d=cur=ListNode(0); carry=0
        while l1 or l2 or carry:
            s=carry+(l1.val if l1 else 0)+(l2.val if l2 else 0)
            carry=s//10; cur.next=ListNode(s%10); cur=cur.next
            l1=l1.next if l1 else None; l2=l2.next if l2 else None
        return d.next
```

---

## 2. Longest Substring Without Repeating Characters

**Problem**

Return the length of the longest substring containing no repeated character.

**Reasoning**

Use a sliding window. Store the most recent index of each character; when a repeat enters the window, move the left boundary just after its previous index.

**C++17 Solution**

```cpp
class Solution { public:
 int lengthOfLongestSubstring(string s){ vector<int> last(256,-1); int l=0,ans=0; for(int r=0;r<(int)s.size();++r){ l=max(l,last[(unsigned char)s[r]]+1); last[(unsigned char)s[r]]=r; ans=max(ans,r-l+1); } return ans; }
};
```

**Test cases**

"abcabcbb" -> 3
"bbbbb" -> 1
"pwwkew" -> 3

**Complexity** — O(n) time, O(1) alphabet space

---

**C Solution**

```c
#include <string.h>
int lengthOfLongestSubstring(char*s){int last[256];for(int i=0;i<256;i++)last[i]=-1;int l=0,ans=0;for(int r=0;s[r];r++){unsigned char c=s[r];if(last[c]>=l)l=last[c]+1;last[c]=r;if(r-l+1>ans)ans=r-l+1;}return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def lengthOfLongestSubstring(self, s):
        last={}; l=ans=0
        for r,c in enumerate(s):
            if c in last: l=max(l,last[c]+1)
            last[c]=r; ans=max(ans,r-l+1)
        return ans
```

---

## 3. 3Sum

**Problem**

Return all unique triples whose sum is zero.

**Reasoning**

Sort first. Fix one value, then use two pointers for the remaining pair. Skip equal values at every level to prevent duplicates.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<int>> threeSum(vector<int>& a){ sort(a.begin(),a.end()); vector<vector<int>> r; for(int i=0;i+2<(int)a.size();++i){ if(i&&a[i]==a[i-1])continue; int l=i+1,h=a.size()-1; while(l<h){ long long s=1LL*a[i]+a[l]+a[h]; if(s<0)++l; else if(s>0)--h; else {r.push_back({a[i],a[l],a[h]}); int x=a[l],y=a[h]; while(l<h&&a[l]==x)++l; while(l<h&&a[h]==y)--h;} } } return r; }
};
```

**Test cases**

[-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]
[0,1,1] -> []

**Complexity** — O(n^2) time, O(1) extra space excluding output

---

**C Solution**

```c
#include <stdlib.h>
int cmp3(const void*a,const void*b){return *(int*)a-*(int*)b;}
// Returns array of triples; caller frees each row and the outer array.
int** threeSum(int*a,int n,int*rs,int**cs){qsort(a,n,sizeof(int),cmp3);int cap=16,k=0,**r=malloc(cap*sizeof(int*));for(int i=0;i<n-2;i++){if(i&&a[i]==a[i-1])continue;int l=i+1,h=n-1;while(l<h){long s=(long)a[i]+a[l]+a[h];if(s<0)l++;else if(s>0)h--;else{if(k==cap){cap*=2;r=realloc(r,cap*sizeof(int*));}r[k]=malloc(3*sizeof(int));r[k][0]=a[i];r[k][1]=a[l];r[k][2]=a[h];k++;l++;h--;while(l<h&&a[l]==a[l-1])l++;while(l<h&&a[h]==a[h+1])h--;}}}*rs=k;*cs=malloc(k*sizeof(int));for(int i=0;i<k;i++)(*cs)[i]=3;return r;}
```

**Python 3 Solution**

```python
class Solution:
    def threeSum(self, nums):
        nums.sort(); ans=[]
        for i in range(len(nums)-2):
            if i and nums[i]==nums[i-1]: continue
            l,r=i+1,len(nums)-1
            while l<r:
                s=nums[i]+nums[l]+nums[r]
                if s<0: l+=1
                elif s>0: r-=1
                else:
                    ans.append([nums[i],nums[l],nums[r]])
                    l+=1; r-=1
                    while l<r and nums[l]==nums[l-1]: l+=1
                    while l<r and nums[r]==nums[r+1]: r-=1
        return ans
```

---

## 4. Container With Most Water

**Problem**

Choose two vertical lines to maximize the rectangle area between them.

**Reasoning**

Area is width times the shorter line. Start at both ends; move the shorter side because moving the taller side cannot improve the limiting height.

**C++17 Solution**

```cpp
class Solution { public:
 int maxArea(vector<int>& h){ int l=0,r=h.size()-1,ans=0; while(l<r){ ans=max(ans,min(h[l],h[r])*(r-l)); if(h[l]<h[r])++l; else --r; } return ans; }
};
```

**Test cases**

[1,8,6,2,5,4,8,3,7] -> 49
[1,1] -> 1

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int maxArea(int*h,int n){int l=0,r=n-1,ans=0;while(l<r){int mn=h[l]<h[r]?h[l]:h[r],x=mn*(r-l);if(x>ans)ans=x;if(h[l]<h[r])l++;else r--;}return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def maxArea(self, h):
        l,r,ans=0,len(h)-1,0
        while l<r:
            ans=max(ans,(r-l)*min(h[l],h[r]))
            if h[l]<h[r]: l+=1
            else: r-=1
        return ans
```

---

## 5. Product of Array Except Self

**Problem**

Return an array where each position equals the product of all other values, without division.

**Reasoning**

First store product of everything to the left. Then sweep from right with a running suffix product and multiply into the answer.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> productExceptSelf(vector<int>& a){ int n=a.size(); vector<int> r(n,1); int p=1; for(int i=0;i<n;i++){r[i]=p;p*=a[i];} p=1; for(int i=n-1;i>=0;i--){r[i]*=p;p*=a[i];} return r; }
};
```

**Test cases**

[1,2,3,4] -> [24,12,8,6]
[-1,1,0,-3,3] -> [0,0,9,0,0]

**Complexity** — O(n) time, O(1) extra space excluding output

---

**C Solution**

```c
#include <stdlib.h>
int* productExceptSelf(int*a,int n,int*rs){int*r=malloc(n*sizeof(int)),p=1;for(int i=0;i<n;i++){r[i]=p;p*=a[i];}p=1;for(int i=n-1;i>=0;i--){r[i]*=p;p*=a[i];}*rs=n;return r;}
```

**Python 3 Solution**

```python
class Solution:
    def productExceptSelf(self, nums):
        n=len(nums); ans=[1]*n; p=1
        for i,x in enumerate(nums): ans[i]=p; p*=x
        p=1
        for i in range(n-1,-1,-1): ans[i]*=p; p*=nums[i]
        return ans
```

---

## 6. Group Anagrams

**Problem**

Group words that have identical character multisets.

**Reasoning**

Use a canonical key: the sorted letters of each word. Words with equal keys belong together.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<string>> groupAnagrams(vector<string>& strs){ unordered_map<string,vector<string>> mp; for(auto s:strs){ string k=s; sort(k.begin(),k.end()); mp[k].push_back(s); } vector<vector<string>> r; for(auto &p:mp)r.push_back(p.second); return r; }
};
```

**Test cases**

["eat","tea","tan","ate","nat","bat"] -> groups {eat,tea,ate},{tan,nat},{bat}

**Complexity** — O(total characters * log word length) time

---

**C Solution**

```c
#include <stdlib.h>
#include <string.h>
typedef struct {char key[101]; char** words; int n,cap;} G;
int cmpchar(const void*a,const void*b){return *(const char*)a-*(const char*)b;}
char*** groupAnagrams(char**strs,int n,int*rs,int**cs){G*g=calloc(n,sizeof(G));int ng=0;for(int i=0;i<n;i++){char key[101];strcpy(key,strs[i]);qsort(key,strlen(key),1,cmpchar);int id=-1;for(int j=0;j<ng;j++)if(strcmp(g[j].key,key)==0){id=j;break;}if(id<0){id=ng++;strcpy(g[id].key,key);g[id].cap=4;g[id].words=malloc(4*sizeof(char*));}if(g[id].n==g[id].cap){g[id].cap*=2;g[id].words=realloc(g[id].words,g[id].cap*sizeof(char*));}g[id].words[g[id].n++]=strs[i];}char***out=malloc(ng*sizeof(char**));*cs=malloc(ng*sizeof(int));for(int i=0;i<ng;i++){out[i]=g[i].words;(*cs)[i]=g[i].n;}*rs=ng;free(g);return out;}
```

**Python 3 Solution**

```python
class Solution:
    def groupAnagrams(self, strs):
        from collections import defaultdict
        d=defaultdict(list)
        for s in strs: d[''.join(sorted(s))].append(s)
        return list(d.values())
```

---

## 7. Top K Frequent Elements

**Problem**

Return the k values with highest frequencies.

**Reasoning**

Count frequencies, then use buckets indexed by frequency. Scanning buckets from high to low avoids a full sort.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> topKFrequent(vector<int>& a,int k){ unordered_map<int,int> f; for(int x:a)++f[x]; vector<vector<int>> b(a.size()+1); for(auto [x,c]:f)b[c].push_back(x); vector<int> r; for(int c=b.size()-1;c>=1&&r.size()<k;--c) for(int x:b[c]){r.push_back(x); if(r.size()==k)break;} return r; }
};
```

**Test cases**

[1,1,1,2,2,3],2 -> [1,2]

**Complexity** — O(n) average time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int cmpK(const void*a,const void*b){return *(int*)a-*(int*)b;}
int* topKFrequent(int*a,int n,int k,int*rs){qsort(a,n,sizeof(int),cmpK);int*vals=malloc(n*sizeof(int));int*cnt=malloc(n*sizeof(int));int m=0;for(int i=0;i<n;){int j=i;while(j<n&&a[j]==a[i])j++;vals[m]=a[i];cnt[m++]=j-i;i=j;}for(int i=0;i<m;i++)for(int j=i+1;j<m;j++)if(cnt[j]>cnt[i]){int t=cnt[i];cnt[i]=cnt[j];cnt[j]=t;t=vals[i];vals[i]=vals[j];vals[j]=t;}int*r=malloc(k*sizeof(int));for(int i=0;i<k;i++)r[i]=vals[i];*rs=k;free(vals);free(cnt);return r;}
```

**Python 3 Solution**

```python
class Solution:
    def topKFrequent(self, nums, k):
        from collections import Counter
        return [x for x,_ in Counter(nums).most_common(k)]
```

---

## 8. Longest Consecutive Sequence

**Problem**

Return the length of the longest run of consecutive integers.

**Reasoning**

Put values in a set. Start a sequence only when x-1 is absent, then count x,x+1,... This visits each value only a constant number of times.

**C++17 Solution**

```cpp
class Solution { public:
 int longestConsecutive(vector<int>& a){ unordered_set<int>s(a.begin(),a.end()); int ans=0; for(int x:s) if(!s.count(x-1)){int y=x; while(s.count(y))++y; ans=max(ans,y-x);} return ans; }
};
```

**Test cases**

[100,4,200,1,3,2] -> 4
[0,3,7,2,5,8,4,6,0,1] -> 9

**Complexity** — O(n) average time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int cmpL(const void*a,const void*b){return *(int*)a-*(int*)b;}
int longestConsecutive(int*a,int n){if(!n)return 0;qsort(a,n,sizeof(int),cmpL);int best=1,cur=1;for(int i=1;i<n;i++){if(a[i]==a[i-1])continue;if(a[i]==a[i-1]+1)cur++;else cur=1;if(cur>best)best=cur;}return best;}
```

**Python 3 Solution**

```python
class Solution:
    def longestConsecutive(self, nums):
        s=set(nums); ans=0
        for x in s:
            if x-1 not in s:
                y=x
                while y in s: y+=1
                ans=max(ans,y-x)
        return ans
```

---

## 9. Subarray Sum Equals K

**Problem**

Count contiguous subarrays whose sum equals k.

**Reasoning**

If prefixSum at i is S and an earlier prefix is S-k, the segment between them sums to k. Store counts of prior prefix sums.

**C++17 Solution**

```cpp
class Solution { public:
 int subarraySum(vector<int>& a,int k){ unordered_map<long long,int> c{{0,1}}; long long s=0; int ans=0; for(int x:a){s+=x; if(c.count(s-k))ans+=c[s-k]; ++c[s];} return ans; }
};
```

**Test cases**

[1,1,1],2 -> 2
[1,2,3],3 -> 2

**Complexity** — O(n) average time, O(n) space

---

**C Solution**

```c
int subarraySum(int*a,int n,int k){int ans=0;for(int i=0;i<n;i++){int s=0;for(int j=i;j<n;j++){s+=a[j];if(s==k)ans++;}}return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def subarraySum(self, nums, k):
        pref={0:1}; s=ans=0
        for x in nums:
            s+=x; ans+=pref.get(s-k,0); pref[s]=pref.get(s,0)+1
        return ans
```

---

## 10. Longest Palindromic Substring

**Problem**

Return any longest palindromic substring.

**Reasoning**

Expand around every possible center. A palindrome is defined by equal characters expanding outward.

**C++17 Solution**

```cpp
class Solution { public:
 string longestPalindrome(string s){ int st=0,len=0; auto ex=[&](int l,int r){ while(l>=0&&r<(int)s.size()&&s[l]==s[r]){ if(r-l+1>len)st=l,len=r-l+1; --l;++r; } }; for(int i=0;i<(int)s.size();++i){ex(i,i);ex(i,i+1);} return s.substr(st,len); }
};
```

**Test cases**

"babad" -> "bab" ("aba" also valid)
"cbbd" -> "bb"

**Complexity** — O(n^2) time, O(1) extra space

---

**C Solution**

```c
#include <string.h>
char* longestPalindrome(char*s){int n=strlen(s),st=0,len=1;for(int c=0;c<n;c++){for(int l=c,r=c;l>=0&&r<n&&s[l]==s[r];l--,r++)if(r-l+1>len){st=l;len=r-l+1;}for(int l=c,r=c+1;l>=0&&r<n&&s[l]==s[r];l--,r++)if(r-l+1>len){st=l;len=r-l+1;}}char*r=malloc(len+1);memcpy(r,s+st,len);r[len]=0;return r;}
```

**Python 3 Solution**

```python
class Solution:
    def longestPalindrome(self, s):
        best=''
        def expand(l,r):
            nonlocal best
            while l>=0 and r<len(s) and s[l]==s[r]: l-=1; r+=1
            if r-l-1>len(best): best=s[l+1:r]
        for i in range(len(s)): expand(i,i); expand(i,i+1)
        return best
```

---

## 11. Permutation in String

**Problem**

Determine whether a permutation of s1 occurs as a contiguous substring of s2.

**Reasoning**

Compare 26-character frequency vectors for a fixed-size sliding window. Add the incoming letter and remove the outgoing one.

**C++17 Solution**

```cpp
class Solution { public:
 bool checkInclusion(string s1,string s2){ if(s1.size()>s2.size())return false; array<int,26>a{},b{}; for(char c:s1)++a[c-'a']; for(int i=0;i<(int)s2.size();++i){++b[s2[i]-'a']; if(i>=(int)s1.size())--b[s2[i-s1.size()]-'a']; if(a==b)return true;} return false; }
};
```

**Test cases**

"ab","eidbaooo" -> true
"ab","eidboaoo" -> false

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
#include <stdbool.h>
#include <string.h>
bool checkInclusion(char*s1,char*s2){int a[26]={0},b[26]={0},n=strlen(s1),m=strlen(s2);if(n>m)return false;for(int i=0;i<n;i++)a[s1[i]-'a']++,b[s2[i]-'a']++;for(int i=n;i<=m;i++){int ok=1;for(int j=0;j<26;j++)if(a[j]!=b[j])ok=0;if(ok)return true;if(i<m)b[s2[i]-'a']++,b[s2[i-n]-'a']--;}return false;}
```

**Python 3 Solution**

```python
class Solution:
    def checkInclusion(self, s1, s2):
        a=[0]*26; b=[0]*26
        if len(s1)>len(s2): return False
        for i,c in enumerate(s1): a[ord(c)-97]+=1; b[ord(s2[i])-97]+=1
        if a==b: return True
        for i in range(len(s1),len(s2)):
            b[ord(s2[i])-97]+=1; b[ord(s2[i-len(s1)])-97]-=1
            if a==b: return True
        return False
```

---

## 12. Daily Temperatures

**Problem**

For each day, return how many days until a warmer temperature; 0 if none.

**Reasoning**

Maintain a decreasing stack of indices. When today is warmer than the stack top, resolve that older day.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> dailyTemperatures(vector<int>& t){ vector<int> r(t.size()); stack<int> st; for(int i=0;i<(int)t.size();++i){ while(!st.empty()&&t[i]>t[st.top()]){int j=st.top();st.pop();r[j]=i-j;} st.push(i);} return r; }
};
```

**Test cases**

[73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]

**Complexity** — O(n) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int* dailyTemperatures(int*t,int n,int*rs){int*r=calloc(n,sizeof(int)),*st=malloc(n*sizeof(int));int top=0;for(int i=0;i<n;i++){while(top&&t[st[top-1]]<t[i]){int j=st[--top];r[j]=i-j;}st[top++]=i;}free(st);*rs=n;return r;}
```

**Python 3 Solution**

```python
class Solution:
    def dailyTemperatures(self, t):
        ans=[0]*len(t); st=[]
        for i,x in enumerate(t):
            while st and t[st[-1]]<x:
                j=st.pop(); ans[j]=i-j
            st.append(i)
        return ans
```

---

## 13. Evaluate Reverse Polish Notation

**Problem**

Evaluate an expression written in postfix notation with +,-,*,/. Integer division truncates toward zero.

**Reasoning**

Push numbers. When an operator appears, pop b then a, compute a op b, and push the result.

**C++17 Solution**

```cpp
class Solution { public:
 int evalRPN(vector<string>& t){ stack<long long>s; for(auto &x:t){ if(x.size()>1||isdigit(x[0]))s.push(stoll(x)); else {auto b=s.top();s.pop();auto a=s.top();s.pop(); if(x=="+")s.push(a+b); else if(x=="-")s.push(a-b); else if(x=="*")s.push(a*b); else s.push(a/b);} } return s.top(); }
};
```

**Test cases**

["2","1","+","3","*"] -> 9
["4","13","5","/","+"] -> 6

**Complexity** — O(n) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
#include <string.h>
#include <math.h>
int evalRPN(char**tok,int n){int st[10000],top=0;for(int i=0;i<n;i++){char*c=tok[i];if(strcmp(c,"+")&&strcmp(c,"-")&&strcmp(c,"*")&&strcmp(c,"/")){st[top++]=atoi(c);continue;}int b=st[--top],a=st[--top];if(c[0]=='+')st[top++]=a+b;else if(c[0]=='-')st[top++]=a-b;else if(c[0]=='*')st[top++]=a*b;else st[top++]=a/b;}return st[0];}
```

**Python 3 Solution**

```python
class Solution:
    def evalRPN(self, tokens):
        st=[]
        for x in tokens:
            if x not in '+-*/': st.append(int(x)); continue
            b,a=st.pop(),st.pop()
            if x=='+': st.append(a+b)
            elif x=='-': st.append(a-b)
            elif x=='*': st.append(a*b)
            else: st.append(int(a/b))
        return st[-1]
```

---

## 14. Find Minimum in Rotated Sorted Array

**Problem**

A sorted array was rotated once with unique values. Return its minimum.

**Reasoning**

Compare middle with the right boundary. If middle is larger, minimum lies right; otherwise it lies left including mid.

**C++17 Solution**

```cpp
class Solution { public:
 int findMin(vector<int>& a){ int l=0,r=a.size()-1; while(l<r){int m=l+(r-l)/2; if(a[m]>a[r])l=m+1; else r=m;} return a[l]; }
};
```

**Test cases**

[3,4,5,1,2] -> 1
[4,5,6,7,0,1,2] -> 0

**Complexity** — O(log n) time, O(1) space

---

**C Solution**

```c
int findMin(int*a,int n){int l=0,r=n-1;while(l<r){int m=l+(r-l)/2;if(a[m]>a[r])l=m+1;else r=m;}return a[l];}
```

**Python 3 Solution**

```python
class Solution:
    def findMin(self, nums):
        l,r=0,len(nums)-1
        while l<r:
            m=(l+r)//2
            if nums[m]>nums[r]: l=m+1
            else: r=m
        return nums[l]
```

---

## 15. Search in Rotated Sorted Array

**Problem**

Find target in a rotated sorted array with unique values.

**Reasoning**

At least one half around mid is sorted. Check whether target lies in that half; otherwise search the other half.

**C++17 Solution**

```cpp
class Solution { public:
 int search(vector<int>& a,int t){ int l=0,r=a.size()-1; while(l<=r){int m=l+(r-l)/2; if(a[m]==t)return m; if(a[l]<=a[m]){if(a[l]<=t&&t<a[m])r=m-1;else l=m+1;}else{if(a[m]<t&&t<=a[r])l=m+1;else r=m-1;}} return -1; }
};
```

**Test cases**

[4,5,6,7,0,1,2],0 -> 4
[4,5,6,7,0,1,2],3 -> -1

**Complexity** — O(log n) time, O(1) space

---

**C Solution**

```c
int searchRot(int*a,int n,int t){int l=0,r=n-1;while(l<=r){int m=l+(r-l)/2;if(a[m]==t)return m;if(a[l]<=a[m]){if(a[l]<=t&&t<a[m])r=m-1;else l=m+1;}else{if(a[m]<t&&t<=a[r])l=m+1;else r=m-1;}}return -1;}
```

**Python 3 Solution**

```python
class Solution:
    def search(self, nums, target):
        l,r=0,len(nums)-1
        while l<=r:
            m=(l+r)//2
            if nums[m]==target: return m
            if nums[l]<=nums[m]:
                if nums[l]<=target<nums[m]: r=m-1
                else: l=m+1
            else:
                if nums[m]<target<=nums[r]: l=m+1
                else: r=m-1
        return -1
```

---

## 16. Rotate Array

**Problem**

Rotate an array to the right by k positions.

**Reasoning**

Reversing the whole array then each part produces the rotated order. Reduce k modulo n first.

**C++17 Solution**

```cpp
class Solution { public:
 void rotate(vector<int>& a,int k){ if(a.empty())return; k%=a.size(); reverse(a.begin(),a.end()); reverse(a.begin(),a.begin()+k); reverse(a.begin()+k,a.end()); }
};
```

**Test cases**

[1,2,3,4,5,6,7],3 -> [5,6,7,1,2,3,4]
[-1,-100,3,99],2 -> [3,99,-1,-100]

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
void rev(int*a,int l,int r){while(l<r){int t=a[l];a[l++]=a[r];a[r--]=t;}}
void rotate(int*a,int n,int k){k%=n;if(k<0)k+=n;rev(a,0,n-1);rev(a,0,k-1);rev(a,k,n-1);}
```

**Python 3 Solution**

```python
class Solution:
    def rotate(self, nums, k):
        k%=len(nums); nums[:]=nums[-k:]+nums[:-k]
```

---

## 17. Spiral Matrix

**Problem**

Return all matrix values in clockwise spiral order.

**Reasoning**

Keep top, bottom, left, right boundaries. Traverse one edge at a time and shrink the corresponding boundary.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> spiralOrder(vector<vector<int>>& a){ vector<int>r; if(a.empty())return r; int t=0,b=a.size()-1,l=0,rr=a[0].size()-1; while(t<=b&&l<=rr){for(int j=l;j<=rr;j++)r.push_back(a[t][j]);++t;for(int i=t;i<=b;i++)r.push_back(a[i][rr]);--rr;if(t<=b)for(int j=rr;j>=l;j--)r.push_back(a[b][j]);--b;if(l<=rr)for(int i=b;i>=t;i--)r.push_back(a[i][l]);++l;} return r;}
};
```

**Test cases**

[[1,2,3],[4,5,6],[7,8,9]] -> [1,2,3,6,9,8,7,4,5]

**Complexity** — O(R*C) time, O(1) extra space excluding output

---

**C Solution**

```c
#include <stdlib.h>
int* spiralOrder(int**m,int R,int*C,int*rs){int n=R*(*C),*out=malloc(n*sizeof(int)),k=0,t=0,b=R-1,l=0,r=*C-1;while(t<=b&&l<=r){for(int j=l;j<=r;j++)out[k++]=m[t][j];t++;for(int i=t;i<=b;i++)out[k++]=m[i][r];r--;if(t<=b){for(int j=r;j>=l;j--)out[k++]=m[b][j];b--;}if(l<=r){for(int i=b;i>=t;i--)out[k++]=m[i][l];l++;}}*rs=k;return out;}
```

**Python 3 Solution**

```python
class Solution:
    def spiralOrder(self, m):
        ans=[]
        if not m:return ans
        t,b,l,r=0,len(m)-1,0,len(m[0])-1
        while t<=b and l<=r:
            for j in range(l,r+1): ans.append(m[t][j])
            t+=1
            for i in range(t,b+1): ans.append(m[i][r])
            r-=1
            if t<=b:
                for j in range(r,l-1,-1): ans.append(m[b][j])
                b-=1
            if l<=r:
                for i in range(b,t-1,-1): ans.append(m[i][l])
                l+=1
        return ans
```

---

## 18. Number of Islands

**Problem**

Count connected groups of land cells (1) in a binary grid using 4-directional adjacency.

**Reasoning**

Every time an unvisited land cell is found, start a DFS that marks the whole island. The number of DFS starts is the answer.

**C++17 Solution**

```cpp
class Solution { public:
 int numIslands(vector<vector<char>>& g){ int n=g.size(),m=g[0].size(),ans=0; int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1}; for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]=='1'){++ans; queue<pair<int,int>>q; q.push({i,j});g[i][j]='0';while(!q.empty()){auto [r,c]=q.front();q.pop();for(int k=0;k<4;k++){int nr=r+dr[k],nc=c+dc[k];if(nr>=0&&nr<n&&nc>=0&&nc<m&&g[nr][nc]=='1'){g[nr][nc]='0';q.push({nr,nc});}}}} return ans;}
};
```

**Test cases**

[["1","1","0"],["0","1","0"],["0","0","1"]] -> 2

**Complexity** — O(R*C) time, O(R*C) worst-case queue space

---

**C Solution**

```c
void dfsI(char**g,int R,int C,int r,int c){if(r<0||r>=R||c<0||c>=C||g[r][c]!='1')return;g[r][c]='0';dfsI(g,R,C,r+1,c);dfsI(g,R,C,r-1,c);dfsI(g,R,C,r,c+1);dfsI(g,R,C,r,c-1);}
int numIslands(char**g,int R,int*C){int ans=0;for(int r=0;r<R;r++)for(int c=0;c<*C;c++)if(g[r][c]=='1'){ans++;dfsI(g,R,*C,r,c);}return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def numIslands(self, grid):
        R,C=len(grid),len(grid[0]); ans=0
        for r in range(R):
            for c in range(C):
                if grid[r][c]=='1':
                    ans+=1; st=[(r,c)]; grid[r][c]='0'
                    for x,y in st:
                        for dx,dy in ((1,0),(-1,0),(0,1),(0,-1)):
                            nx,ny=x+dx,y+dy
                            if 0<=nx<R and 0<=ny<C and grid[nx][ny]=='1': grid[nx][ny]='0'; st.append((nx,ny))
        return ans
```

---

## 19. Binary Tree Level Order Traversal

**Problem**

Return node values level by level from top to bottom.

**Reasoning**

BFS uses a queue. Process exactly queue.size() nodes per level before moving to the next level.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<int>> levelOrder(TreeNode* r){ vector<vector<int>>ans; if(!r)return ans; queue<TreeNode*>q;q.push(r);while(!q.empty()){int z=q.size();vector<int>v;while(z--){auto*n=q.front();q.pop();v.push_back(n->val);if(n->left)q.push(n->left);if(n->right)q.push(n->right);}ans.push_back(v);}return ans;}
};
```

**Test cases**

[3,9,20,null,null,15,7] -> [[3],[9,20],[15,7]]

**Complexity** — O(n) time, O(n) space

---

**C Solution**

```c
// Practice implementation: DFS by depth; output packing is omitted because C judge signatures vary.
typedef struct TreeNode{int val;struct TreeNode*left,*right;}TreeNode;
void levelDFS(TreeNode*r,int d,int**out,int*sizes){if(!r)return;out[d][sizes[d]++]=r->val;levelDFS(r->left,d+1,out,sizes);levelDFS(r->right,d+1,out,sizes);}
```

**Python 3 Solution**

```python
class Solution:
    def levelOrder(self, root):
        from collections import deque
        if not root:return []
        q=deque([root]); ans=[]
        while q:
            row=[]
            for _ in range(len(q)):
                n=q.popleft(); row.append(n.val)
                if n.left:q.append(n.left)
                if n.right:q.append(n.right)
            ans.append(row)
        return ans
```

---

## 20. Lowest Common Ancestor of BST

**Problem**

Given a binary search tree and two nodes, return their lowest common ancestor.

**Reasoning**

BST ordering tells us where both nodes lie. If both are smaller go left; both larger go right; otherwise current node is the split point.

**C++17 Solution**

```cpp
class Solution { public:
 TreeNode* lowestCommonAncestor(TreeNode* r,TreeNode* p,TreeNode* q){ while(r){ if(p->val<r->val&&q->val<r->val)r=r->left; else if(p->val>r->val&&q->val>r->val)r=r->right; else return r; } return nullptr; }
};
```

**Test cases**

BST [6,2,8,0,4,7,9], p=2,q=8 -> 6
p=2,q=4 -> 2

**Complexity** — O(h) time, O(1) space

---

**C Solution**

```c
typedef struct TreeNode{int val;struct TreeNode*left,*right;}TreeNode;
TreeNode* lowestCommonAncestor(TreeNode*r,TreeNode*p,TreeNode*q){while(r){if(p->val<r->val&&q->val<r->val)r=r->left;else if(p->val>r->val&&q->val>r->val)r=r->right;else return r;}return 0;}
```

**Python 3 Solution**

```python
class Solution:
    def lowestCommonAncestor(self, root, p, q):
        while root:
            if p.val<root.val and q.val<root.val: root=root.left
            elif p.val>root.val and q.val>root.val: root=root.right
            else:return root
```

---

## 21. Kth Smallest in BST

**Problem**

Return the k-th smallest value in a BST.

**Reasoning**

Inorder traversal of a BST is sorted. Use an iterative stack and stop after visiting k nodes.

**C++17 Solution**

```cpp
class Solution { public:
 int kthSmallest(TreeNode* r,int k){ stack<TreeNode*>st; while(true){while(r){st.push(r);r=r->left;}r=st.top();st.pop();if(--k==0)return r->val;r=r->right;} }
};
```

**Test cases**

BST [3,1,4,null,2], k=1 -> 1
BST [5,3,6,2,4,1], k=3 -> 3

**Complexity** — O(h+k) time, O(h) space

---

**C Solution**

```c
typedef struct TreeNode{int val;struct TreeNode*left,*right;}TreeNode;
int kthSmallest(TreeNode*r,int k){TreeNode*st[10000];int top=0;while(1){while(r){st[top++]=r;r=r->left;}r=st[--top];if(--k==0)return r->val;r=r->right;}}
```

**Python 3 Solution**

```python
class Solution:
    def kthSmallest(self, root, k):
        st=[]; cur=root
        while True:
            while cur: st.append(cur); cur=cur.left
            cur=st.pop(); k-=1
            if k==0:return cur.val
            cur=cur.right
```

---

## 22. Coin Change

**Problem**

Given coin denominations and a target amount, return the fewest coins needed, or -1.

**Reasoning**

DP[amount] = 1 + min(DP[amount-coin]). Build amounts from 0 upward, starting DP[0]=0.

**C++17 Solution**

```cpp
class Solution { public:
 int coinChange(vector<int>& c,int a){ const int INF=1e9; vector<int>dp(a+1,INF);dp[0]=0;for(int x=1;x<=a;x++)for(int coin:c)if(coin<=x)dp[x]=min(dp[x],dp[x-coin]+1);return dp[a]==INF?-1:dp[a]; }
};
```

**Test cases**

coins=[1,2,5], amount=11 -> 3
coins=[2], amount=3 -> -1

**Complexity** — O(amount * number of coins) time, O(amount) space

---

**C Solution**

```c
#include <stdlib.h>
int coinChange(int*c,int n,int amount){int*dp=malloc((amount+1)*sizeof(int));for(int i=0;i<=amount;i++)dp[i]=amount+1;dp[0]=0;for(int a=1;a<=amount;a++)for(int j=0;j<n;j++)if(c[j]<=a&&dp[a-c[j]]+1<dp[a])dp[a]=dp[a-c[j]]+1;int r=dp[amount]>amount?-1:dp[amount];free(dp);return r;}
```

**Python 3 Solution**

```python
class Solution:
    def coinChange(self, coins, amount):
        dp=[amount+1]*(amount+1); dp[0]=0
        for a in range(1,amount+1):
            for c in coins:
                if c<=a: dp[a]=min(dp[a],dp[a-c]+1)
        return -1 if dp[amount]>amount else dp[amount]
```

---

## 23. House Robber II

**Problem**

Houses form a circle; adjacent houses cannot both be robbed.

**Reasoning**

Because first and last are adjacent, either exclude the first or exclude the last. Solve the linear robber problem for both ranges and take the larger.

**C++17 Solution**

```cpp
class Solution { public:
 int line(vector<int>&a,int l,int r){int p2=0,p1=0;for(int i=l;i<=r;i++){int c=max(p1,p2+a[i]);p2=p1;p1=c;}return p1;} int rob(vector<int>&a){int n=a.size();if(n==1)return a[0];return max(line(a,0,n-2),line(a,1,n-1));}
};
```

**Test cases**

[2,3,2] -> 3
[1,2,3,1] -> 4

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int robRange(int*a,int l,int r){int p=0,q=0;for(int i=l;i<=r;i++){int t=q>p+a[i]?q:p+a[i];p=q;q=t;}return q;}
int robCircular(int*a,int n){if(n==1)return a[0];int x=robRange(a,0,n-2),y=robRange(a,1,n-1);return x>y?x:y;}
```

**Python 3 Solution**

```python
class Solution:
    def rob(self, nums):
        if len(nums)==1:return nums[0]
        def f(a):
            p=q=0
            for x in a:p,q=q,max(q,p+x)
            return q
        return max(f(nums[:-1]),f(nums[1:]))
```

---

## 24. Decode Ways

**Problem**

Digits encode A=1,...,Z=26. Count valid decodings.

**Reasoning**

At position i, a valid decoding can end with a one-digit value 1..9 or a two-digit value 10..26. Sum both DP states.

**C++17 Solution**

```cpp
class Solution { public:
 int numDecodings(string s){ if(s.empty()||s[0]=='0')return 0; int a=1,b=1; for(int i=1;i<(int)s.size();++i){int c=0;if(s[i]!='0')c+=b;int x=(s[i-1]-'0')*10+s[i]-'0';if(x>=10&&x<=26)c+=a;a=b;b=c;}return b;}
};
```

**Test cases**

"12" -> 2
"226" -> 3
"06" -> 0

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int numDecodings(char*s){int n=strlen(s);if(!n||s[0]=='0')return 0;int a=1,b=1;for(int i=1;i<n;i++){int c=0;if(s[i]!='0')c+=b;int x=(s[i-1]-'0')*10+s[i]-'0';if(x>=10&&x<=26)c+=a;a=b;b=c;}return b;}
```

**Python 3 Solution**

```python
class Solution:
    def numDecodings(self, s):
        if not s or s[0]=='0':return 0
        a=b=1
        for i in range(1,len(s)):
            c=0
            if s[i]!='0':c+=b
            if 10<=int(s[i-1:i+1])<=26:c+=a
            a,b=b,c
        return b
```

---

## 25. Unique Paths

**Problem**

Count paths from top-left to bottom-right of an m x n grid using only right/down moves.

**Reasoning**

Let dp[j] be ways to reach the current row’s column j. Each cell gets ways from above plus left.

**C++17 Solution**

```cpp
class Solution { public:
 int uniquePaths(int m,int n){ vector<int>dp(n,1);for(int i=1;i<m;i++)for(int j=1;j<n;j++)dp[j]+=dp[j-1];return dp[n-1];}
};
```

**Test cases**

m=3,n=7 -> 28
m=3,n=2 -> 3

**Complexity** — O(m*n) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
long long uniquePaths(int m,int n){long long*dp=malloc(n*sizeof(long long));for(int j=0;j<n;j++)dp[j]=1;for(int i=1;i<m;i++)for(int j=1;j<n;j++)dp[j]+=dp[j-1];long long r=dp[n-1];free(dp);return r;}
```

**Python 3 Solution**

```python
class Solution:
    def uniquePaths(self,m,n):
        dp=[1]*n
        for _ in range(1,m):
            for j in range(1,n):dp[j]+=dp[j-1]
        return dp[-1]
```

---

## 26. Longest Increasing Subsequence

**Problem**

Return the length of the longest strictly increasing subsequence.

**Reasoning**

Maintain tails[i] = smallest possible ending value for an increasing subsequence of length i+1. Binary search the first tail >= x.

**C++17 Solution**

```cpp
class Solution { public:
 int lengthOfLIS(vector<int>&a){vector<int>t;for(int x:a){auto it=lower_bound(t.begin(),t.end(),x);if(it==t.end())t.push_back(x);else *it=x;}return t.size();}
};
```

**Test cases**

[10,9,2,5,3,7,101,18] -> 4
[0,1,0,3,2,3] -> 4

**Complexity** — O(n log n) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int lengthOfLIS(int*a,int n){int*d=malloc(n*sizeof(int)),sz=0;for(int i=0;i<n;i++){int l=0,r=sz;while(l<r){int m=(l+r)/2;if(d[m]<a[i])l=m+1;else r=m;}d[l]=a[i];if(l==sz)sz++;}free(d);return sz;}
```

**Python 3 Solution**

```python
class Solution:
    def lengthOfLIS(self, nums):
        from bisect import bisect_left
        d=[]
        for x in nums:
            i=bisect_left(d,x)
            if i==len(d):d.append(x)
            else:d[i]=x
        return len(d)
```

---

## 27. Validate Binary Search Tree

**Problem**

Determine whether a binary tree satisfies strict BST ordering.

**Reasoning**

Every node must fall inside a valid numeric range inherited from its ancestors. Use long long bounds to avoid edge issues.

**C++17 Solution**

```cpp
class Solution { public:
 bool ok(TreeNode*n,long long lo,long long hi){if(!n)return true;if(n->val<=lo||n->val>=hi)return false;return ok(n->left,lo,n->val)&&ok(n->right,n->val,hi);} bool isValidBST(TreeNode*r){return ok(r,LLONG_MIN,LLONG_MAX);}
};
```

**Test cases**

[2,1,3] -> true
[5,1,4,null,null,3,6] -> false

**Complexity** — O(n) time, O(h) space

---

**C Solution**

```c
#include <stdbool.h>
#include <limits.h>
typedef struct TreeNode{int val;struct TreeNode*left,*right;}TreeNode;
bool bst(TreeNode*r,long long lo,long long hi){return !r||(r->val>lo&&r->val<hi&&bst(r->left,lo,r->val)&&bst(r->right,r->val,hi));}
bool isValidBST(TreeNode*r){return bst(r,LLONG_MIN,LLONG_MAX);}
```

**Python 3 Solution**

```python
class Solution:
    def isValidBST(self, root):
        def ok(n,lo,hi):
            if not n:return True
            return lo<n.val<hi and ok(n.left,lo,n.val) and ok(n.right,n.val,hi)
        return ok(root,float('-inf'),float('inf'))
```

---

## 28. Combination Sum

**Problem**

Find all combinations of candidate values that sum to target; a candidate can be reused.

**Reasoning**

Backtracking tries each candidate from a non-decreasing start index. Stop when the remaining target becomes negative.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<int>>ans; vector<int>cur; void dfs(vector<int>&a,int st,int rem){if(rem==0){ans.push_back(cur);return;}for(int i=st;i<(int)a.size()&&a[i]<=rem;i++){cur.push_back(a[i]);dfs(a,i,rem-a[i]);cur.pop_back();}} vector<vector<int>> combinationSum(vector<int>&a,int t){sort(a.begin(),a.end());dfs(a,0,t);return ans;}
};
```

**Test cases**

[2,3,6,7],7 -> [[2,2,3],[7]]
[2,3,5],8 -> [[2,2,2,2],[2,3,3],[3,5]]

**Complexity** — Exponential in number of valid combinations; O(target) recursion depth

---

**C Solution**

```c
// Core backtracking routine. Store solutions in caller-managed result arrays.
void comb(int*c,int n,int start,int t,int*path,int len,int***out,int*rows,int*cols,int*cap){if(t==0){if(*rows==*cap){*cap*=2;*out=realloc(*out,*cap*sizeof(int*));}(*out)[*rows]=malloc(len*sizeof(int));for(int i=0;i<len;i++)(*out)[*rows][i]=path[i];cols[*rows]=len;(*rows)++;return;}for(int i=start;i<n&&c[i]<=t;i++){path[len]=c[i];comb(c,n,i,t-c[i],path,len+1,out,rows,cols,cap);}}
```

**Python 3 Solution**

```python
class Solution:
    def combinationSum(self, candidates, target):
        ans=[]
        def dfs(i,t,path):
            if t==0:ans.append(path[:]);return
            if t<0:return
            for j in range(i,len(candidates)):
                dfs(j,t-candidates[j],path+[candidates[j]])
        dfs(0,target,[]);return ans
```

---

## 29. Jump Game

**Problem**

Return whether the last array index is reachable when a[i] is the maximum jump length from i.

**Reasoning**

Greedily track the farthest reachable index. If the current index is beyond it, the end is unreachable.

**C++17 Solution**

```cpp
class Solution { public:
 bool canJump(vector<int>&a){int far=0;for(int i=0;i<(int)a.size();++i){if(i>far)return false;far=max(far,i+a[i]);}return true;}
};
```

**Test cases**

[2,3,1,1,4] -> true
[3,2,1,0,4] -> false

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
#include <stdbool.h>
bool canJump(int*a,int n){int reach=0;for(int i=0;i<n;i++){if(i>reach)return false;if(i+a[i]>reach)reach=i+a[i];}return true;}
```

**Python 3 Solution**

```python
class Solution:
    def canJump(self, nums):
        reach=0
        for i,x in enumerate(nums):
            if i>reach:return False
            reach=max(reach,i+x)
        return True
```

---

## 30. Jump Game II

**Problem**

Return the minimum jumps needed to reach the final index; reachability is guaranteed.

**Reasoning**

Treat each jump as a BFS layer. Scan the current reachable range and compute the farthest next range; increase jumps when the current range ends.

**C++17 Solution**

```cpp
class Solution { public:
 int jump(vector<int>&a){int jumps=0,end=0,far=0;for(int i=0;i<(int)a.size()-1;i++){far=max(far,i+a[i]);if(i==end){++jumps;end=far;}}return jumps;}
};
```

**Test cases**

[2,3,1,1,4] -> 2
[2,3,0,1,4] -> 2

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int jump(int*a,int n){int jumps=0,end=0,farthest=0;for(int i=0;i<n-1;i++){if(i+a[i]>farthest)farthest=i+a[i];if(i==end){jumps++;end=farthest;}}return jumps;}
```

**Python 3 Solution**

```python
class Solution:
    def jump(self, nums):
        jumps=end=farthest=0
        for i in range(len(nums)-1):
            farthest=max(farthest,i+nums[i])
            if i==end:jumps+=1;end=farthest
        return jumps
```

---

## 31. Merge Intervals

**Problem**

Merge all overlapping closed intervals.

**Reasoning**

Sort by start time. Extend the last merged interval while the next interval overlaps; otherwise start a new interval.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<int>> merge(vector<vector<int>>&a){sort(a.begin(),a.end());vector<vector<int>>r;for(auto &v:a){if(r.empty()||v[0]>r.back()[1])r.push_back(v);else r.back()[1]=max(r.back()[1],v[1]);}return r;}
};
```

**Test cases**

[[1,3],[2,6],[8,10],[15,18]] -> [[1,6],[8,10],[15,18]]

**Complexity** — O(n log n) time, O(n) output space

---

**C Solution**

```c
#include <stdlib.h>
int cmpInterval(const void*a,const void*b){int*ia=*(int**)a,*ib=*(int**)b;return ia[0]-ib[0];}
int** mergeIntervals(int**in,int n,int*col,int*rs,int**cs){qsort(in,n,sizeof(int*),cmpInterval);int**out=malloc(n*sizeof(int*));int k=0;for(int i=0;i<n;i++){if(!k||in[i][0]>out[k-1][1]){out[k]=malloc(2*sizeof(int));out[k][0]=in[i][0];out[k][1]=in[i][1];k++;}else if(in[i][1]>out[k-1][1])out[k-1][1]=in[i][1];}*rs=k;*cs=malloc(k*sizeof(int));for(int i=0;i<k;i++)(*cs)[i]=2;return out;}
```

**Python 3 Solution**

```python
class Solution:
    def merge(self, intervals):
        intervals.sort(); ans=[]
        for s,e in intervals:
            if not ans or s>ans[-1][1]:ans.append([s,e])
            else:ans[-1][1]=max(ans[-1][1],e)
        return ans
```

---

## 32. Insert Interval

**Problem**

Insert a new interval into a sorted non-overlapping list and merge overlaps.

**Reasoning**

Add intervals ending before new starts, merge all overlapping intervals, then append the remainder.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<int>> insert(vector<vector<int>>&a,vector<int> x){vector<vector<int>>r;int i=0,n=a.size();while(i<n&&a[i][1]<x[0])r.push_back(a[i++]);while(i<n&&a[i][0]<=x[1]){x[0]=min(x[0],a[i][0]);x[1]=max(x[1],a[i][1]);++i;}r.push_back(x);while(i<n)r.push_back(a[i++]);return r;}
};
```

**Test cases**

[[1,3],[6,9]],[2,5] -> [[1,5],[6,9]]
[],[5,7] -> [[5,7]]

**Complexity** — O(n) time, O(n) output space

---

**C Solution**

```c
#include <stdlib.h>
int** insertInterval(int**a,int n,int*col,int*nv,int*rs,int**cs){int**o=malloc((n+1)*sizeof(int*));int k=0,i=0,s=nv[0],e=nv[1];while(i<n&&a[i][1]<s){o[k]=malloc(2*sizeof(int));o[k][0]=a[i][0];o[k++][1]=a[i++][1];}while(i<n&&a[i][0]<=e){if(a[i][0]<s)s=a[i][0];if(a[i][1]>e)e=a[i][1];i++;}o[k]=malloc(2*sizeof(int));o[k][0]=s;o[k++][1]=e;while(i<n){o[k]=malloc(2*sizeof(int));o[k][0]=a[i][0];o[k++][1]=a[i++][1];}*rs=k;*cs=malloc(k*sizeof(int));for(i=0;i<k;i++)(*cs)[i]=2;return o;}
```

**Python 3 Solution**

```python
class Solution:
    def insert(self, intervals, newInterval):
        ans=[];i=0;n=len(intervals);s,e=newInterval
        while i<n and intervals[i][1]<s:ans.append(intervals[i]);i+=1
        while i<n and intervals[i][0]<=e:s=min(s,intervals[i][0]);e=max(e,intervals[i][1]);i+=1
        ans.append([s,e]);ans+=intervals[i:];return ans
```

---

## 33. Find All Anagrams in a String

**Problem**

Return start indices where p’s anagram occurs in s.

**Reasoning**

Keep a fixed-size window of p length and compare its 26-letter frequency counts.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> findAnagrams(string s,string p){vector<int>r; if(p.size()>s.size())return r;array<int,26>a{},b{};for(char c:p)++a[c-'a'];for(int i=0;i<(int)s.size();++i){++b[s[i]-'a'];if(i>=(int)p.size())--b[s[i-p.size()]-'a'];if(a==b)r.push_back(i-p.size()+1);}return r;}
};
```

**Test cases**

s="cbaebabacd", p="abc" -> [0,6]

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
#include <stdlib.h>
#include <string.h>
int* findAnagrams(char*s,char*p,int*rs){int a[26]={0},b[26]={0},n=strlen(s),m=strlen(p),*r=malloc((n+1)*sizeof(int)),k=0;if(m>n){*rs=0;return r;}for(int i=0;i<m;i++)a[p[i]-'a']++,b[s[i]-'a']++;for(int i=0;i<=n-m;i++){int ok=1;for(int j=0;j<26;j++)if(a[j]!=b[j])ok=0;if(ok)r[k++]=i;if(i<n-m)b[s[i]-'a']--,b[s[i+m]-'a']++;}*rs=k;return r;}
```

**Python 3 Solution**

```python
class Solution:
    def findAnagrams(self, s, p):
        from collections import Counter
        need=Counter(p); cur=Counter();ans=[];k=len(p)
        for i,c in enumerate(s):
            cur[c]+=1
            if i>=k: 
                old=s[i-k];cur[old]-=1
                if cur[old]==0:del cur[old]
            if cur==need:ans.append(i-k+1)
        return ans
```

---

## 34. Min Stack

**Problem**

Design a stack supporting push, pop, top, and retrieving the minimum in O(1).

**Reasoning**

Store each value together with the minimum seen up to that point, or maintain a second min stack.

**C++17 Solution**

```cpp
class MinStack { stack<pair<int,int>> st; public:
 void push(int x){st.push({x,st.empty()?x:min(x,st.top().second)});} void pop(){st.pop();} int top(){return st.top().first;} int getMin(){return st.top().second;}
};
```

**Test cases**

push(3),push(1),push(2),getMin() -> 1
pop(),getMin() -> 1

**Complexity** — O(1) per operation, O(n) space

---

**C Solution**

```c
#include <limits.h>
typedef struct{int v[10000],mn[10000],n;}MinStack;
void minStackPush(MinStack*s,int x){s->v[s->n]=x;s->mn[s->n]=s->n? (x<s->mn[s->n-1]?x:s->mn[s->n-1]) : x;s->n++;}
int minStackPop(MinStack*s){return s->v[--s->n];}
int minStackTop(MinStack*s){return s->v[s->n-1];}
int minStackGetMin(MinStack*s){return s->mn[s->n-1];}
```

**Python 3 Solution**

```python
class MinStack:
    def __init__(self): self.st=[]
    def push(self,val): self.st.append((val,min(val,self.st[-1][1] if self.st else val)))
    def pop(self): self.st.pop()
    def top(self): return self.st[-1][0]
    def getMin(self): return self.st[-1][1]
```

---

## 35. Car Fleet

**Problem**

Cars move toward the same target with positions and speeds. Cars merge into one fleet when a faster car catches a slower one. Return fleet count.

**Reasoning**

Sort cars by position descending. Compute each car’s time to target. If its time is greater than the current fleet time, it forms a new fleet; otherwise it joins the fleet ahead.

**C++17 Solution**

```cpp
class Solution { public:
 int carFleet(int target,vector<int>&p,vector<int>&s){vector<pair<int,double>>v;for(int i=0;i<(int)p.size();++i)v.push_back({p[i],(target-p[i])*1.0/s[i]});sort(v.rbegin(),v.rend());int ans=0;double last=0;for(auto [pos,t]:v)if(t>last){++ans;last=t;}return ans;}
};
```

**Test cases**

target=12, position=[10,8,0,5,3], speed=[2,4,1,1,3] -> 3

**Complexity** — O(n log n) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int carFleet(int target,int*pos,int n,int*speed){for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(pos[i]<pos[j]){int t=pos[i];pos[i]=pos[j];pos[j]=t;t=speed[i];speed[i]=speed[j];speed[j]=t;}double last=0;int fleets=0;for(int i=0;i<n;i++){double t=(double)(target-pos[i])/speed[i];if(t>last){fleets++;last=t;}}return fleets;}
```

**Python 3 Solution**

```python
class Solution:
    def carFleet(self,target,position,speed):
        times=sorted(((target-p)/s for p,s in zip(position,speed)),reverse=True); fleets=0; last=0
        for t in times:
            if t>last:fleets+=1;last=t
        return fleets
```

---

## 36. Time Based Key-Value Store

**Problem**

Set values at integer timestamps and query the value with greatest timestamp <= requested time.

**Reasoning**

For each key store pairs (timestamp,value) sorted by insertion time. Binary search the last timestamp not exceeding the query.

**C++17 Solution**

```cpp
class TimeMap { unordered_map<string,vector<pair<int,string>>> mp; public:
 void set(string k,string v,int t){mp[k].push_back({t,v});} string get(string k,int t){auto &v=mp[k];int l=0,r=v.size()-1,ans=-1;while(l<=r){int m=(l+r)/2;if(v[m].first<=t)ans=m,l=m+1;else r=m-1;}return ans<0?"":v[ans].second;}
};
```

**Test cases**

set("foo","bar",1); get("foo",1)->"bar"; get("foo",3)->"bar"; set("foo","bar2",4); get("foo",4)->"bar2"

**Complexity** — set O(1) amortized, get O(log n)

---

**C Solution**

```c
#include <stdlib.h>
#include <string.h>
typedef struct Entry{char*key;char*val;int ts;}Entry;
typedef struct{Entry e[10000];int n;}TimeMap;
void timeMapSet(TimeMap*m,char*k,char*v,int ts){m->e[m->n].key=strdup(k);m->e[m->n].val=strdup(v);m->e[m->n++].ts=ts;}
char*timeMapGet(TimeMap*m,char*k,int ts){char*ans="";int best=-1;for(int i=0;i<m->n;i++)if(strcmp(m->e[i].key,k)==0&&m->e[i].ts<=ts&&m->e[i].ts>best){best=m->e[i].ts;ans=m->e[i].val;}return ans;}
```

**Python 3 Solution**

```python
class TimeMap:
    def __init__(self): self.d={}
    def set(self,key,value,timestamp): self.d.setdefault(key,[]).append((timestamp,value))
    def get(self,key,timestamp):
        a=self.d.get(key,[]);l,r=0,len(a)-1;ans=''
        while l<=r:
            m=(l+r)//2
            if a[m][0]<=timestamp:ans=a[m][1];l=m+1
            else:r=m-1
        return ans
```

---

## 37. LRU Cache

**Problem**

Design a cache with fixed capacity supporting get/put in O(1), evicting the least recently used item.

**Reasoning**

Use a doubly linked list for recency order and a hash map from key to list iterator. Front is most recent; back is least recent.

**C++17 Solution**

```cpp
class LRUCache { int cap; list<pair<int,int>> dq; unordered_map<int,list<pair<int,int>>::iterator> mp; public:
 LRUCache(int c):cap(c){} int get(int k){if(!mp.count(k))return -1;auto it=mp[k];int v=it->second;dq.erase(it);dq.push_front({k,v});mp[k]=dq.begin();return v;} void put(int k,int v){if(mp.count(k))dq.erase(mp[k]);dq.push_front({k,v});mp[k]=dq.begin();if((int)dq.size()>cap){auto x=dq.back();mp.erase(x.first);dq.pop_back();}}
};
```

**Test cases**

capacity=2: put(1,1),put(2,2),get(1)->1,put(3,3),get(2)->-1

**Complexity** — O(1) average per operation, O(capacity) space

---

**C Solution**

```c
#include <stdlib.h>
typedef struct Node{int key,val;struct Node*prev,*next;}Node;
typedef struct{int cap,n;Node head,tail;Node**map;}LRUCache;
void removeN(LRUCache*c,Node*x){x->prev->next=x->next;x->next->prev=x->prev;}
void front(LRUCache*c,Node*x){x->next=c->head.next;x->prev=&c->head;c->head.next->prev=x;c->head.next=x;}
LRUCache* lRUCacheCreate(int cap){LRUCache*c=calloc(1,sizeof(LRUCache));c->cap=cap;c->head.next=&c->tail;c->tail.prev=&c->head;c->map=calloc(100001,sizeof(Node*));return c;}
int lRUCacheGet(LRUCache*c,int key){if(key<0||key>100000||!c->map[key])return -1;Node*x=c->map[key];removeN(c,x);front(c,x);return x->val;}
void lRUCachePut(LRUCache*c,int key,int value){if(c->map[key]){Node*x=c->map[key];x->val=value;removeN(c,x);front(c,x);return;}if(c->n==c->cap){Node*x=c->tail.prev;c->map[x->key]=0;removeN(c,x);free(x);c->n--;}Node*x=malloc(sizeof(Node));x->key=key;x->val=value;c->map[key]=x;front(c,x);c->n++;}
```

**Python 3 Solution**

```python
from collections import OrderedDict
class LRUCache:
    def __init__(self,capacity): self.cap=capacity;self.d=OrderedDict()
    def get(self,key):
        if key not in self.d:return -1
        self.d.move_to_end(key);return self.d[key]
    def put(self,key,value):
        if key in self.d:self.d.move_to_end(key)
        self.d[key]=value
        if len(self.d)>self.cap:self.d.popitem(last=False)
```

---

## 38. Serialize and Deserialize Binary Tree

**Problem**

Convert a binary tree to a string and rebuild the same tree.

**Reasoning**

Preorder traversal with a null marker uniquely describes the tree. During deserialization consume tokens recursively in the same order.

**C++17 Solution**

```cpp
class Codec { public:
 void enc(TreeNode*r,string& s){if(!r){s+="#,";return;}s+=to_string(r->val)+",";enc(r->left,s);enc(r->right,s);} string serialize(TreeNode*r){string s;enc(r,s);return s;} TreeNode* dec(stringstream& ss){string x;getline(ss,x,',');if(x=="#")return nullptr;TreeNode*n=new TreeNode(stoi(x));n->left=dec(ss);n->right=dec(ss);return n;} TreeNode* deserialize(string s){stringstream ss(s);return dec(ss);}
};
```

**Test cases**

Tree [1,2,3,null,null,4,5] -> serialize -> deserialize -> identical tree

**Complexity** — O(n) time, O(n) space

---

**C Solution**

```c
typedef struct TreeNode{int val;struct TreeNode*left,*right;}TreeNode;
void ser(TreeNode*r,char*buf,int*idx){if(!r){buf[(*idx)++]='#';buf[(*idx)++]=',';return;}*idx+=sprintf(buf+*idx,"%d,",r->val);ser(r->left,buf,idx);ser(r->right,buf,idx);}
```

**Python 3 Solution**

```python
class Codec:
    def serialize(self,root):
        out=[]
        def dfs(n):
            if not n:out.append('#');return
            out.append(str(n.val));dfs(n.left);dfs(n.right)
        dfs(root);return ','.join(out)
    def deserialize(self,data):
        it=iter(data.split(','))
        def dfs():
            x=next(it)
            if x=='#':return None
            n=TreeNode(int(x));n.left=dfs();n.right=dfs();return n
        return dfs()
```

---

## 39. Graph Valid Tree

**Problem**

Given n nodes and undirected edges, determine whether the graph is a single connected acyclic tree.

**Reasoning**

A tree has exactly n-1 edges and must be connected. Build a DSU; if an edge joins nodes already in the same set, a cycle exists.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> p; int find(int x){return p[x]==x?x:p[x]=find(p[x]);} bool validTree(int n,vector<vector<int>>&e){if(e.size()!=n-1)return false;p.resize(n);iota(p.begin(),p.end(),0);for(auto &x:e){int a=find(x[0]),b=find(x[1]);if(a==b)return false;p[a]=b;}return true;}
};
```

**Test cases**

n=5, edges=[[0,1],[0,2],[0,3],[1,4]] -> true
n=5, edges=[[0,1],[1,2],[2,3],[1,3],[1,4]] -> false

**Complexity** — O(E α(n)) time, O(n) space

---

**C Solution**

```c
int findp(int*p,int x){return p[x]==x?x:(p[x]=findp(p,p[x]));}
int validTree(int n,int**e,int edges){if(edges!=n-1)return 0;int*p=malloc(n*sizeof(int));for(int i=0;i<n;i++)p[i]=i;for(int i=0;i<edges;i++){int a=findp(p,e[i][0]),b=findp(p,e[i][1]);if(a==b){free(p);return 0;}p[a]=b;}free(p);return 1;}
```

**Python 3 Solution**

```python
class Solution:
    def validTree(self,n,edges):
        if len(edges)!=n-1:return False
        p=list(range(n))
        def find(x):
            while p[x]!=x:p[x]=p[p[x]];x=p[x]
            return x
        for a,b in edges:
            a,b=find(a),find(b)
            if a==b:return False
            p[a]=b
        return True
```

---

## 40. Course Schedule

**Problem**

Given prerequisite pairs, determine whether all courses can be completed.

**Reasoning**

This is cycle detection in a directed graph. Kahn’s algorithm repeatedly removes zero-indegree nodes. If fewer than n nodes are processed, a cycle exists.

**C++17 Solution**

```cpp
class Solution { public:
 bool canFinish(int n,vector<vector<int>>&pre){vector<vector<int>>g(n);vector<int>in(n);for(auto&p:pre){g[p[1]].push_back(p[0]);++in[p[0]];}queue<int>q;for(int i=0;i<n;i++)if(!in[i])q.push(i);int cnt=0;while(!q.empty()){int u=q.front();q.pop();++cnt;for(int v:g[u])if(!--in[v])q.push(v);}return cnt==n;}
};
```

**Test cases**

2, [[1,0]] -> true
2, [[1,0],[0,1]] -> false

**Complexity** — O(V+E) time, O(V+E) space

---

**C Solution**

```c
#include <stdlib.h>
int canFinish(int n,int**pre,int m){int*deg=calloc(n,sizeof(int)),*q=malloc(n*sizeof(int)),*g=calloc(n*n,sizeof(int));for(int i=0;i<m;i++){int a=pre[i][0],b=pre[i][1];g[b*n+a]=1;deg[a]++;}int h=0,t=0;for(int i=0;i<n;i++)if(!deg[i])q[t++]=i;int cnt=0;while(h<t){int u=q[h++];cnt++;for(int v=0;v<n;v++)if(g[u*n+v]&&--deg[v]==0)q[t++]=v;}free(deg);free(q);free(g);return cnt==n;}
```

**Python 3 Solution**

```python
class Solution:
    def canFinish(self,numCourses,prerequisites):
        g=[[] for _ in range(numCourses)];deg=[0]*numCourses
        for a,b in prerequisites:g[b].append(a);deg[a]+=1
        q=[i for i,d in enumerate(deg) if d==0];cnt=0
        for x in q:
            cnt+=1
            for y in g[x]:deg[y]-=1; q.append(y) if deg[y]==0 else None
        return cnt==numCourses
```

---

