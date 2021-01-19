#include <iostream>
#include<math.h>
// move function returns pointer to a array containing velocities of wheel
// angle is wrt +ve Y-axis (that is in forward direction of robot) and when robot is turned left that angle is 90
// omega is positive when robot rotate clockwise
void move(float speed, float angle, float omega,float v[])
{
    // conversion from degrees to radians
    angle = (angle * 3.1415926)/180;
    float vx = speed*sin(angle)*pow(2,-0.5);
    float vy = speed*cos(angle)*pow(2,-0.5);
    v[0]= vx+vy+omega;
    v[1]= vx-vy+omega;
    v[2]= omega-vx-vy;
    v[3]= vy-vx+omega;
}

int main()
{   float v[4]{};
    float speed,angle,omega;
    std::cout<<"enter speed : ";
    std::cin>>speed;
    std::cout<<"enter angle : ";
    std::cin>>angle;
    std::cout<<"enter omega : ";
    std::cin>>omega;
    
    move(speed,angle,omega,v);
    for(int i=0;i<4;i++)
    {
        std::cout<<"Velocity of "<<i<<" is "<<v[i]<<"\n";
    }
    return 0;
}