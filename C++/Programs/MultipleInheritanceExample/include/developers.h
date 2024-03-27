#ifndef DEVELOPERS_H
#define DEVELOPERS_H
class DataScienceDev
{
    public:
        DataScienceDev();
};

class FutureCppDev
{
    public:
        FutureCppDev();
};

class Student: public DataScienceDev, public FutureCppDev
{
    public:
        Student();
};
#endif