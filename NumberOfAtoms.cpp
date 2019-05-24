class Solution {
    void updateCurElement(unordered_map<string, int>& elementCount, string& curElement, int& curCount){
        if (!curElement.empty()){
            elementCount[curElement] += curCount == 0 ? 1 : curCount;
            curElement = "";
            curCount = 0;
        }
    }
    unordered_map<string, int> countOfAtoms(string formula, int& i){
        unordered_map<string, int> elementCount;
        int curCount = 0;
        string curElement;
        while(i < formula.size()){
            if (formula[i] == '('){
                updateCurElement(elementCount, curElement, curCount);
                i++;
                unordered_map<string, int> tempCount = countOfAtoms(formula, i);
                i++;
                int count = 0;
                while (i < formula.size() && isdigit(formula[i])){
                    count = 10*count + (formula[i] - '0');
                    i++;
                }
                
                count = count == 0 ? 1 : count;
                for_each(tempCount.begin(), tempCount.end(), [&elementCount, &count](pair<const string,int>& item){
                     elementCount[item.first] += (item.second)*count;
                });
            }else if(isdigit(formula[i])){
                curCount = 0;
                while(i < formula.size() && isdigit(formula[i])){
                    curCount = 10*curCount + (formula[i] - '0');
                    i++;
                }
            }else if(formula[i] == ')'){
                break;
            }else if (formula[i] >= 'A' && formula[i] <= 'Z'){
                updateCurElement(elementCount, curElement, curCount);
                int start = i;
                i++;
                while(i < formula.size() && formula[i] >= 'a' && formula[i] <= 'z'){
                    i++;
                }
                
                curElement = formula.substr(start, i - start);
            }
        }
        
        updateCurElement(elementCount, curElement, curCount);
        return elementCount;
    }
    
public:
    string countOfAtoms(string formula) {
        int index  = 0;
        unordered_map<string, int> elementCount = countOfAtoms(formula, index);
        vector<string> elements;
        for_each(elementCount.begin(), elementCount.end(), [&elements](pair<const string,int>& item){
            elements.push_back(item.first);
        });
        
        sort(elements.begin(), elements.end());
        
        string result;
        for_each(elements.begin(), elements.end(), [&result,&elementCount](string& item){
            result += item;
            if (elementCount[item] > 1){
                result += to_string(elementCount[item]);
            }
        });
        
        return result;
    }
};
