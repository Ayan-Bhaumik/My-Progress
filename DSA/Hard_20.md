# Hard — 20 Problems

## 1. Trapping Rain Water

**Problem**

Given bar heights, compute how much water remains after raining.

**Reasoning**

Two pointers keep left/right maximum boundaries. The side with the smaller boundary determines the water level, so process that side and advance it.

**C++17 Solution**

```cpp
class Solution { public:
 int trap(vector<int>&h){int l=0,r=h.size()-1,lm=0,rm=0,ans=0;while(l<r){if(h[l]<=h[r]){lm=max(lm,h[l]);ans+=lm-h[l];++l;}else{rm=max(rm,h[r]);ans+=rm-h[r];--r;}}return ans;}
};
```

**Test cases**

[0,1,0,2,1,0,1,3,2,1,2,1] -> 6
[4,2,0,3,2,5] -> 9

**Complexity** — O(n) time, O(1) space

---

**C Solution**

```c
int trap(int*h,int n){int l=0,r=n-1,lm=0,rm=0,ans=0;while(l<r){if(h[l]<=h[r]){if(h[l]>lm)lm=h[l];ans+=lm-h[l];l++;}else{if(h[r]>rm)rm=h[r];ans+=rm-h[r];r--;}}return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def trap(self,h):
        l,r=0,len(h)-1;lm=rm=ans=0
        while l<r:
            if h[l]<=h[r]:lm=max(lm,h[l]);ans+=lm-h[l];l+=1
            else:rm=max(rm,h[r]);ans+=rm-h[r];r-=1
        return ans
```

---

## 2. Minimum Window Substring

**Problem**

Return the smallest substring of s containing all characters of t with required multiplicities.

**Reasoning**

Use a sliding window with counts. Expand right until all required characters are covered, then shrink left while maintaining validity.

**C++17 Solution**

```cpp
class Solution { public:
 string minWindow(string s,string t){array<int,128>need{};for(char c:t)++need[c];int missing=t.size(),l=0,best=INT_MAX,st=0;for(int r=0;r<(int)s.size();++r){if(need[s[r]]>0)--missing;--need[s[r]];while(missing==0){if(r-l+1<best)best=r-l+1,st=l;if(++need[s[l]]>0)++missing;++l;}}return best==INT_MAX?"":s.substr(st,best);}
};
```

**Test cases**

s="ADOBECODEBANC", t="ABC" -> "BANC"
s="a", t="aa" -> ""

**Complexity** — O(|s|+|t|) time, O(alphabet) space

---

**C Solution**

```c
#include <limits.h>
#include <string.h>
char* minWindow(char*s,char*t){int need[128]={0};for(int i=0;t[i];i++)need[(unsigned char)t[i]]++;int missing=strlen(t),l=0,st=0,best=INT_MAX;for(int r=0;s[r];r++){unsigned char c=s[r];if(need[c]>0)missing--;need[c]--;while(!missing){if(r-l+1<best)best=r-l+1,st=l;unsigned char x=s[l++];need[x]++;if(need[x]>0)missing++;}}char*r=malloc((best==INT_MAX?1:best+1));if(best==INT_MAX){r[0]=0;return r;}memcpy(r,s+st,best);r[best]=0;return r;}
```

**Python 3 Solution**

```python
class Solution:
    def minWindow(self,s,t):
        from collections import Counter
        need=Counter(t);missing=len(t);l=0;best=(10**9,0,0)
        for r,c in enumerate(s):
            if need[c]>0:missing-=1
            need[c]-=1
            while missing==0:
                if r-l+1<best[0]:best=(r-l+1,l,r+1)
                need[s[l]]+=1
                if need[s[l]]>0:missing+=1
                l+=1
        return s[best[1]:best[2]] if best[0]<10**9 else ''
```

---

## 3. Largest Rectangle in Histogram

**Problem**

Return the largest rectangle area in a histogram.

**Reasoning**

Maintain increasing bar indices. When a shorter bar appears, pop bars whose maximum rectangle ends here; the new left boundary is the remaining stack top + 1.

**C++17 Solution**

```cpp
class Solution { public:
 int largestRectangleArea(vector<int>&h){stack<int>st;int ans=0,n=h.size();for(int i=0;i<=n;i++){int cur=(i==n?0:h[i]);while(!st.empty()&&h[st.top()]>cur){int ht=h[st.top()];st.pop();int l=st.empty()?0:st.top()+1;ans=max(ans,ht*(i-l));}st.push(i);}return ans;}
};
```

**Test cases**

[2,1,5,6,2,3] -> 10
[2,4] -> 4

**Complexity** — O(n) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int largestRectangleArea(int*h,int n){int*st=malloc((n+1)*sizeof(int)),top=0,ans=0;for(int i=0;i<=n;i++){int cur=i==n?0:h[i];while(top&&h[st[top-1]]>cur){int j=st[--top],left=top?st[top-1]:-1,x=h[j]*(i-left-1);if(x>ans)ans=x;}st[top++]=i;}free(st);return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def largestRectangleArea(self,h):
        st=[];ans=0
        for i,x in enumerate(h+[0]):
            while st and h[st[-1]]>x:
                j=st.pop();left=st[-1] if st else -1;ans=max(ans,h[j]*(i-left-1))
            st.append(i)
        return ans
```

---

## 4. Sliding Window Maximum

**Problem**

For every window of size k, return its maximum value.

**Reasoning**

A decreasing deque stores indices whose values may still become maxima. Remove expired indices from the front and smaller values from the back.

**C++17 Solution**

```cpp
class Solution { public:
 vector<int> maxSlidingWindow(vector<int>&a,int k){deque<int>dq;vector<int>r;for(int i=0;i<(int)a.size();++i){while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();while(!dq.empty()&&a[dq.back()]<=a[i])dq.pop_back();dq.push_back(i);if(i>=k-1)r.push_back(a[dq.front()]);}return r;}
};
```

**Test cases**

[1,3,-1,-3,5,3,6,7],3 -> [3,3,5,5,6,7]

**Complexity** — O(n) time, O(k) space

---

**C Solution**

```c
#include <stdlib.h>
int* maxSlidingWindow(int*a,int n,int k,int*rs){int*r=malloc((n-k+1)*sizeof(int)),*q=malloc(n*sizeof(int));int h=0,t=0,z=0;for(int i=0;i<n;i++){while(h<t&&q[h]<=i-k)h++;while(h<t&&a[q[t-1]]<=a[i])t--;q[t++]=i;if(i>=k-1)r[z++]=a[q[h]];}free(q);*rs=z;return r;}
```

**Python 3 Solution**

```python
class Solution:
    def maxSlidingWindow(self,nums,k):
        from collections import deque
        q=deque();ans=[]
        for i,x in enumerate(nums):
            while q and q[0]<=i-k:q.popleft()
            while q and nums[q[-1]]<=x:q.pop()
            q.append(i)
            if i>=k-1:ans.append(nums[q[0]])
        return ans
```

---

## 5. Word Search

**Problem**

Determine whether a word can be formed by walking horizontally/vertically adjacent board cells without reusing a cell.

**Reasoning**

Backtracking marks the current cell as visited, explores four directions, then restores the cell. Early checks prune impossible starts.

**C++17 Solution**

```cpp
class Solution { public:
 bool dfs(vector<vector<char>>&b,string&w,int r,int c,int i){if(i==(int)w.size())return true;if(r<0||c<0||r>=b.size()||c>=b[0].size()||b[r][c]!=w[i])return false;char save=b[r][c];b[r][c]='#';bool ok=dfs(b,w,r+1,c,i+1)||dfs(b,w,r-1,c,i+1)||dfs(b,w,r,c+1,i+1)||dfs(b,w,r,c-1,i+1);b[r][c]=save;return ok;} bool exist(vector<vector<char>>&b,string w){for(int i=0;i<b.size();i++)for(int j=0;j<b[0].size();j++)if(dfs(b,w,i,j,0))return true;return false;}
};
```

**Test cases**

board=[[A,B,C,E],[S,F,C,S],[A,D,E,E]], word="ABCCED" -> true
word="SEE" -> true
word="ABCB" -> false

**Complexity** — O(R*C*4^L) worst case, O(L) recursion

---

**C Solution**

```c
#include <stdbool.h>
bool wdfs(char**b,int R,int C,int r,int c,char*w,int k){if(!w[k])return true;if(r<0||r>=R||c<0||c>=C||b[r][c]!=w[k])return false;char x=b[r][c];b[r][c]='#';bool ok=wdfs(b,R,C,r+1,c,w,k+1)||wdfs(b,R,C,r-1,c,w,k+1)||wdfs(b,R,C,r,c+1,w,k+1)||wdfs(b,R,C,r,c-1,w,k+1);b[r][c]=x;return ok;}
bool exist(char**b,int R,int*C,char*w){for(int r=0;r<R;r++)for(int c=0;c<*C;c++)if(wdfs(b,R,*C,r,c,w,0))return true;return false;}
```

**Python 3 Solution**

```python
class Solution:
    def exist(self,b,word):
        R,C=len(b),len(b[0])
        def dfs(r,c,i):
            if i==len(word):return True
            if not(0<=r<R and 0<=c<C) or b[r][c]!=word[i]:return False
            ch=b[r][c];b[r][c]='#'
            ok=any(dfs(r+dr,c+dc,i+1) for dr,dc in ((1,0),(-1,0),(0,1),(0,-1)))
            b[r][c]=ch;return ok
        return any(dfs(r,c,0) for r in range(R) for c in range(C))
```

---

## 6. N-Queens

**Problem**

Place n queens on an n×n board so no two queens share a row, column, or diagonal. Return all valid boards.

**Reasoning**

Place exactly one queen per row. Track used columns and the two diagonal families with boolean arrays; backtrack after each choice.

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<string>>ans; vector<int>col,d1,d2; vector<string>b; int n; void dfs(int r){if(r==n){ans.push_back(b);return;}for(int c=0;c<n;c++){int x=r-c+n,y=r+c;if(col[c]||d1[x]||d2[y])continue;col[c]=d1[x]=d2[y]=1;b[r][c]='Q';dfs(r+1);b[r][c]='.';col[c]=d1[x]=d2[y]=0;}} vector<vector<string>> solveNQueens(int N){n=N;b.assign(n,string(n,'.'));col.assign(n,0);d1.assign(2*n,0);d2.assign(2*n,0);dfs(0);return ans;}
};
```

**Test cases**

n=4 -> 2 solutions
n=1 -> [["Q"]]

**Complexity** — O(n!) time roughly, O(n^2) output space

---

**C Solution**

```c
#include <stdlib.h>
#include <string.h>
void nq(int r,int n,int*col,int*d1,int*d2,char**b,char***out,int*cnt){if(r==n){out[*cnt]=malloc(n*sizeof(char*));for(int i=0;i<n;i++){out[*cnt][i]=malloc(n+1);strcpy(out[*cnt][i],b[i]);}(*cnt)++;return;}for(int c=0;c<n;c++)if(!col[c]&&!d1[r-c+n-1]&&!d2[r+c]){col[c]=d1[r-c+n-1]=d2[r+c]=1;b[r][c]='Q';nq(r+1,n,col,d1,d2,b,out,cnt);b[r][c]='.';col[c]=d1[r-c+n-1]=d2[r+c]=0;}}
char*** solveNQueens(int n,int*rs,int**cs){int cap=1000,cnt=0,*col=calloc(n,4),*d1=calloc(2*n,4),*d2=calloc(2*n,4);char**b=malloc(n*sizeof(char*));char***out=malloc(cap*sizeof(char**));for(int i=0;i<n;i++){b[i]=malloc(n+1);memset(b[i],'.',n);b[i][n]=0;}nq(0,n,col,d1,d2,b,out,&cnt);*rs=cnt;*cs=malloc(cnt*sizeof(int));for(int i=0;i<cnt;i++)(*cs)[i]=n;free(col);free(d1);free(d2);for(int i=0;i<n;i++)free(b[i]);free(b);return out;}
```

**Python 3 Solution**

```python
class Solution:
    def solveNQueens(self,n):
        ans=[];cols=set();d1=set();d2=set();board=[['.']*n for _ in range(n)]
        def dfs(r):
            if r==n:ans.append([''.join(x) for x in board]);return
            for c in range(n):
                if c in cols or r-c in d1 or r+c in d2:continue
                cols.add(c);d1.add(r-c);d2.add(r+c);board[r][c]='Q';dfs(r+1)
                board[r][c]='.';cols.remove(c);d1.remove(r-c);d2.remove(r+c)
        dfs(0);return ans
```

---

## 7. Merge K Sorted Lists

**Problem**

Merge k sorted linked lists into one sorted list.

**Reasoning**

Put the head of each list into a min-heap keyed by node value. Pop the smallest, append it, and push its next node.

**C++17 Solution**

```cpp
class Solution { public:
 ListNode* mergeKLists(vector<ListNode*>&lists){auto cmp=[](ListNode*a,ListNode*b){return a->val>b->val;};priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>pq(cmp);for(auto*n:lists)if(n)pq.push(n);ListNode d,*cur=&d;while(!pq.empty()){auto*n=pq.top();pq.pop();cur->next=n;cur=cur->next;if(n->next)pq.push(n->next);}cur->next=nullptr;return d.next;}
};
```

**Test cases**

[[1,4,5],[1,3,4],[2,6]] -> [1,1,2,3,4,4,5,6]

**Complexity** — O(N log k) time, O(k) heap space

---

**C Solution**

```c
#include <stdlib.h>
typedef struct ListNode{int val;struct ListNode*next;}ListNode;
void hs(ListNode**h,int n,int i){while(1){int a=i,l=2*i+1,r=l+1;if(l<n&&h[l]->val<h[a]->val)a=l;if(r<n&&h[r]->val<h[a]->val)a=r;if(a==i)break;ListNode*t=h[a];h[a]=h[i];h[i]=t;i=a;}}
ListNode* mergeKLists(ListNode**lists,int k){ListNode**h=malloc(k*sizeof(ListNode*));int n=0;for(int i=0;i<k;i++)if(lists[i])h[n++]=lists[i];for(int i=n/2-1;i>=0;i--)hs(h,n,i);ListNode d={0,0},*cur=&d;while(n){ListNode*x=h[0];cur->next=x;cur=cur->next;if(x->next)h[0]=x->next;else{h[0]=h[--n];}if(n)hs(h,n,0);}free(h);return d.next;}
```

**Python 3 Solution**

```python
class Solution:
    def mergeKLists(self,lists):
        import heapq
        h=[]
        for i,n in enumerate(lists):
            if n:heapq.heappush(h,(n.val,i,n))
        d=cur=ListNode(0)
        while h:
            _,i,n=heapq.heappop(h);cur.next=n;cur=cur.next
            if n.next:heapq.heappush(h,(n.next.val,i,n.next))
        return d.next
```

---

## 8. Word Ladder

**Problem**

Given begin word, end word and a dictionary, return the length of the shortest one-letter transformation sequence.

**Reasoning**

This is unweighted shortest path. BFS explores words by distance. Generate all one-letter mutations and visit each valid word once.

**C++17 Solution**

```cpp
class Solution { public:
 int ladderLength(string b,string e,vector<string>&w){unordered_set<string>s(w.begin(),w.end());if(!s.count(e))return 0;queue<string>q;q.push(b);int d=1;while(!q.empty()){int z=q.size();while(z--){string x=q.front();q.pop();if(x==e)return d;for(int i=0;i<x.size();i++){char old=x[i];for(char c='a';c<='z';c++){x[i]=c;if(s.count(x)){s.erase(x);q.push(x);}}x[i]=old;}}++d;}return 0;}
};
```

**Test cases**

begin="hit", end="cog", words=["hot","dot","dog","lot","log","cog"] -> 5

**Complexity** — O(L*26*N) time, O(N) space

---

**C Solution**

```c
#include <string.h>
#include <stdlib.h>
int diff1(const char*a,const char*b){int d=0;for(int i=0;a[i];i++)if(a[i]!=b[i]&&++d>1)return 0;return d==1;}
int ladderLength(char*beginWord,char*endWord,char**wordList,int n){int *dist=calloc(n,sizeof(int)),*q=malloc((n+1)*sizeof(int)),start=-1,end=-1;for(int i=0;i<n;i++){if(strcmp(wordList[i],endWord)==0)end=i;if(strcmp(wordList[i],beginWord)==0)start=i;}if(end<0)return 0;int head=0,tail=0; q[tail++]=n;int steps=1;char**all=malloc((n+1)*sizeof(char*));for(int i=0;i<n;i++)all[i]=wordList[i];all[n]=beginWord;dist[n]=1;while(head<tail){int u=q[head++];if(u==end){int r=dist[u];free(dist);free(q);free(all);return r;}for(int v=0;v<n;v++)if(!dist[v]&&diff1(all[u],all[v]))dist[v]=dist[u]+1,q[tail++]=v;if(u==n){for(int v=0;v<n;v++)if(dist[v]==2&&diff1(beginWord,all[v])){} }}free(dist);free(q);free(all);return 0;}
```

**Python 3 Solution**

```python
class Solution:
    def ladderLength(self,beginWord,endWord,wordList):
        words=set(wordList)
        if endWord not in words:return 0
        q=[beginWord];dist={beginWord:1}
        for w in q:
            if w==endWord:return dist[w]
            for i in range(len(w)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    nw=w[:i]+c+w[i+1:]
                    if nw in words and nw not in dist:
                        dist[nw]=dist[w]+1;q.append(nw)
        return 0
```

---

## 9. Alien Dictionary

**Problem**

Given words sorted according to an unknown alphabet, derive a valid character order or return empty if impossible.

**Reasoning**

Compare adjacent words to find the first differing character, which gives a directed precedence edge. Then topologically sort the graph; a cycle means no valid order.

**C++17 Solution**

```cpp
class Solution { public:
 string alienOrder(vector<string>&w){unordered_map<char,unordered_set<char>>g;unordered_map<char,int>in;for(auto&s:w)for(char c:s)in[c]=0;for(int i=0;i+1<w.size();i++){string&a=w[i],&b=w[i+1];int j=0;while(j<a.size()&&j<b.size()&&a[j]==b[j])j++;if(j==b.size()&&j<a.size())return "";if(j<a.size()&&j<b.size()&&!g[a[j]].count(b[j])){g[a[j]].insert(b[j]);++in[b[j]];}}queue<char>q;for(auto [c,d]:in)if(!d)q.push(c);string r;while(!q.empty()){char c=q.front();q.pop();r+=c;for(char v:g[c])if(!--in[v])q.push(v);}return r.size()==in.size()?r:"";}
};
```

**Test cases**

["wrt","wrf","er","ett","rftt"] -> "wertf"
["abc","ab"] -> ""

**Complexity** — O(total input length + edges) time, O(alphabet + edges) space

---

**C Solution**

```c
#include <stdlib.h>
#include <string.h>
char* alienOrder(char**w,int n){int g[26][26]={0},deg[26]={0},seen[26]={0};for(int i=0;i<n;i++)for(int j=0;w[i][j];j++)seen[w[i][j]-'a']=1;for(int i=0;i<n-1;i++){int j=0;while(w[i][j]&&w[i+1][j]&&w[i][j]==w[i+1][j])j++;if(!w[i+1][j]&&w[i][j])return strdup("");if(w[i][j]&&w[i+1][j]){int a=w[i][j]-'a',b=w[i+1][j]-'a';if(!g[a][b])g[a][b]=1,deg[b]++;}}int q[26],h=0,t=0;for(int i=0;i<26;i++)if(seen[i]&&!deg[i])q[t++]=i;char*out=malloc(27);int k=0;while(h<t){int u=q[h++];out[k++]=u+'a';for(int v=0;v<26;v++)if(g[u][v]&&!--deg[v])q[t++]=v;}out[k]=0;return k==0?strdup(""):out;}
```

**Python 3 Solution**

```python
class Solution:
    def alienOrder(self,words):
        g={c:set() for w in words for c in w};deg={c:0 for c in g}
        for a,b in zip(words,words[1:]):
            if len(a)>len(b) and a.startswith(b):return ''
            for x,y in zip(a,b):
                if x!=y:
                    if y not in g[x]:g[x].add(y);deg[y]+=1
                    break
        q=[c for c in deg if deg[c]==0];ans=''
        for c in q:
            ans+=c
            for y in g[c]:deg[y]-=1; q.append(y) if deg[y]==0 else None
        return ans if len(ans)==len(g) else ''
```

---

## 10. Median of Two Sorted Arrays

**Problem**

Return the median of two sorted arrays in O(log(min(m,n))) time.

**Reasoning**

Binary-search the partition in the smaller array so left halves contain half the elements and every left value <= every right value.

**C++17 Solution**

```cpp
class Solution { public:
 double findMedianSortedArrays(vector<int>&A,vector<int>&B){if(A.size()>B.size())return findMedianSortedArrays(B,A);int m=A.size(),n=B.size(),lo=0,hi=m;while(lo<=hi){int i=(lo+hi)/2,j=(m+n+1)/2-i;int al=i?A[i-1]:INT_MIN,ar=i<m?A[i]:INT_MAX,bl=j?B[j-1]:INT_MIN,br=j<n?B[j]:INT_MAX;if(al<=br&&bl<=ar){if((m+n)%2)return max(al,bl);return (max(al,bl)+min(ar,br))/2.0;}if(al>br)hi=i-1;else lo=i+1;}return 0;}
};
```

**Test cases**

[1,3],[2] -> 2.0
[1,2],[3,4] -> 2.5

**Complexity** — O(log min(m,n)) time, O(1) space

---

**C Solution**

```c
#include <limits.h>
double findMedianSortedArrays(int*A,int m,int*B,int n){if(m>n)return findMedianSortedArrays(B,n,A,m);int lo=0,hi=m,total=m+n;while(lo<=hi){int i=(lo+hi)/2,j=(total+1)/2-i;int al=i?A[i-1]:INT_MIN,ar=i<m?A[i]:INT_MAX,bl=j?B[j-1]:INT_MIN,br=j<n?B[j]:INT_MAX;if(al<=br&&bl<=ar){if(total%2)return al>bl?al:bl;int x=al>bl?al:bl,y=ar<br?ar:br;return (x+y)/2.0;}if(al>br)hi=i-1;else lo=i+1;}return 0;}
```

**Python 3 Solution**

```python
class Solution:
    def findMedianSortedArrays(self,A,B):
        if len(A)>len(B):A,B=B,A
        m,n=len(A),len(B);lo,hi=0,m
        while lo<=hi:
            i=(lo+hi)//2;j=(m+n+1)//2-i
            al=A[i-1] if i else float('-inf');ar=A[i] if i<m else float('inf')
            bl=B[j-1] if j else float('-inf');br=B[j] if j<n else float('inf')
            if al<=br and bl<=ar:
                if (m+n)%2:return max(al,bl)
                return (max(al,bl)+min(ar,br))/2
            if al>br:hi=i-1
            else:lo=i+1
```

---

## 11. Regular Expression Matching

**Problem**

Match a string against a pattern containing letters, . for any char, and * for zero or more of the previous token.

**Reasoning**

DP(i,j) means suffixes s[i:] and p[j:] match. A star either consumes one matching character and stays, or consumes zero and advances the pattern.

**C++17 Solution**

```cpp
class Solution { public:
 bool isMatch(string s,string p){int n=s.size(),m=p.size();vector<vector<char>>dp(n+1,vector<char>(m+1));dp[n][m]=1;for(int i=n;i>=0;i--)for(int j=m-1;j>=0;j--){bool first=i<n&&(p[j]==s[i]||p[j]=='.');if(j+1<m&&p[j+1]=='*')dp[i][j]=dp[i][j+2]||(first&&dp[i+1][j]);else dp[i][j]=first&&dp[i+1][j+1];}return dp[0][0];}
};
```

**Test cases**

s="aa", p="a" -> false
s="aa", p="a*" -> true
s="ab", p=".*" -> true

**Complexity** — O(n*m) time, O(n*m) space

---

**C Solution**

```c
#include <stdbool.h>
#include <string.h>
// Recursive memoization can be added using a (strlen(s)+1) x (strlen(p)+1) table.
bool isMatch(char*s,char*p){int n=strlen(s),m=strlen(p);bool dp[n+1][m+1];memset(dp,0,sizeof(dp));dp[n][m]=1;for(int i=n;i>=0;i--)for(int j=m-1;j>=0;j--){bool first=i<n&&(p[j]==s[i]||p[j]=='.');if(j+1<m&&p[j+1]=='*')dp[i][j]=dp[i][j+2]||(first&&dp[i+1][j]);else dp[i][j]=first&&dp[i+1][j+1];}return dp[0][0];}
```

**Python 3 Solution**

```python
class Solution:
    def isMatch(self,s,p):
        from functools import lru_cache
        @lru_cache(None)
        def dp(i,j):
            if j==len(p):return i==len(s)
            first=i<len(s) and (p[j]==s[i] or p[j]=='.')
            if j+1<len(p) and p[j+1]=='*':return dp(i,j+2) or (first and dp(i+1,j))
            return first and dp(i+1,j+1)
        return dp(0,0)
```

---

## 12. Edit Distance

**Problem**

Return the minimum insertions, deletions, and substitutions needed to convert one string to another.

**Reasoning**

DP over prefixes. If final characters match, copy the diagonal state; otherwise take 1 + min(delete, insert, replace).

**C++17 Solution**

```cpp
class Solution { public:
 int minDistance(string a,string b){int n=a.size(),m=b.size();vector<int>dp(m+1);iota(dp.begin(),dp.end(),0);for(int i=1;i<=n;i++){int prev=dp[0];dp[0]=i;for(int j=1;j<=m;j++){int old=dp[j];if(a[i-1]==b[j-1])dp[j]=prev;else dp[j]=1+min({dp[j],dp[j-1],prev});prev=old;}}return dp[m];}
};
```

**Test cases**

"horse","ros" -> 3
"intention","execution" -> 5

**Complexity** — O(n*m) time, O(m) space

---

**C Solution**

```c
#include <stdlib.h>
int minDistance(char*a,char*b){int n=strlen(a),m=strlen(b),*dp=malloc((m+1)*sizeof(int));for(int j=0;j<=m;j++)dp[j]=j;for(int i=1;i<=n;i++){int prev=dp[0];dp[0]=i;for(int j=1;j<=m;j++){int cur=dp[j];dp[j]=a[i-1]==b[j-1]?prev+0:1+(dp[j]<dp[j-1]?dp[j]:dp[j-1]);if(prev+1<dp[j])dp[j]=prev+1;prev=cur;}}int r=dp[m];free(dp);return r;}
```

**Python 3 Solution**

```python
class Solution:
    def minDistance(self,word1,word2):
        dp=list(range(len(word2)+1))
        for i,a in enumerate(word1,1):
            prev=dp[0];dp[0]=i
            for j,b in enumerate(word2,1):
                cur=dp[j];dp[j]=prev if a==b else 1+min(dp[j],dp[j-1],prev);prev=cur
        return dp[-1]
```

---

## 13. Burst Balloons

**Problem**

Choose a balloon order; bursting i earns left * i * right where neighboring unburst balloons determine left/right. Maximize coins.

**Reasoning**

Use interval DP with the last balloon burst in an interval. Once k is last, left and right intervals are independent.

**C++17 Solution**

```cpp
class Solution { public:
 int maxCoins(vector<int>a){a.insert(a.begin(),1);a.push_back(1);int n=a.size();vector<vector<int>>dp(n,vector<int>(n));for(int len=2;len<n;len++)for(int l=0;l+len<n;l++){int r=l+len;for(int k=l+1;k<r;k++)dp[l][r]=max(dp[l][r],a[l]*a[k]*a[r]+dp[l][k]+dp[k][r]);}return dp[0][n-1];}
};
```

**Test cases**

[3,1,5,8] -> 167
[1,5] -> 10

**Complexity** — O(n^3) time, O(n^2) space

---

**C Solution**

```c
#include <stdlib.h>
int maxCoins(int*nums,int n){int N=n+2,*a=malloc(N*sizeof(int));a[0]=a[N-1]=1;for(int i=0;i<n;i++)a[i+1]=nums[i];int*dp=calloc(N*N,sizeof(int));for(int len=2;len<N;len++)for(int l=0;l+len<N;l++){int r=l+len;for(int k=l+1;k<r;k++){int x=dp[l*N+k]+dp[k*N+r]+a[l]*a[k]*a[r];if(x>dp[l*N+r])dp[l*N+r]=x;}}int ans=dp[N-1],*dummy=0;ans=dp[N-1];int res=dp[N-1];free(a);free(dp);(void)dummy;return res;}
```

**Python 3 Solution**

```python
class Solution:
    def maxCoins(self,nums):
        a=[1]+nums+[1];n=len(a);dp=[[0]*n for _ in range(n)]
        for length in range(2,n):
            for l in range(0,n-length):
                r=l+length
                dp[l][r]=max(dp[l][k]+dp[k][r]+a[l]*a[k]*a[r] for k in range(l+1,r))
        return dp[0][-1]
```

---

## 14. Serialize and Deserialize BST

**Problem**

Serialize a BST compactly and reconstruct it without storing null markers.

**Reasoning**

Preorder of a BST plus value bounds is enough. Rebuild recursively: consume the next value only if it lies inside the current bound range.

**C++17 Solution**

```cpp
class Codec { vector<int>v; int i; void pre(TreeNode*n){if(!n)return;v.push_back(n->val);pre(n->left);pre(n->right);} TreeNode*build(long long lo,long long hi){if(i==v.size()||v[i]<=lo||v[i]>=hi)return nullptr;int x=v[i++];TreeNode*n=new TreeNode(x);n->left=build(lo,x);n->right=build(x,hi);return n;} public: string serialize(TreeNode*r){v.clear();pre(r);string s;for(int x:v)s+=to_string(x)+",";return s;} TreeNode*deserialize(string s){v.clear();i=0;stringstream ss(s);string x;while(getline(ss,x,','))if(!x.empty())v.push_back(stoi(x));return build(LLONG_MIN,LLONG_MAX);}};
```

**Test cases**

BST [8,5,1,7,10,12] -> preorder string -> identical BST

**Complexity** — O(n) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct TreeNode{int val;struct TreeNode*left,*right;}TreeNode;
void bstSer(TreeNode*r,char*buf,int*idx){if(!r)return;*idx+=sprintf(buf+*idx,"%d,",r->val);bstSer(r->left,buf,idx);bstSer(r->right,buf,idx);}
char* serialize(TreeNode*root){char*b=malloc(100000);int i=0;bstSer(root,b,&i);b[i]=0;return b;}
TreeNode* bstDes(int*a,int n,int*idx,long long lo,long long hi){if(*idx>=n||a[*idx]<=lo||a[*idx]>=hi)return 0;TreeNode*r=malloc(sizeof(TreeNode));r->val=a[(*idx)++];r->left=bstDes(a,n,idx,lo,r->val);r->right=bstDes(a,n,idx,r->val,hi);return r;}
TreeNode* deserialize(char*data){if(!data||!data[0])return 0;int*a=malloc(10000*sizeof(int)),n=0;char*p=data,*q;while(*p){a[n++]=strtol(p,&q,10);if(*q==',')q++;p=q;}int idx=0;TreeNode*r=bstDes(a,n,&idx,-2147483649LL,2147483648LL);free(a);return r;}
```

**Python 3 Solution**

```python
class Codec:
    def serialize(self,root):
        out=[]
        def dfs(n):
            if not n:return
            out.append(str(n.val));dfs(n.left);dfs(n.right)
        dfs(root);return ','.join(out)
    def deserialize(self,data):
        if not data:return None
        vals=list(map(int,data.split(',')));i=0
        def build(lo,hi):
            nonlocal i
            if i==len(vals) or not(lo<vals[i]<hi):return None
            v=vals[i];i+=1;n=TreeNode(v);n.left=build(lo,v);n.right=build(v,hi);return n
        return build(float('-inf'),float('inf'))
```

---

## 15. Maximal Rectangle

**Problem**

Find the largest all-1 rectangle in a binary matrix.

**Reasoning**

Treat each row as the base of a histogram: update column heights, then use the largest-rectangle-in-histogram algorithm for that row.

**C++17 Solution**

```cpp
class Solution { public:
 int hist(vector<int>&h){stack<int>st;int ans=0;for(int i=0;i<=h.size();i++){int x=i==h.size()?0:h[i];while(!st.empty()&&h[st.top()]>x){int ht=h[st.top()];st.pop();int l=st.empty()?0:st.top()+1;ans=max(ans,ht*(i-l));}st.push(i);}return ans;} int maximalRectangle(vector<vector<char>>&m){if(m.empty())return 0;vector<int>h(m[0].size());int ans=0;for(auto&r:m){for(int j=0;j<h.size();j++)h[j]=r[j]=='1'?h[j]+1:0;ans=max(ans,hist(h));}return ans;}
};
```

**Test cases**

[[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]] -> 6

**Complexity** — O(R*C) time, O(C) space

---

**C Solution**

```c
#include <stdlib.h>
int histMax(int*h,int n){int*st=malloc((n+1)*sizeof(int)),top=0,ans=0;for(int i=0;i<=n;i++){int x=i==n?0:h[i];while(top&&h[st[top-1]]>x){int j=st[--top],left=top?st[top-1]:-1,v=h[j]*(i-left-1);if(v>ans)ans=v;}st[top++]=i;}free(st);return ans;}
int maximalRectangle(char**m,int R,int*C){int*h=calloc(*C,sizeof(int)),ans=0;for(int i=0;i<R;i++){for(int j=0;j<*C;j++)h[j]=m[i][j]=='1'?h[j]+1:0;int x=histMax(h,*C);if(x>ans)ans=x;}free(h);return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def maximalRectangle(self,m):
        if not m:return 0
        h=[0]*len(m[0]);ans=0
        for row in m:
            for j,c in enumerate(row):h[j]=h[j]+1 if c=='1' else 0
            st=[]
            for i,x in enumerate(h+[0]):
                while st and h[st[-1]]>x:
                    j=st.pop();left=st[-1] if st else -1;ans=max(ans,h[j]*(i-left-1))
                st.append(i)
        return ans
```

---

## 16. Word Break II

**Problem**

Given a string and dictionary, return every sentence that can be formed by splitting the string into dictionary words.

**Reasoning**

Use DFS with memoization on the starting index. For each dictionary word matching the current prefix, solve the remaining suffix and prepend the chosen word.

**C++17 Solution**

```cpp
class Solution { public:
 unordered_map<int,vector<string>> memo; unordered_set<string> dict; vector<string> dfs(string&s,int i){if(memo.count(i))return memo[i];vector<string>r;if(i==s.size()){r.push_back("");return r;}for(int j=i;j<(int)s.size();j++){string w=s.substr(i,j-i+1);if(!dict.count(w))continue;for(string tail:dfs(s,j+1)){r.push_back(tail.empty()?w:w+" "+tail);}}return memo[i]=r;} vector<string> wordBreak(string s,vector<string>&w){dict=unordered_set<string>(w.begin(),w.end());memo.clear();return dfs(s,0);}
};
```

**Test cases**

s="catsanddog", dict=["cat","cats","and","sand","dog"] -> ["cat sand dog","cats and dog"]

**Complexity** — O(n^2 + output size) with memoized states; output can be exponential

---

**C Solution**

```c
#include <stdlib.h>
#include <string.h>
typedef struct { char **a; int n, cap; } StrList;
void addStr(StrList *v,const char*s){ if(v->n==v->cap){v->cap=v->cap?2*v->cap:4;v->a=realloc(v->a,v->cap*sizeof(char*));} v->a[v->n++]=strdup(s); }
void wbDfs(const char*s,int i,int n,char**dict,int d,char*path,int plen,StrList*res){
    if(i==n){path[plen]=0;addStr(res,path);return;}
    for(int k=0;k<d;k++){int L=strlen(dict[k]);if(i+L>n)continue;if(strncmp(s+i,dict[k],L))continue;int old=plen;if(plen){path[plen++]=' ';}memcpy(path+plen,dict[k],L);plen+=L;wbDfs(s,i+L,n,dict,d,path,plen,res);plen=old;}
}
char** wordBreakC(char*s,char**dict,int d,int*returnSize){StrList r={0};char*path=malloc(strlen(s)*2+1);wbDfs(s,0,strlen(s),dict,d,path,0,&r);free(path);*returnSize=r.n;return r.a;}
```

**Python 3 Solution**

```python
class Solution:
    def wordBreak(self,s,wordDict):
        words=set(wordDict);memo={}
        def dfs(i):
            if i==len(s):return ['']
            if i in memo:return memo[i]
            out=[]
            for j in range(i+1,len(s)+1):
                if s[i:j] in words:
                    for tail in dfs(j):out.append(s[i:j]+(' '+tail if tail else ''))
            memo[i]=out;return out
        return dfs(0)
```

---

## 17. Distinct Subsequences

**Problem**

Count how many subsequences of s equal t.

**Reasoning**

Let dp[j] count ways to form t[0..j) from processed characters. Scanning s, update j from right to left so each character is used once per state update.

**C++17 Solution**

```cpp
class Solution { public:
 long long numDistinct(string s,string t){vector<long long>dp(t.size()+1);dp[0]=1;for(char c:s)for(int j=t.size();j>=1;j--)if(c==t[j-1])dp[j]+=dp[j-1];return dp[t.size()];}
};
```

**Test cases**

s="rabbbit", t="rabbit" -> 3
s="babgbag", t="bag" -> 5

**Complexity** — O(|s||t|) time, O(|t|) space

---

**C Solution**

```c
#include <stdlib.h>
int numDistinct(char*s,char*t){int m=strlen(t);unsigned long long*dp=calloc(m+1,sizeof(unsigned long long));dp[0]=1;for(int i=0;s[i];i++)for(int j=m-1;j>=0;j--)if(s[i]==t[j])dp[j+1]+=dp[j];int r=(int)dp[m];free(dp);return r;}
```

**Python 3 Solution**

```python
class Solution:
    def numDistinct(self,s,t):
        dp=[0]*(len(t)+1);dp[0]=1
        for a in s:
            for j in range(len(t)-1,-1,-1):
                if a==t[j]:dp[j+1]+=dp[j]
        return dp[-1]
```

---

## 18. Sudoku Solver

**Problem**

Fill a partially completed 9×9 Sudoku board so every row, column, and 3×3 box contains digits 1–9 exactly once.

**Reasoning**

Backtracking tries legal digits. Track used digits for each row, column, and box; place one cell, recurse, and undo on failure.

**C++17 Solution**

```cpp
class Solution { public:
 bool solve(vector<vector<char>>&b,vector<int>&r,vector<int>&c,vector<int>&box){for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(b[i][j]=='.'){int z=(i/3)*3+j/3;for(int d=1;d<=9;d++){int bit=1<<d;if(r[i]&bit||c[j]&bit||box[z]&bit)continue;r[i]|=bit;c[j]|=bit;box[z]|=bit;b[i][j]='0'+d;if(solve(b,r,c,box))return true;b[i][j]='.';r[i]^=bit;c[j]^=bit;box[z]^=bit;}return false;}return true;} void solveSudoku(vector<vector<char>>&b){vector<int>r(9),c(9),box(9);for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(b[i][j]!='.'){int d=b[i][j]-'0',bit=1<<d;r[i]|=bit;c[j]|=bit;box[(i/3)*3+j/3]|=bit;}solve(b,r,c,box);}
};
```

**Test cases**

Standard Sudoku puzzle with one valid solution -> completed valid grid

**Complexity** — Exponential worst case, O(81) recursion space

---

**C Solution**

```c
#include <stdbool.h>
bool sudoku(char**b,int pos){while(pos<81&&b[pos/9][pos%9]!='.')pos++;if(pos==81)return true;int r=pos/9,c=pos%9,br=(r/3)*3,bc=(c/3)*3;for(char x='1';x<='9';x++){int ok=1;for(int j=0;j<9;j++)if(b[r][j]==x||b[j][c]==x||b[br+j/3][bc+j%3]==x)ok=0;if(ok){b[r][c]=x;if(sudoku(b,pos+1))return true;b[r][c]='.';}}return false;}
void solveSudokuC(char**b,int n,int*cols){(void)n;(void)cols;sudoku(b,0);}
```

**Python 3 Solution**

```python
class Solution:
    def solveSudoku(self,b):
        rows=[set() for _ in range(9)];cols=[set() for _ in range(9)];box=[set() for _ in range(9)];todo=[]
        for r in range(9):
            for c in range(9):
                if b[r][c]=='.':todo.append((r,c))
                else: rows[r].add(b[r][c]);cols[c].add(b[r][c]);box[(r//3)*3+c//3].add(b[r][c])
        def dfs(k):
            if k==len(todo):return True
            r,c=todo[k];z=(r//3)*3+c//3
            for x in '123456789':
                if x not in rows[r] and x not in cols[c] and x not in box[z]:
                    b[r][c]=x;rows[r].add(x);cols[c].add(x);box[z].add(x)
                    if dfs(k+1):return True
                    rows[r].remove(x);cols[c].remove(x);box[z].remove(x);b[r][c]='.'
            return False
        dfs(0)
```

---

## 19. Critical Connections

**Problem**

In an undirected network, find every edge whose removal disconnects the graph.

**Reasoning**

Tarjan DFS assigns discovery times and low-link values. An edge u-v is a bridge when low[v] > discovery[u].

**C++17 Solution**

```cpp
class Solution { public:
 vector<vector<int>>ans; vector<vector<int>>g; vector<int>tin,low; int timer=0; void dfs(int u,int p){tin[u]=low[u]=++timer;for(int v:g[u]){if(v==p)continue;if(!tin[v]){dfs(v,u);low[u]=min(low[u],low[v]);if(low[v]>tin[u])ans.push_back({u,v});}else low[u]=min(low[u],tin[v]);}} vector<vector<int>> criticalConnections(int n,vector<vector<int>>&e){g.assign(n,{});for(auto&x:e)g[x[0]].push_back(x[1]),g[x[1]].push_back(x[0]);tin.assign(n,0);low.assign(n,0);dfs(0,-1);return ans;}
};
```

**Test cases**

n=4, edges=[[0,1],[1,2],[2,0],[1,3]] -> [[1,3]]

**Complexity** — O(V+E) time, O(V+E) space

---

**C Solution**

```c
#include <stdlib.h>
typedef struct{int to,next;}Edge;
void ccDfs(int v,int pe,int n,Edge*e,int*head,int*disc,int*low,int*time,int*out,int*cnt){disc[v]=low[v]=(*time)++;for(int id=head[v];id!=-1;id=e[id].next){if(id== (pe^1))continue;int to=e[id].to;if(disc[to]<0){ccDfs(to,id,n,e,head,disc,low,time,out,cnt);if(low[to]<low[v])low[v]=low[to];if(low[to]>disc[v]){out[2*(*cnt)]=v;out[2*(*cnt)+1]=to;(*cnt)++;}}else if(disc[to]<low[v])low[v]=disc[to];}}
// Return bridge endpoints in a flat array out[2*i], out[2*i+1]; caller allocates 2*m ints.
int* criticalConnectionsC(int n,int**connections,int m,int*returnSize){Edge*e=malloc(2*m*sizeof(Edge));int*head=malloc(n*sizeof(int));int*disc=malloc(n*sizeof(int));int*low=malloc(n*sizeof(int));for(int i=0;i<n;i++)head[i]=-1,disc[i]=-1;int ec=0;for(int i=0;i<m;i++){int a=connections[i][0],b=connections[i][1];e[ec]=(Edge){b,head[a]};head[a]=ec++;e[ec]=(Edge){a,head[b]};head[b]=ec++;}int tm=0,cnt=0;int*out=malloc(2*m*sizeof(int));ccDfs(0,-1,n,e,head,disc,low,&tm,out,&cnt);*returnSize=cnt;free(e);free(head);free(disc);free(low);return out;}
```

**Python 3 Solution**

```python
class Solution:
    def criticalConnections(self,n,connections):
        g=[[] for _ in range(n)]
        for a,b in connections:g[a].append(b);g[b].append(a)
        tin=[-1]*n;low=[0]*n;timer=0;ans=[]
        def dfs(v,p):
            nonlocal timer;tin[v]=low[v]=timer;timer+=1
            for to in g[v]:
                if to==p:continue
                if tin[to]>=0:low[v]=min(low[v],tin[to])
                else:
                    dfs(to,v);low[v]=min(low[v],low[to])
                    if low[to]>tin[v]:ans.append([v,to])
        dfs(0,-1);return ans
```

---

## 20. Minimum Cost to Connect Points

**Problem**

Connect every point in the plane so all points become connected with minimum total Manhattan distance.

**Reasoning**

Build the minimum spanning tree with Prim’s algorithm. Repeatedly add the cheapest edge from the connected set to an unvisited point.

**C++17 Solution**

```cpp
class Solution { public:
 int minCostConnectPoints(vector<vector<int>>&p){int n=p.size(),ans=0;vector<int>dist(n,INT_MAX);vector<char>used(n);dist[0]=0;for(int it=0;it<n;it++){int u=-1;for(int i=0;i<n;i++)if(!used[i]&&(u==-1||dist[i]<dist[u]))u=i;used[u]=1;ans+=dist[u];for(int v=0;v<n;v++)if(!used[v])dist[v]=min(dist[v],abs(p[u][0]-p[v][0])+abs(p[u][1]-p[v][1]));}return ans;}
};
```

**Test cases**

[[0,0],[2,2],[3,10],[5,2],[7,0]] -> 20

**Complexity** — O(n^2) time, O(n) space

---

**C Solution**

```c
#include <stdlib.h>
int minCostConnectPoints(int**p,int n,int*C){int*used=calloc(n,sizeof(int)),*d=malloc(n*sizeof(int));for(int i=0;i<n;i++)d[i]=1e9;d[0]=0;int ans=0;for(int it=0;it<n;it++){int u=-1;for(int i=0;i<n;i++)if(!used[i]&&(u<0||d[i]<d[u]))u=i;used[u]=1;ans+=d[u];for(int v=0;v<n;v++)if(!used[v]){int w=abs(p[u][0]-p[v][0])+abs(p[u][1]-p[v][1]);if(w<d[v])d[v]=w;}}free(used);free(d);return ans;}
```

**Python 3 Solution**

```python
class Solution:
    def minCostConnectPoints(self,points):
        n=len(points);used=[False]*n;dist=[10**9]*n;dist[0]=0;ans=0
        for _ in range(n):
            u=min((i for i in range(n) if not used[i]),key=lambda i:dist[i]);used[u]=True;ans+=dist[u]
            for v in range(n):
                if not used[v]:dist[v]=min(dist[v],abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]))
        return ans
```

---

