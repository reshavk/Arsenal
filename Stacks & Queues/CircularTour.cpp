/*
Suppose there is a circle. There are n petrol pumps on that circle. You will be given two sets of data.

1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Your task is to complete the function tour which returns an integer denoting the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity).
*/

//Naive solution : O(n^2)
int tour(petrolPump p[],int n)
{
   //Your code here
   
   for(int i=0; i<n; i++){
       int x = (p[i].petrol - p[i].distance);
       int j = (i+1)%n;
       while(x >= 0 && j != i) {
           x += (p[j].petrol - p[j].distance);
           j = (j+1)%n;
       }
       if(j == i && x >= 0) {
           
           return i;
       }
   }
   
   return -1;
}

//Efficient solution : O(n)
int tour(petrolPump p[],int n) {
    int start = 0, end = 1;
    int x = (p[0].petrol - p[0].distance);
    
    while(start != end || x < 0) {
        while(x < 0 && start != end) {
            x -= (p[start].petrol - p[start].distance);
            start = (start+1)%n;
            
            if(start == 0)
                return -1;
        }
        
        x += (p[end].petrol - p[end].distance);
        end = (end + 1)%n;
    }
    
    return start;
}
