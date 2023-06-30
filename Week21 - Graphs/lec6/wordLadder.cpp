class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        // jo bhi word queue mei insert krunga, toh usko set mei se remove krunga
        st.erase(beginWord);
        while (!q.empty())
        {
            pair<string, int> fNode = q.front();
            q.pop();
            string currString = fNode.first;
            int currCount = fNode.second;
            // check kahin destination tak toh nhi pahuch gae
            if (currString == endWord)
            {
                return currCount;
            }
            for (int index = 0; index < currString.length(); index++)
            {
                char originalCharacter = currString[index];
                // replace with characters from a to z
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[index] = ch;
                    // check in word list
                    if (st.find(currString) != st.end())
                    {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }
                // bring back currString to original state
                currString[index] = originalCharacter;
            }
        }
        return 0;
    }
};