#include <string>
#include <stack>
#include <iostream>
#include "RegistrationForm.h"

void processRegistration(RegistrationForm form);
void storeRegistrationForm(std::stack<RegistrationForm>& stack, RegistrationForm form);
void endOfDayRegistrationProcessing(std::stack<RegistrationForm>& stack);

int main()
{
    std::stack<RegistrationForm> registerStack;
    RegistrationForm bob {"Bob"};
    RegistrationForm alice {"Alice"};
    RegistrationForm charlie {"Charlie"};
    
    storeRegistrationForm(registerStack, bob);
    storeRegistrationForm(registerStack, alice);
    storeRegistrationForm(registerStack, charlie);

    endOfDayRegistrationProcessing(registerStack);

    return EXIT_SUCCESS;
}
// g++ -I include/ -o main main.cpp

void processRegistration(RegistrationForm form)
{
    std::cout << "Processing form for user: " << form.userName << std::endl;
}

void storeRegistrationForm(std::stack<RegistrationForm>& stack, RegistrationForm form)
{
    stack.push(form);
}

void endOfDayRegistrationProcessing(std::stack<RegistrationForm>& stack)
{
    while (stack.size() != 0)
    {
        RegistrationForm form = stack.top();
        processRegistration(form);
        stack.pop();
    }
}