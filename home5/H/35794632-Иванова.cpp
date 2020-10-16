#include <iostream>
#include <string>

class NotifierBase {
public:
    virtual void Notify(const std::string&) const {}

    virtual ~NotifierBase() {}
};

class SmsNotifier: public NotifierBase {
private:
    std::string number;

public:
    SmsNotifier(std::string number): number(number) {}

    void Notify(const std::string& message) const override {
        SendSms(number, message);
    };
};

class EmailNotifier: public NotifierBase {
private:
    std::string email;

public:
    EmailNotifier(std::string email): email(email) {}

    void Notify(const std::string& message) const override {
        SendEmail(email, message);
    };
};