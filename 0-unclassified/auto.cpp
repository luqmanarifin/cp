#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e6 + 5;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

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

int dfs(trie_t *pTrie, char key[]) {
	int i;
	int length = strlen(key);
	trie_node_t *pCrawl;
	//pf("%s ", key);
	
	pCrawl = pTrie->root;
	FORS(i, length) {
		int id = key[i] - 'a';
		if(pCrawl->children[id] != NULL) {
			//pf("%d\n", i + 1);
			return i + 1;
		}
		pCrawl = pCrawl->children[id];
	}
	//pf("%d\n", length);
	return length;
}

void bebaskan(trie_node_t *now) {
	int i;
	//pf("%d\n", now);
	FORS(i, 26) {
		if(now->children[i] != NULL) {
			bebaskan(now->children[i]);
		}
	}
	free(now);
}

char s[N];

int main(void)
{
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int n;
		trie_t trie;
		initialize(&trie);
		
		sf("%d", &n);
		int ans = 0;
		while(n--) {
			sf("%s", s);
			ans += dfs(&trie, s);
			insert(&trie, s);
		}
		pf("Case #%d: %d\n", tt, ans);
		cerr << tt << " done!" << endl;
		cerr << "Case #" << tt << ": " << ans << '\n';
		
		trie_node_t *now;
		now = trie.root;
		//bebaskan(now);
	}
	
	return 0;
}
