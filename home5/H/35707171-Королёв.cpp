class NotifierBase {
public:
    virtual void Notify(const std::string& message) const {}
    virtual ~NotifierBase() {}
};

class SmsNotifier : public NotifierBase {
private:
    std::string number;
public:
    SmsNotifier(const std::string& number) : number(number) {}
    virtual void Notify(const std::string& message) const {
        SendSms(number, message);
    }
    virtual ~SmsNotifier() {}
};

class EmailNotifier : public NotifierBase {
private:
    std::string email;
public:
    EmailNotifier(const std::string& email) : email(email) {}
    virtual void Notify(const std::string& message) const {
        SendEmail(email, message);
    }
    virtual ~EmailNotifier() {}
};