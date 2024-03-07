#ifndef IMOMENTO_H
#define IMOMENTO_H

class IMomento
{
public:
    IMomento() = default;
    IMomento(const IMomento &) = delete;
    IMomento(IMomento &&) = delete;
    IMomento &operator=(const IMomento &) = delete;
    IMomento &operator=(const IMomento &&) = delete;
    ~IMomento() = default;

    virtual void Hyderate() = 0;
    virtual void Dehyderate() = 0;
};

#endif // IMOMENTO_H
