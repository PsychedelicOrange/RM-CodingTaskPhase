detectObstacle(memory())
{
    // if any sensor give <10cm ==> detect obstacle
    if(DistanceFromLeftSensor()<=10 || DistanceFromRightSensor()<=10 || DistanceFromFrontSensor()<=10 || DistanceFromRearSensor()<=10)
    {
        //object detected;
        //move in the direction with most high reading on sensor && dir must not be memory
        d[0] = DistanceFromLeftSensor();
        d[1] = DistanceFromRightSensor();
        d[2] = DistanceFromFrontSensor();
        d[3] = DistanceFromRearSensor();
        int largest = 0;
        for(int i=0, i<4;i++)
        {
         if(largest<d[i])
         {
             if(i != memory())
             {
                 largest = i;
             }
         }   

        }
        move(30,convert(largest));
    }

}
convert()//converts the i value to the correstponding angle