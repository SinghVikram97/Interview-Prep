https://leetcode.com/problems/valid-tic-tac-toe-state/description/

XXX
X00
00""

Only  X WINS AND X==O BUT STILL NOT VALID
AS IF X WINS X SHOULD BE X==O+1

class Solution {
public:
    bool validBoard(vector<string> &board){
        
        int xRowCount[3]={0},xColCount[3]={0};
        int oRowCount[3]={0},oColCount[3]={0};
        int xDia1Count=0,xDia2Count=0,oDia1Count=0,oDia2Count=0;
        int x=0,o=0;
        bool xWins=false,oWins=false;
        int i,j;
        
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                
                if(board[i][j]=='X'){
                    
                    x++;
                    xRowCount[i]++;
                    xColCount[j]++;
                    
                    if(i==j){
                        xDia1Count++;
                    }
                    if(i+j==2){
                        xDia2Count++;
                    }
                    
                }
                else if(board[i][j]=='O'){
                    
                    o++;
                    oRowCount[i]++;
                    oColCount[j]++;
                    
                    if(i==j){
                        oDia1Count++;
                    }
                    if(i+j==2){
                       oDia2Count++;
                    }
                    
                }
                if(!xWins){
                    if(xRowCount[i]==3 || xColCount[j]==3 || xDia1Count==3 || xDia2Count==3){
                    xWins=true;
                  }
                }
                if(!oWins){
                    if(oRowCount[i]==3 || oColCount[j]==3 || oDia1Count==3 || oDia2Count==3){
                    oWins=true;
                    }
                }                
            }     
            
        }
        
        // X started before so x should have equal or one more turn
        if(!(x==o || x==o+1)){
            return false;
        }
        
        // Both can't win
        if(xWins && oWins){
            return false;
        }
        
        // If x wins it should have more 1 more count than o
        if(xWins && (!(x==o+1))){
            return false;
        }
        
        // If o wins it should have equal count of x
        if(oWins && !(x==o)){
            return false;
        }
        
        // Else
        return true;
        
    }
    bool validTicTacToe(vector<string>& board) {
        
       
            if(validBoard(board)){
                return true;
            }
            else{
                return false;
            }
         
    }
};
