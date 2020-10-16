#include <string>

class NotifierBase {
protected:
    std::string number;

public:
    NotifierBase(const std::string& number) : number(number) {
    }
    virtual void Notify(const std::string&) const = 0;
};

class SmsNotifier : public NotifierBase {
public:
    SmsNotifier(const std::string& number) : NotifierBase(number) {
    }
    void Notify(const std::string& message) const override {
        SendSms(number, message);
    }
};

class EmailNotifier : public NotifierBase {
public:
    EmailNotifier(const std::string& number) : NotifierBase(number) {
    }
    void Notify(const std::string& message) const override {
        SendEmail(number, message);
    }
};
