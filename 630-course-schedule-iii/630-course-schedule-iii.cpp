bool cmp(vector<int>a,vector<int>b)
{
    if(a[1]==b[1])
        return a[0]<b[0];
    
    return a[1]<b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp); //Sort on the basis of last day.
        
        int days=0,count=0,n=courses.size(); //variable that will use in keeping track.
        priority_queue<int>maxh; //Maxh heap.
        
        for(int i=0;i<n;i++) //Itration
        {
            if(days+courses[i][0]<=courses[i][1])
            {
                /*If last day of this course is less than total days taken to study +
                 duration of this course ,then just take this course by incrementing the
                 count.
                 And push it's duration in the maxh heap.*/
                count++;
                days+=courses[i][0];
                maxh.push(courses[i][0]);
            }
            else
            {
                /*If last day of this course is greater than total days taken to study +
                 duration of this course ,then check the maximum durataion course we have
                 taken before this course. if duration of that maximim is greater than 
                 the duration of this course then we will replace that maximimum 
                 duration course with this course.
                 
                 So we will pop it out from maxh heap and then push the duration of
                 this course.*/
                if(!maxh.empty() && maxh.top()>courses[i][0])
                {
                    days-=maxh.top();maxh.pop();
                    days+=courses[i][0];
                    maxh.push(courses[i][0]);
                }
            }
        }
        return count; //At the end return count.
    }
};