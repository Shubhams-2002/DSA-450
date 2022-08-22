#include<bits/stdc++.h>
//return length of the ladder formed and not no. of changes
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict;
        for(auto it : wordList) dict.insert(it);
        if( !dict.count(endWord) ) return 0;
        
        unordered_set<string> vis;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int changes=1; //each level denotes one change
        
        while( !q.empty() ) {
            int k=q.size();
            while(k) {
                k--;
                
                string word = q.front();
                q.pop();
                if(word==endWord) return changes;
                
                for(int i=0; i<word.length(); i++) {
                    char ch = word[i];
                    for(char j='a'; j<='z'; j++) {
                        word[i] = j;
                        
                        if( dict.count(word) && !vis.count(word) ) {
                            q.push(word);
                            vis.insert(word);
                        }
                    }
                    word[i] = ch; //backtrack
                }
            }
            changes++; //one level completed
        }
        
        return 0;
    }
};