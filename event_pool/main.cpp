#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
using namespace std;

/*
Пример асинхронной реализации паттерна Команда
Так же можно рассматривать как Event Pool
Подходит для реализации например веб сервера
*/

class Command{
public:
    virtual void execute() = 0;
};

class Command1: public Command{
private:
    mutex mtx;
public:
    void execute(){
        lock_guard<mutex> lock(mtx);
        cout << "Command 1" << endl;
    }
};

class Command2: public Command{
private:
    mutex mtx;
public:
    void execute(){
        lock_guard<mutex> lock(mtx);
        cout << "Command 2" << endl;
    }
};

class CommandPool{
private:
    queue<Command*> command_queue;
    mutex mtx;
public:
    void push(Command* command){
        lock_guard<mutex> lock(mtx);
        command_queue.push(command);
    }
    Command* pop(){
        lock_guard<mutex> lock(mtx);
        if(command_queue.empty())
            return nullptr;

        Command* command = command_queue.front();
        command_queue.pop();
        return command;
    }
};

void threaded_func(CommandPool* cmd_pool){
    while(true){
        Command* curr_command = cmd_pool->pop();
        if(!curr_command)
            continue;
        curr_command->execute();
        cmd_pool->push(curr_command);
    }
}

int main()
{
    CommandPool* pool = new CommandPool;
    pool->push(new Command1);
    pool->push(new Command2);
    thread t1(threaded_func, pool);
    thread t2(threaded_func, pool);
    t1.join();
    t2.join();
    delete pool;
    return 0;
}
