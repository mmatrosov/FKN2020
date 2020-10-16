class NotifierBase {
protected:
    std::string notifier;
public:
    NotifierBase() : notifier("") {}
    NotifierBase(const std::string& s) : notifier(s) {}
    virtual void Notify(const std::string& message) const {}
};

class SmsNotifier : public NotifierBase {
public:
    SmsNotifier(const std::string& s) {
        notifier = s;
    }
    virtual void Notify(const std::string& message) const {
        SendSms(notifier, message);
    }
};

class EmailNotifier : public NotifierBase {
public:
    EmailNotifier(const std::string& s) {
        notifier = s;
    }
    virtual void Notify(const std::string& message) const {
        SendEmail(notifier, message);
    }
};