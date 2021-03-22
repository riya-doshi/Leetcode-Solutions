class Solution {
public:
    
    vector<string> roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    vector<int> integer = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    
    int greatestdiv(int n){
        
        for(int i=roman.size()-1; i>=0; i--){
            if(integer[i] <= n){
                return i;
            }
        }
        return 0;
    }
    
    string intToRoman(int num) {
        string ans="";
        
        while(num){
            
            int d = greatestdiv(num);
            
            ans+=roman[d];
            num-=integer[d];
        }
        return ans;
    }
};
