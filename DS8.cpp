#include<iostream>
using namespace std;

int countpaths(int x,int y,int endx,int endy)
{
    
if(x==endx && y==endy)
{
    return 1;
}

if (x>endx || y>endy)
{
   return 0;
}

return countpaths(x+1,y,endx,endy) + countpaths(x,y+1,endx,endy);
}

int main()
{
int gridsize,startx,starty,endx,endy;
cout<<"enter the grid size :";
cin>>gridsize;

cout<<"enter the starting position (x,y) :";
cin>>startx>>starty;

cout<<"enter the ending position (x,y) :";
cin>>endx>>endy;

if(startx<1 || starty<1 || endx<1 || endy<1 ||startx>gridsize || starty>gridsize || endx>gridsize || endy>gridsize)
{
cout<<"invalid position "<<endl;
return 1;
}

int uniquepaths=countpaths(startx,starty,endx,endy);
cout<<"unique path from ("<<startx<<","<<starty<< ") to ("<<endx<<"," <<endy<<"): "<<uniquepaths;
return 0;

} 
