/*
<-----PROBLEM----->
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, 
thus you may return any valid order and output will be 1 if the order of string returned by 
the function is correct else 0 denoting incorrect string returned.

EXAMPLE:-
Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1

Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
-------------------------------------------------------------------------------------
*/


//<-----SOLUTION------>
//using topological sort logic
void get_order(int node, vector<vector<int> > &adj, vector<int> &vis, string &ans)
{
    if(vis[node]==1) return;
    for(int i=0;i<adj[node].size();i++)
    {
        if(vis[adj[node][i]]==0) get_order(adj[node][i],adj,vis,ans);

    }
    ans+=node+'a'; 
    vis[node]=1;
    return;

}
 
// First calling funtion  
string AlienDictionary(string dict[], int N, int K) {

    vector<vector<int> > adj(K);
    for(int i=0;i<N-1;i++)
    {
        // Take the current two words and find the first mismatching character
        string s1=dict[i], s2=dict[i+1];
        int i1=0,i2=0;
        while(i1<s1.size() && i2<s2.size() && s1[i1]==s2[i2])
        {
            i1++;i2++;
        }
        // If we find a mismatching character, then add an edge
        // from character of word1 to that of word2
        if(i1<s1.size() && i2<s2.size())
        {

            adj[s1[i1]-'a'].push_back(s2[i2]-'a');
        }
    }
    string ans;
    vector<int> vis(K,0);
    // as all k value(character in Alian dictionary) are from 
    // starting alphabate in actual one
    for(int i=0;i<K;i++) 
    {
        if(vis[i]==0) get_order(i,adj,vis,ans);
    }
    // as in string "ans"  highest one coming first so we need to reverse it
    reverse(ans.begin(),ans.end()); 
    return ans;
}

int main()
{
    string words[] = {"caa", "aaa", "aab"};
    cout<<AlienDictionary(words, 3,3);
    return 0;
} 

/*
OUTPUT:
c a b

*/
