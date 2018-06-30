https://practice.geeksforgeeks.org/problems/circular-tour/1

https://leetcode.com/problems/gas-station/discuss/42568/Share-some-of-my-ideas.(IMP)

https://drive.google.com/open?id=1Wp8dzuvaPTGjoq0k33RUambk9pQrQANj
https://drive.google.com/open?id=1IhAzkfR3wkLIASm3BiggD8N5CLcq9jvm

struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n)
{
  
    queue<petrolPump> q;
    int totalDistance=0,totalPetrol=0;
    for(int i=0;i<n;i++){
        q.push(p[i]);
        totalDistance+=p[i].distance;
        totalPetrol+=p[i].petrol;
    }
    
    /// Not possible 
    if(totalPetrol<totalDistance){
        return -1;
    }
    
    int start=0,tank=0,passed=0;
    while(passed<n){
        
        petrolPump element=q.front();
        
        tank=tank+element.petrol;
        
        q.pop();
        
        if(tank>=element.distance){
            passed=passed+1;
            tank=tank-element.distance;
        }
        else{
            start=start+passed+1;
            passed=0;
            tank=0;
        }
        q.push(element);
        
    }
    return start;
}
