// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char internalBuf[4];
    int internalIndex = 0;
    int numValidChar = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int numberOfCharRead = 0;
        
        // copy any left over form previous read!
        if (internalIndex != 0){
            int i = 0;
            while(n > 0 && internalIndex < numValidChar){
                buf[i] = internalBuf[internalIndex];
                i++;
                n--;
                internalIndex++;
                numberOfCharRead++;
            }    
            internalIndex = internalIndex == numValidChar ? 0 : internalIndex;
        }
        
        if (n > 0){
            int count = n / 4;
            int rem = n % 4;
            
            while(count > 0){
                int charRead = read4(buf+numberOfCharRead);
                numberOfCharRead+=charRead;
                if (charRead < 4){ // reached end of file
                    return numberOfCharRead;
                }
                
                count--;
            }
            
            // take care of n % 4 chars!
            if (rem != 0){
                numValidChar = read4(internalBuf);
                int i = 0;
                while(i < min(numValidChar, rem)){
                    buf[numberOfCharRead] = internalBuf[i];
                    numberOfCharRead++;
                    i++;
                }
                
                buf+=i;
                internalIndex = i == numValidChar ? 0 : i;
            }
            
        }
        
        return numberOfCharRead;
    }
};
