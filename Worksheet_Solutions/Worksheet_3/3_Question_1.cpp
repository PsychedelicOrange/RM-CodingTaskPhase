#include <iostream>
#include <chrono> // for std::chrono functions
 
class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now())
	{
	}
	
	void reset()
	{
		m_beg = clock_t::now();
	}
	
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}



};
void fib(int i,int j)
{
    std::cout<<i<<" "<<j<<"\n";
    i=i+j;
    j=i+j;
    if(i<63245986)
    {
    fib(i,j);
    }
    
}
int main()
{   
    Timer t;
    fib(0,1);
    std::cout<<t.elapsed();
    return 0;
}