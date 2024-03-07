#include <iostream>
#include <string>
using namespace std;

// Decorator Design
//COR
//Abstract Factory
// Template method
// Flyweight
// hyderate , dehydrate
// Singleton with smrt ptr
/* Req -> Ek msg jo bhejana hai usko encode karna, encrpyt , sign bhejna hai.*/

class IMsgSend
{
public:
    virtual void Send(string) = 0;
};

class NullSend : public IMsgSend
{
public:
    void Send(string) override
    {
        // do nothing.
    }
};

class Helper : public IMsgSend // self Referential
{
    IMsgSend *msg_send;

protected:
    Helper(IMsgSend *msg_send) : msg_send(msg_send) // Linked Lsit Construction.
    {
    }

public:
    void Send(string msg) override
    {
        msg_send->Send(msg);
    }
};

class Encryptor : public Helper
{
public:
    Encryptor(IMsgSend *msg_send) : Helper(msg_send)
    {
    }
    void Send(string msg) override
    {
        msg = "ency - " + msg + " - ency";
        cout << "Encrypted : " << msg << "\n";
        Helper::Send(msg);
    }
};

class Encoder : public Helper
{
public:
    Encoder(IMsgSend *msg_send) : Helper(msg_send)
    {
    }
    void Send(string msg) override
    {
        msg = "ecod - " + msg + " - ecod";
        cout << "Encode : " << msg << "\n";
        Helper::Send(msg);
    }
};

class Sign : public Helper
{
public:
    Sign(IMsgSend *msg_send) : Helper(msg_send)
    {
    }
    void Send(string msg) override
    {
        msg = "sin - " + msg + " - sin";
        cout << "Signed : " << msg << "\n";
        Helper::Send(msg);
    }
};

IMsgSend *Message_Factory()
{
    return new Encryptor(new Encoder(new Sign(new NullSend())));
}
int main()
{
    IMsgSend *msg = Message_Factory();
    msg->Send("Mera Bharath Mahan!!");
    return 0;
}