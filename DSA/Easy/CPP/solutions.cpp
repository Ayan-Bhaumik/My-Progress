// DSA 100 - Easy | C++ solutions
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int v=0,ListNode*n=nullptr):val(v),next(n){}};
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int v=0):val(v),left(nullptr),right(nullptr){}};
vector<int> q01_pairWithTargetSum(vector<int>&a,int target){unordered_map<int,int>m;for(int i=0;i<(int)a.size();++i){if(m.count(target-a[i]))return {m[target-a[i]],i};m[a[i]]=i;}return{};}
int q02_removeDuplicates(vector<int>&a){int k=0;for(int x:a)if(k==0||x!=a[k-1])a[k++]=x;return k;}
void q03_moveZeroes(vector<int>&a){int k=0;for(int x:a)if(x)a[k++]=x;while(k<(int)a.size())a[k++]=0;}
int q04_maxProfit(vector<int>&p){int mn=INT_MAX,ans=0;for(int x:p){mn=min(mn,x);ans=max(ans,x-mn);}return ans;}
int q05_missingNumber(vector<int>&a){int x=a.size();for(int i=0;i<(int)a.size();++i)x^=i^a[i];return x;}
int q06_majorityElement(vector<int>&a){int c=0,x=0;for(int v:a){if(!c)x=v;c+=(v==x?1:-1);}return x;}
bool q07_validAnagram(string s,string t){sort(s.begin(),s.end());sort(t.begin(),t.end());return s==t;}
int q08_firstUnique(string s){int c[256]={};for(unsigned char x:s)c[x]++;for(int i=0;i<(int)s.size();++i)if(c[(unsigned char)s[i]]==1)return i;return -1;}
string q09_reverseWords(string s){stringstream ss(s);vector<string>w;string x;while(ss>>x)w.push_back(x);reverse(w.begin(),w.end());string r;for(int i=0;i<(int)w.size();++i){if(i)r+=' ';r+=w[i];}return r;}
bool q10_palindrome(string s){int i=0,j=(int)s.size()-1;while(i<j){while(i<j&&!isalnum((unsigned char)s[i]))i++;while(i<j&&!isalnum((unsigned char)s[j]))j--;if(tolower((unsigned char)s[i])!=tolower((unsigned char)s[j]))return false;i++;j--;}return true;}
vector<int> q11_twoSumSorted(vector<int>&a,int target){int i=0,j=a.size()-1;while(i<j){int s=a[i]+a[j];if(s==target)return{i,j};if(s<target)i++;else j--;}return{};}
vector<int> q12_mergeSortedArrays(vector<int>a,vector<int>b){vector<int>r;merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(r));return r;}
int q13_binarySearch(vector<int>&a,int target){int l=0,r=a.size()-1;while(l<=r){int m=l+(r-l)/2;if(a[m]==target)return m;if(a[m]<target)l=m+1;else r=m-1;}return-1;}
int q14_searchInsert(vector<int>&a,int target){return lower_bound(a.begin(),a.end(),target)-a.begin();}
vector<int> q15_sortedSquares(vector<int>&a){vector<int>r(a.size());int l=0,j=a.size()-1,k=j;while(l<=j){int x=a[l]*a[l],y=a[j]*a[j];if(x>y)r[k--]=x,l++;else r[k--]=y,j--;}return r;}
ListNode* q16_reverseList(ListNode*h){ListNode*p=nullptr;while(h){auto*n=h->next;h->next=p;p=h;h=n;}return p;}
ListNode* q17_middleNode(ListNode*h){auto*s=h,*f=h;while(f&&f->next)s=s->next,f=f->next->next;return s;}
bool q18_hasCycle(ListNode*h){auto*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;if(s==f)return true;}return false;}
ListNode* q19_mergeTwoLists(ListNode*a,ListNode*b){ListNode d;auto*t=&d;while(a&&b){if(a->val<=b->val)t->next=a,a=a->next;else t->next=b,b=b->next;t=t->next;}t->next=a?a:b;return d.next;}
bool q20_validParentheses(string s){stack<char>st;for(char c:s){if(c=='('||c=='['||c=='{')st.push(c);else{if(st.empty())return false;char x=st.top();st.pop();if((c==')'&&x!='(')||(c==']'&&x!='[')||(c=='}'&&x!='{'))return false;}}return st.empty();}
class q21_Stack{queue<int>q;public:void push(int x){q.push(x);for(int i=0;i<(int)q.size()-1;i++){q.push(q.front());q.pop();}}int pop(){int x=q.front();q.pop();return x;}int top(){return q.front();}bool empty(){return q.empty();}};
class q22_Queue{stack<int>in,out;void shift(){if(out.empty())while(!in.empty())out.push(in.top()),in.pop();}public:void push(int x){in.push(x);}int pop(){shift();int x=out.top();out.pop();return x;}int peek(){shift();return out.top();}bool empty(){return in.empty()&&out.empty();}};
int q23_maxDepth(TreeNode*r){return r?1+max(q23_maxDepth(r->left),q23_maxDepth(r->right)):0;}
vector<int> q24_inorder(TreeNode*r){vector<int>ans;stack<TreeNode*>st;while(r||!st.empty()){while(r)st.push(r),r=r->left;r=st.top();st.pop();ans.push_back(r->val);r=r->right;}return ans;}
vector<vector<int>> q25_levelOrder(TreeNode*r){vector<vector<int>>a;if(!r)return a;queue<TreeNode*>q{{r}};while(!q.empty()){int n=q.size();a.push_back({});while(n--){auto*x=q.front();q.pop();a.back().push_back(x->val);if(x->left)q.push(x->left);if(x->right)q.push(x->right);}}return a;}
TreeNode*q26_searchBST(TreeNode*r,int t){while(r&&r->val!=t)r=t<r->val?r->left:r->right;return r;}
int q27_countSetBits(unsigned x){int c=0;while(x)x&=x-1,c++;return c;}
bool q28_powerOfTwo(unsigned n){return n&&!(n&(n-1));}
int q29_gcd(int a,int b){return std::gcd(a,b);}
long long q30_fibonacci(int n){long long a=0,b=1;for(int i=0;i<n;i++)tie(a,b)=make_tuple(b,a+b);return a;}
