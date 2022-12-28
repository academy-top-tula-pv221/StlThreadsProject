#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <future>

using namespace std;

mutex m;

int n{};

void funcForThread()
{
    
    for(int i = 0; i < 100; i++)
    {
        //m.lock();
        lock_guard<mutex> l(m);
        n++;
        cout << this_thread::get_id() << " sub thread " << i << "\n";
        //m.unlock();
        //this_thread::sleep_for(50ms);
    }
}

int funcForAsync()
{
    int result{};
    for (int i = 0; i < 1000; i++)
    {
        result++;
        this_thread::sleep_for(5ms);
    }
    return result;
}

int main()
{
    //int a = 5;
    //thread th1(funcForThread);
    //thread th2(funcForThread, a, 30);
    auto result = async(funcForAsync);
    cout << result.get() << "\n";
    result.wait();
    cout << "main thread\n";
    //


    //for (int i = 0; i < 10000; i++)
    //{
    //    n++;
    //    //cout << "main thread " << i << "\n";
    //    //this_thread::sleep_for(20ms);
    //}
    //this_thread::sleep_for(20ms);
    //cout << "----" << n << "\n";
    //th1.join();
    //th2.join();
    //cout << "--------------------" << "\n";
    //cout << "" << n << "\n";
}
