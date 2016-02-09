#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'A')

typedef struct trie_node trie_node_t;
struct trie_node
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};

typedef struct trie trie_t;
struct trie
{
    trie_node_t *root;
    int count;
};
 
trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;
 
    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));
 
    if( pNode )
    {
        int i;
 
        pNode->value = 0;
 
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
 
    return pNode;
}

void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}

void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
 
    pCrawl->value = pTrie->count;
}

pair<int,int> count(trie_node_t *now) {
	int i;
	int ans = 0, nodeAda = now->value;
	if(nodeAda) nodeAda = 1;
	int available = nodeAda;
	for(i = 0; i < 26; i++) {
		trie_node_t *anak;
		anak = now->children[i];
		if(anak) {
			pair<int,int> temp = count(anak);
			ans += temp.first;
			available += temp.second;
			if(nodeAda && temp.second) {
				ans++;
				nodeAda = 0;
				available -= 2;
			}
		}
	}
	return mp(ans, available);
}

int main()
{
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		trie_t trie;
		initialize(&trie);
		int n, i;
		sf("%d", &n);
		FORS(i, n) {
			char s[25];
			sf("%s", s);
			insert(&trie, s);
		}
		int ans = 0;
		trie_node_t *akar;
		akar = trie.root;
		FORS(i, 26) {
			pair<int,int> cur = mp(0, 0);
			if(akar->children[i]) {
				cur = count(akar->children[i]);
			}
			ans += cur.first;
			//pf("%d %d\n", cur.first, cur.second);
		}
		pf("Case #%d: %d\n", tt, ans);
	}
 
	return 0;
}