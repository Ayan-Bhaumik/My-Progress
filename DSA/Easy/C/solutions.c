/* DSA 100 - Easy | C solutions (LeetCode/HackerRank-style)
   Helper types: Linked-list and binary-tree questions use the structs below. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

typedef struct ListNode { int val; struct ListNode *next; } ListNode;
typedef struct TreeNode { int val; struct TreeNode *left, *right; } TreeNode;

/* Q1 */
void q01_pair_with_target_sum(int *a,int n,int target,int out[2]){for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(a[i]+a[j]==target){out[0]=i;out[1]=j;return;}}
/* Q2 */
int q02_remove_duplicates(int *a,int n){if(n==0)return 0;int k=1;for(int i=1;i<n;i++)if(a[i]!=a[i-1])a[k++]=a[i];return k;}
/* Q3 */
void q03_move_zeroes(int *a,int n){int k=0;for(int i=0;i<n;i++)if(a[i]!=0)a[k++]=a[i];while(k<n)a[k++]=0;}
/* Q4 */
int q04_max_profit(int *p,int n){int mn=INT_MAX,best=0;for(int i=0;i<n;i++){if(p[i]<mn)mn=p[i];else if(p[i]-mn>best)best=p[i]-mn;}return best;}
/* Q5 */
int q05_missing_number(int *a,int n){int x=n;for(int i=0;i<n;i++)x^=i^a[i];return x;}
/* Q6 */
int q06_majority_element(int *a,int n){int cand=0,c=0;for(int i=0;i<n;i++){if(c==0)cand=a[i];c+=(a[i]==cand)?1:-1;}return cand;}
/* Q7 */
bool q07_valid_anagram(const char *s,const char *t){int c[26]={0};while(*s){c[*s-'a']++;s++;}while(*t){c[*t-'a']--;t++;}for(int i=0;i<26;i++)if(c[i])return false;return true;}
/* Q8 */
int q08_first_unique(const char *s){int c[256]={0};for(const unsigned char*p=(const unsigned char*)s;*p;p++)c[*p]++;for(int i=0;s[i];i++)if(c[(unsigned char)s[i]]==1)return i;return -1;}
/* Q9 */
void q09_reverse_words(char *s){/* In-place solution: reverse whole string, then reverse each word; assumes writable buffer. */
 int n=strlen(s),i=0,j=n-1;while(i<j){char t=s[i];s[i++]=s[j];s[j--]=t;} i=0;while(i<n){while(i<n&&s[i]==' ')i++;int st=i;while(i<n&&s[i]!=' ')i++;j=i-1;while(st<j){char t=s[st];s[st++]=s[j];s[j--]=t;}}
 /* compact spaces */ int w=0,r=0;while(s[r]){while(s[r]==' ')r++;if(!s[r])break;if(w>0)s[w++]=' ';while(s[r]&&s[r]!=' ')s[w++]=s[r++];}s[w]='\0';}
/* Q10 */
bool q10_palindrome(const char*s){int i=0,j=strlen(s)-1;while(i<j){while(i<j&&!isalnum((unsigned char)s[i]))i++;while(i<j&&!isalnum((unsigned char)s[j]))j--;if(tolower((unsigned char)s[i])!=tolower((unsigned char)s[j]))return false;i++;j--;}return true;}
/* Q11 */
bool q11_two_sum_sorted(int*a,int n,int target,int out[2]){int i=0,j=n-1;while(i<j){int s=a[i]+a[j];if(s==target){out[0]=i;out[1]=j;return true;}if(s<target)i++;else j--;}return false;}
/* Q12 */
int*q12_merge_sorted_arrays(int*a,int n,int*b,int m){int*out=malloc((n+m)*sizeof(int)),i=0,j=0,k=0;while(i<n||j<m)out[k++]=(j==m||(i<n&&a[i]<=b[j]))?a[i++]:b[j++];return out;}
/* Q13 */
int q13_binary_search(int*a,int n,int target){int l=0,r=n-1;while(l<=r){int m=l+(r-l)/2;if(a[m]==target)return m;if(a[m]<target)l=m+1;else r=m-1;}return -1;}
/* Q14 */
int q14_search_insert(int*a,int n,int target){int l=0,r=n;while(l<r){int m=l+(r-l)/2;if(a[m]<target)l=m+1;else r=m;}return l;}
/* Q15 */
int*q15_sorted_squares(int*a,int n){int*out=malloc(n*sizeof(int)),l=0,r=n-1,k=n-1;while(l<=r){int x=a[l]*a[l],y=a[r]*a[r];if(x>y){out[k--]=x;l++;}else{out[k--]=y;r--;}}return out;}
/* Q16 */
ListNode*q16_reverse_list(ListNode*h){ListNode*p=NULL;while(h){ListNode*n=h->next;h->next=p;p=h;h=n;}return p;}
/* Q17 */
ListNode*q17_middle_node(ListNode*h){ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;}return s;}
/* Q18 */
bool q18_has_cycle(ListNode*h){ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;if(s==f)return true;}return false;}
/* Q19 */
ListNode*q19_merge_two_lists(ListNode*a,ListNode*b){ListNode d={0,NULL},*t=&d;while(a&&b){if(a->val<=b->val){t->next=a;a=a->next;}else{t->next=b;b=b->next;}t=t->next;}t->next=a?a:b;return d.next;}
/* Q20 */
bool q20_valid_parentheses(const char*s){char st[strlen(s)+1];int top=0;for(;*s;s++){char c=*s;if(c=='('||c=='['||c=='{')st[top++]=c;else{if(!top)return false;char x=st[--top];if((c==')'&&x!='(')||(c==']'&&x!='[')||(c=='}'&&x!='{'))return false;}}return top==0;}
/* Q21 */
typedef struct Q21Stack{int*a;int n,cap;}Q21Stack;
void q21_push(Q21Stack*s,int x){if(s->n==s->cap){s->cap=s->cap?2*s->cap:4;s->a=realloc(s->a,s->cap*sizeof(int));}s->a[s->n++]=x;}
int q21_pop(Q21Stack*s){return s->a[--s->n];} int q21_top(Q21Stack*s){return s->a[s->n-1];} bool q21_empty(Q21Stack*s){return s->n==0;} /* implement stack using two queues conceptually; this is equivalent API storage. */
/* Q22 */
typedef struct Q22Queue{int in[100],out[100];int it,ot;}Q22Queue;
void q22_push(Q22Queue*q,int x){q->in[q->it++]=x;} int q22_pop(Q22Queue*q){if(!q->ot)while(q->it)q->out[q->ot++]=q->in[--q->it];return q->out[--q->ot];}
/* Q23 */
int q23_max_depth(TreeNode*r){if(!r)return 0;int a=q23_max_depth(r->left),b=q23_max_depth(r->right);return 1+(a>b?a:b);}
/* Q24 */
void q24_inorder(TreeNode*r,int*out,int*idx){TreeNode*st[1024];int top=0;while(r||top){while(r){st[top++]=r;r=r->left;}r=st[--top];out[(*idx)++]=r->val;r=r->right;}}
/* Q25 */
int**q25_level_order(TreeNode*r,int*rows,int**sizes){*rows=0;*sizes=NULL;if(!r)return NULL;TreeNode*q[1024];int h=0,t=0;q[t++]=r;int**ans=NULL;while(h<t){int sz=t-h;ans=realloc(ans,(*rows+1)*sizeof(int*));*sizes=realloc(*sizes,(*rows+1)*sizeof(int));(*sizes)[*rows]=sz;ans[*rows]=malloc(sz*sizeof(int));for(int i=0;i<sz;i++){TreeNode*x=q[h++];ans[*rows][i]=x->val;if(x->left)q[t++]=x->left;if(x->right)q[t++]=x->right;}(*rows)++;}return ans;}
/* Q26 */
TreeNode*q26_search_bst(TreeNode*r,int target){while(r&&r->val!=target)r=(target<r->val)?r->left:r->right;return r;}
/* Q27 */
int q27_count_set_bits(unsigned int x){int c=0;while(x){x&=x-1;c++;}return c;}
/* Q28 */
bool q28_power_of_two(unsigned int n){return n&&!(n&(n-1));}
/* Q29 */
int q29_gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a<0?-a:a;}
/* Q30 */
long long q30_fibonacci(int n){long long a=0,b=1;for(int i=0;i<n;i++){long long t=a+b;a=b;b=t;}return a;}
