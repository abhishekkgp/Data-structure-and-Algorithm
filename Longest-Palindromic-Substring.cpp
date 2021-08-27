Problem description:
    Given a string s, return the longest palindromic substring in s.

  
Example 1:
    Input: s = "babad"
    Output: "bab"

    Note: "aba" is also a valid answer.
  
  
Example 2:
    Input: s = "cbbd"
    Output: "bb"
 
        
Time complexity: O(n^2)  [A nested traversal of the string is needed. So time complexity is O(n^2)]
Auxiliary Space: O(1)    [No extra space is needed]
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

string longestPalindrome(string s) 
{
    int n=s.size();
    int low,high,maxlen=1,start=0;
    for(int i=0;i<n;i++)
    {
        low=i;
        high=i+1;
        while(low>=0 && high<n && s[low]==s[high])
        {
            if(high-low+1>maxlen)
            {
                maxlen=high-low+1;
                start=low;
            }
            low--;
            high++;

        }
        low=i-1;
        high=i+1;
        while(low>=0 && high<n && s[low]==s[high])
        {
            if(high-low+1>maxlen)
            {
                maxlen=high-low+1;
                start=low;
            }
            low--;
            high++;

        }
    }
    return s.substr(start,maxlen);
}
