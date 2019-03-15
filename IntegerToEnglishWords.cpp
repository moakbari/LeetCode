class Solution {
    
    vector<string> zeroToNine = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> tenToNineteen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> twentyToNighty = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> powerOfTens = {"Hundred", "Thousand", "Million", "Billion"};
    
    // anything between 0 to 99
    string twoDigitNumberToWords(int num){
        if (num <= 9 && num >= 0 ){
            return zeroToNine[num];
        }
        
        if (num >= 10 && num <= 19){
            return tenToNineteen[num - 10];
        }
        
        if (num % 10 == 0){
            return twentyToNighty[num / 10 - 2];
        }
        
        string words;
        return twentyToNighty[num / 10 - 2] + " " + zeroToNine[num % 10];
    }
    
    // anything between 100 to 999
    string threeDigitNumberToWords(int num){
              
        string words;
        
        if (num % 100 == 0){           
            return zeroToNine[num / 100] + " " + powerOfTens[0];
        }
        
        words = twoDigitNumberToWords(num % 100);
        
        if (num / 100 >= 1 ){
            words = zeroToNine[num / 100] + " " + powerOfTens[0] + " "+ words;
        }
        
        return words;
    } 
    
public:
    string numberToWords(int num) {
        string words;
        if (num == 0){
            return "Zero";
        }
        int powerOfTensIndex = 0;
        while(num > 0){
            string partialWords;
            
            if (num % 1000 != 0){
                partialWords = threeDigitNumberToWords(num % 1000);
                if (powerOfTensIndex > 0){
                    partialWords +=  (" " + powerOfTens[powerOfTensIndex]);
                    words = words.empty() ?  partialWords : partialWords + " " + words;
                }else{
                    words  = partialWords;
                }
            }
                        
            powerOfTensIndex++;
            num = num / 1000;
        }
        
        return words;
    }
};
