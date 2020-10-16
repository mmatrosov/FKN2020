#include <iostream>
#include <string>

class NotifierBase {
public:
    virtual void Notify(const std::string&) const {
    }
    virtual ~NotifierBase() {
    }
};

class SmsNotifier : public NotifierBase {
private:
    std::string sms;

public:
    SmsNotifier(const std::string& s) : sms(s) {
    }

    void Notify(const std::string& message) const override {
        SendSms(sms, message);
    }
    ~SmsNotifier() override {
    }
};

class EmailNotifier : public NotifierBase {
private:
    std::string email;

public:
    EmailNotifier(const std::string& s) : email(s) {
    }
    void Notify(const std::string& message) const override {
        SendEmail(email, message);
    }
    ~EmailNotifier() override {
    }
};

