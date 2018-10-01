#include<ctime>
//using namespace std;
class __random_number
{
    int low,high;
public:
    __random_number()
    {
        low=1;
        high=100;
    }
    void timerseed();
    int draw_random_numbers();
    int gethigh();
    int getlow();
 /*   void display()
    {
        cout<<high<<endl<<low<<endl
            <<draw___random_numbernumbers()<<endl;
    }*/
};
void __random_number::timerseed()
{
    time_t seedTime;
    struct tm seedDate;
    seedTime=time(0);
    seedDate=*localtime(&seedTime);
    int finalSeed=seedTime+seedDate.tm_mday+(seedDate.tm_mon+1)+(seedDate.tm_year+1900);
  srand((unsigned int)finalSeed);

}
int __random_number::draw_random_numbers()
{
    timerseed();            // this function declaration in this function  will help generating unique array of random number each time.
    int interval=gethigh()-getlow()+1;
    int ran_offset=rand()%interval;
    int ran_number=getlow()+ran_offset;
    return ran_number;
}
int __random_number::gethigh()
{
    return high;
}
int __random_number::getlow()
{
    return low;
}
void wait(int wait_time)
{
    long *start_time=new long;
    *start_time=time(0);
    while((*start_time+wait_time)>time(0))
    {}
    delete start_time;
}
/*main()
{
    __random_number r;
    r.display();
    r.timerseed();
}*/
