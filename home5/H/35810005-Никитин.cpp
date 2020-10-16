class NotifierBase {
protected:
    std::string name;

public:
    NotifierBase(const std::string &_name) : name(_name) {
    }
    virtual void Notify(const std::string &message) const {
    }
};

class SmsNotifier : public NotifierBase {
public:
    SmsNotifier(const std::string &_name) : NotifierBase(_name) {
    }
    void Notify(const std::string &message) const override {
        SendSms(name, message);
    }
};

class EmailNotifier : public NotifierBase {
public:
    EmailNotifier(const std::string &_name) : NotifierBase(_name) {
    }
    void Notify(const std::string &message) const override {
        SendEmail(name, message);
    }
};
