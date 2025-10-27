class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long totalBeams = 0LL;                       
        // store total beams, use 64-bit for safety
        long long prevDevices = 0LL;                      
        // number of devices in the last non-empty row

        for (const string &row : bank) {                  
            // iterate over every row in the bank layout
            long long countOnes = 0LL;                   
            
             // counter for '1's in current row

            for (char c : row) {                          
                // iterate over each character in the row
                if (c == '1') countOnes++;                
                // increment when we find a security device
            }

            if (countOnes > 0) {                         
                 // only consider rows that contain at least one device
                totalBeams += prevDevices * countOnes;  
                 // each device in this row connects to every device in previous non-empty row
                prevDevices = countOnes;                 
                // update previous non-empty row device count to current row
            }
            
            // if countOnes == 0, we skip (do not reset prevDevices) because prevDevices should refer to the last non-empty row
        }

        return static_cast<int>(totalBeams);             
         // return result as int (fits within problem constraints)
    }
};

