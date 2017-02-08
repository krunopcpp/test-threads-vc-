/*

Hi, 

I send you my experiment with 20 threads calculating the same function for N= 5000
 
The total number of multiplications if N=10000 is smaller than 10000^2 = 4 * 5000^2, 
but I run 20 threads for N=5000, and performance is much better than one thread for N=10000 
-also all four cores of i3 proc are employed now I think it is run in parallel,
 and ready to implement multiplication of big numbers 


Regarding that, is it posslible to run the thread again after finish the task? 
So when finished last task, to do a second task only with different input parameters 

although code:	
	thread  t(f);
looks like for each thread there is a separate variable,
so if we then write
	thread  t(g);
means that variable t is defined twice !

which makes me to conclude that each thread needs a separate variable t


I want to do multiplication of big numbers in parallel, so 
	abcdefghijklmnoprst * xyzw
can be devided in parallel
	thread1-	abcdefghijklmnoprst * x
	thread2-	abcdefghijklmnoprst * y
	thread3-	abcdefghijklmnoprst * z
	thread4-	abcdefghijklmnoprst * w
and then move right and sum up in basic thread, like hand written multiplication



What do you think? 


Kruno

*/



/////////////////////////////////////////////////////////////////////////////////////////////////////




// CALC 2^10,000


#include <iostream>
#include <vector>
#include <thread>
using namespace std;

const int N = 5000;


void fcount(){

	/*
	we multiply numbers to the right, and not to the left as usualy hand written multiplication
	eg. usualy is 512*2 = 1024  But this time we do:  2* 215 = 4201
	At the end we must reverse the vector
	*/
	vector<int> v;  
	v.push_back(1);
	int overflow=0; // eg. 2*6=12, digit is 2, and overflow is 1

	for (int i = 0; i < N; i++)	{
		for ( vector<int>::iterator it=v.begin(); it!=v.end(); ++it){
			int digit= *it;
			int dig2 = 2*digit + overflow;

			if (dig2 >= 10)	{
				*it = dig2 -10;
				overflow=1; 
			}
			else{
				*it = dig2 ;
				overflow =0;
			}
		}
		if (1 == overflow){
			v.push_back(1);// += '1'; 
			overflow=0;
		}
	}
	/* print out results
	now we reverse the vector as we do for array  -	we do not bother with reverse_iterator
	*/
	int v_size = v.size();
	cout<<"Number of digits:" << v_size << '\n';

	for (int i =0;  i<  v_size ; i++){
	//	cout<< v[v_size -i  -1]; // do not forget -1 coz its array now
	}

};






int main() {


	thread  
		t1(fcount)
	,	t2(fcount)
	,	t3(fcount)
	,	t4(fcount)
	,	t5(fcount)
	,	t6(fcount)
	,	t7(fcount)
	,	t8(fcount)
	,	t9(fcount)
	,	t10(fcount)
,		t11(fcount)
	,	t12(fcount)
	,	t13(fcount)
	,	t14(fcount)
	,	t15(fcount)
	,	t16(fcount)
	,	t17(fcount)
	,	t18(fcount)
	,	t19(fcount)
	,	t20(fcount)
		;
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();


	// only for window to stay, to see the results
	//int dummy; 	std::cin>>dummy;

}


