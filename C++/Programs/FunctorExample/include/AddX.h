#ifndef ADD_X_H
#define ADD_X_H
class AddX
{
    public:
        explicit AddX(int v); // explicit prevents implicit type conversions by the compiler
        int operator()(int other);

    private:
        int value;
};
#endif