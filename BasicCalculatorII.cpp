logo
Explore
Problems
New
Mock
Contest
Articles
Discuss
Store
0
Description
Solution
Submissions
Discuss (296)
Back
12ms C++
0
Xclamated's avatar
Xclamated
2
a few seconds ago

class Solution {
    bool isOpr(const char& c){
        return c == '+' || c == '-' || c == '/' || c == '*';
    }

public:
    int calculate(string s) {
        int prev = 0;
        int result = 0, start = 0, end = 0;
        while(end < s.size() && !isOpr(s[end])){
                end++;
        }
        
        result  = stoi(s.substr(start, end - start));
        char curOpr = end != s.size() ? s[end] : '/0';
        end++;
        start = end;
        
        while(end < s.size()){
            while(end < s.size() && !isOpr(s[end])){
                end++;
            }

            int curNum = stoi(s.substr(start, end - start));
            
            if (curOpr == '+' || curOpr == '-'){
                prev = result;
                result = curOpr == '+' ? result + curNum : result - curNum;
            }else{
                result = curNum == '*' ? (result - prev)*curNum + prev : (result - prev)/curNum + prev;
            }
            
            if (end == s.size()){
                break;
            }
            
            curOpr = s[end];
            end++;
            start = end;
        }
        
        return result;
    }
};
Comments: 0
Most VotesNewest to OldestOldest to Newest
Type comment here... (Markdown is supported)

Preview

Post
Copyright © 2019 LeetCode
Help Center
Jobs
Bug Bounty
Terms
Privacy Policy
United StatesUnited States
Type here...(Markdown is enabled)
​
Saved
12ms C++

Close

Update
```
class Solution {
    bool isOpr(const char& c){
        return c == '+' || c == '-' || c == '/' || c == '*';
    }
​
public:
    int calculate(string s) {
        int prev = 0;
        int result = 0, start = 0, end = 0;
        while(end < s.size() && !isOpr(s[end])){
                end++;
        }
        
class Solution {
    bool isOpr(const char& c){
        return c == '+' || c == '-' || c == '/' || c == '*';
    }

public:
    int calculate(string s) {
        int prev = 0;
        int result = 0, start = 0, end = 0;
        while(end < s.size() && !isOpr(s[end])){
                end++;
        }
        
        result  = stoi(s.substr(start, end - start));
        char curOpr = end != s.size() ? s[end] : '/0';
        end++;
        start = end;
        
        while(end < s.size()){
            while(end < s.size() && !isOpr(s[end])){
                end++;
            }

            int curNum = stoi(s.substr(start, end - start));
            
            if (curOpr == '+' || curOpr == '-'){
                prev = result;
                result = curOpr == '+' ? result + curNum : result - curNum;
            }else{
                result = curNum == '*' ? (result - prev)*curNum + prev : (result - prev)/curNum + prev;
            }
            
            if (end == s.size()){
                break;
            }
            
            curOpr = s[end];
            end++;
            start = end;
        }
        
        return result;
    }
};
Tag your topic (e.g. 'facebook', 'binary-search...')
