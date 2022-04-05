
int min(int a,int b){
    if(a<b)
    return a;
    return b;
}

int maxArea(int* height, int heightSize){
    int max_area = 0;
    int i = 0;
    int j = heightSize - 1;
    while(i<j){
        int a = min(height[i],height[j])*(j-i);
        
        if(a>max_area)
        max_area=a;
        
        if(height[i]>height[j])
        j--;
        else
        i++;
    }
    return max_area;
}