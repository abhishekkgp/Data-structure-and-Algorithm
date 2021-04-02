/*
Problem: Given a set of reviews provided by the customers for different hotels and a string containing Good Words, you need to sort the reviews in descending order according to their Goodness Value (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.
NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.

Input Format
First argument is a string A containing "Good Words" separated by "_" character
Second argument is a vector B of strings containing Hotel Reviews. Review strings are also separated by "_" character.

Output Format
Return a vector of integers which contain the original indexes of the reviews in the sorted order of reviews.

Example Input
Input 1:
 A = "cool_ice_wifi"
 B = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]
Example Output
Output 1: [2, 0, 1]

Example Explanation
Explanation 1:
sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]
*/


class TrieNode
{
    public:
    bool endWord;
    TrieNode* ch[26];
   
};

TrieNode *getNode()
{
    TrieNode* temp=new TrieNode();
    temp->endWord=false;
    for(int i=0;i<26;i++)
    {
        temp->ch[i]=NULL;
    }
    return temp;
}
void insert(TrieNode* root,string key)
{
    TrieNode* p=root;
    for(int i=0;i<key.length();i++)
    {
        if(p->ch[key[i]-'a']==NULL)
        p->ch[key[i]-'a']=getNode();
        p=p->ch[key[i]-'a'];
    }
    p->endWord=true;
}
int search(TrieNode* root,string key)
{
    TrieNode* p=root;
    
    for(int i=0;i<key.length();i++)
    {
        if(p->ch[key[i]-'a']==NULL)
        return false;
        p=p->ch[key[i]-'a'];
    }
    return (p!=NULL && p->endWord);
}

bool comp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    TrieNode* root=getNode();
    string word="";
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='_' && word!="")
        {
            insert(root,word);
            word="";
        }
        else
        word+=A[i];
    }
    insert(root,word);
    word="";
    vector<pair<int,int>> ans;
    for(int i=0;i<B.size();i++)
    {
        int count=0;
        for(int j=0;j<B[i].length();j++)
        {
        if(B[i][j]=='_' && word!="")
        {
        if(search(root,word))
        count++;
    
                word="";
            }
            else
            word+=B[i][j];
        }
        if(search(root,word))
        count++;
        
        word="";
        ans.push_back({i,count});
    }
    
    sort(ans.begin(),ans.end(),comp);
    
    vector<int> res;
    for(auto x : ans)
        res.push_back(x.first);
    
    return res;
}
