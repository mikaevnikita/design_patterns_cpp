#include <iostream>
using namespace std;

/*
Паттерн Мост(Bridge)
структурный
разделяет абстракцию и реализацию так, чтобы они развивались независимо

*/

class Device {
public:
    virtual bool isEnabled() = 0;

    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual int getVolume() = 0;
    virtual void setVolume(int percent) = 0;

    virtual int getChannel() = 0;

    virtual void setChannel(int channel) = 0;

    virtual void printStatus() = 0;
};

class Radio : public Device {
private:
    bool on;
    int volume;
    int channel;
public:
    Radio(bool on=false, int volume=30, int channel=1)
        :Device(), on(on), volume(volume), channel(channel)
    {
    }
    bool isEnabled() override{
        return on;
    }

    void enable() override {
        on = true;
    }

    void disable() override{
        on = false;
    }

    int getVolume() override{
        return volume;
    }

    void setVolume(int volume) override{
        if (volume > 100) {
            volume = 100;
        }
        else if (volume < 0) {
            volume = 0;
        }
        this->volume = volume;
    }

    int getChannel() override{
        return channel;
    }

    void setChannel(int channel) override {
        this->channel = channel;
    }

    void printStatus() override {
        cout << "------------------------------------" << endl;
        cout << "| I'm radio." << endl;
        cout << "| I'm " << (on ? "enabled" : "disabled") << endl;
        cout << "| Current volume is " << volume <<"%" << endl;
        cout << "| Current channel is " <<  channel << endl;
        cout << "------------------------------------\n" << endl;
    }
};


class TV : public Device {
private:
    bool on;
    int volume;
    int channel;
public:
    TV(bool on=false, int volume=30, int channel=1)
        :Device(), on(on), volume(volume), channel(channel)
    {
    }
    bool isEnabled() override{
        return on;
    }

    void enable() override {
        on = true;
    }

    void disable() override{
        on = false;
    }

    int getVolume() override{
        return volume;
    }

    void setVolume(int volume) override{
        if (volume > 100) {
            volume = 100;
        }
        else if (volume < 0) {
            volume = 0;
        }
        this->volume = volume;
    }

    int getChannel() override{
        return channel;
    }

    void setChannel(int channel) override {
        this->channel = channel;
    }

    void printStatus() override {
        cout << "------------------------------------" << endl;
        cout << "| I'm TV." << endl;
        cout << "| I'm " << (on ? "enabled" : "disabled") << endl;
        cout << "| Current volume is " <<  volume << "%" << endl;
        cout << "| Current channel is " << channel << endl;
        cout << "------------------------------------\n" << endl;
    }
};

class Remote {
public:
    virtual void power() = 0;
    virtual void volumeDown() = 0;
    virtual void volumeUp() = 0;
    virtual void channelDown() = 0;
    virtual void channelUp() = 0;
};

class BasicRemote : public Remote {
protected:
    Device* device;
public:
    BasicRemote()
        :Remote()
    {}

    BasicRemote(Device* device)
        :Remote(), device(device){
    }

    void power() override{
        cout << "Remote: power toggle" << endl;
        if (device->isEnabled()) {
            device->disable();
        } else {
            device->enable();
        }
    }

    void volumeDown() override{
        cout << "Remote: volume down" << endl;
        device->setVolume(device->getVolume() - 10);
    }

    void volumeUp() override{
        cout << "Remote: volume up" << endl;
        device->setVolume(device->getVolume() + 10);
    }

    void channelDown() override {
        cout << "Remote: channel down" << endl;
        device->setChannel(device->getChannel() - 1);
    }

    void channelUp() override{
        cout << "Remote: channel up" << endl;
        device->setChannel(device->getChannel() + 1);
    }
};


class AdvancedRemote : public BasicRemote {
public:
    AdvancedRemote(Device* device)
        :BasicRemote()
    {
        this->device = device;
    }

    void mute() {
        cout << "Remote: mute" << endl;
        device->setVolume(0);
    }
};


int main(){
    Device* device = new TV;
    BasicRemote* basicRemote = new BasicRemote(device);
    basicRemote->power();
    device->printStatus();

    AdvancedRemote* advancedRemote = new AdvancedRemote(device);
    advancedRemote->power();
    advancedRemote->mute();
    device->printStatus();

    delete device;
    delete basicRemote;
    delete advancedRemote;

    return 0;
}
