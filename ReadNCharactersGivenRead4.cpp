// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int numberOfCharsRead = 0;
        
        int count = n / 4;
        int rem = n % 4;
        
        while(count > 0){
            int charRead = read4(buf + numberOfCharsRead);
            numberOfCharsRead += charRead;
            
            if (charRead < 4){
                return numberOfCharsRead;
            }
            
            count--;
        }
        
        if(rem > 0){
            char internalBuf[4];
            int charRead = read4(internalBuf);
            
            int i = 0;
            while(i < min(charRead, rem) ){
                buf[numberOfCharsRead] = internalBuf[i];
                numberOfCharsRead++;
                i++;
            }
        }
        
        return numberOfCharsRead;
    }
};
