vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        int level=0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        
        while(!q.empty()) {
            
              vector<string> vec = q.front();
              q.pop();
              
              if(vec.size()>level) {
                  level++;
                  for(auto it: usedOnLevel) {
                        s.erase(it);
                  }
                  usedOnLevel.clear();
              }
              
              string word = vec.back();
              if(word == endWord) {
                  if(ans.size()==0){
                      ans.push_back(vec);
                  } 
                  else if(ans[0].size() == vec.size())
                     ans.push_back(vec);
              }
              
              for(int i=0;i<word.size();i++) {
                    char original = word[i];
                    for(char c='a';c<='z';c++) {
                          word[i] = c;
                          
                          if(s.count(word)>0) {
                               vec.push_back(word);
                               q.push(vec);
                               usedOnLevel.push_back(word);
                               vec.pop_back();
                          }
                    }
                    word[i] = original;
              }
        }
        return ans;
        
    }

/* Another approach for leetcode

class Solution {
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string b;
    int sz;
private :
    void dfs(string word, vector<string> &seq) {
        if(word == b) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mp[word];
        for(int i=0;i<sz;i++) {
            char original = word[i];
                for(char ch='a';ch<='z';ch++) {
                    word[i] = ch;
                    
                if(mp.find(word)!=mp.end() && mp[word]+1 == steps){
                    seq.push_back(word); 
                    dfs(word,seq);
                    seq.pop_back();
                }      
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        s.erase(beginWord);
        sz = beginWord.size();
        
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mp[word];
            if(word == endWord) break;
            for(int i=0;i<sz;i++) {
                char original = word[i];
                for(char ch='a';ch<='z';ch++) {
                    word[i] = ch;
                    
                    if(s.count(word)) {
                        q.push(word);
                        s.erase(word);
                        mp[word] = steps+1;
                    }
                }
                word[i] = original;
            }
        }
        if(mp.find(endWord)!=mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};
*/