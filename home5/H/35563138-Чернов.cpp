#include <string>

class NotifierBase {
protected:
    std::string recipient;

public:
    NotifierBase(const std::string _recipient) : recipient(_recipient) {
    }

    virtual void Notify(const std::string& text) const {
    }
};

class SmsNotifier : public NotifierBase {
public:
    SmsNotifier(const std::string _recipient) : NotifierBase(_recipient) {
    }

    void Notify(const std::string& text) const override {
        SendSms(recipient, text);
    }
};

class EmailNotifier : public NotifierBase {
public:
    EmailNotifier(const std::string _recipient) : NotifierBase(_recipient) {
    }

    void Notify(const std::string& text) const override {
        SendEmail(recipient, text);
    }
};